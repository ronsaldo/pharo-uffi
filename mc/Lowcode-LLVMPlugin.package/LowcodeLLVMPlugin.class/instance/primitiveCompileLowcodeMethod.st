as yet unclassified
primitiveCompileLowcodeMethod
	<export: true>
	<var: #instructions declareC: 'uint8_t *instructions'>
	| stackFrameSize literalsOop methodOop instructionsOop instructions instructionsSize numberOfTemporals numberOfArguments |
	
	interpreterProxy methodArgumentCount < 1 ifTrue: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].

	"Fetch the arguments"
	methodOop := interpreterProxy stackObjectValue: 0.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"Fetch the method elements"
	literalsOop := interpreterProxy fetchPointer: 0 ofObject: methodOop.
	instructionsOop := interpreterProxy fetchPointer: 1 ofObject: methodOop.
	stackFrameSize := interpreterProxy fetchInteger: 2 ofObject: methodOop.
	numberOfTemporals := interpreterProxy fetchInteger: 3 ofObject: methodOop.
	numberOfArguments := interpreterProxy fetchInteger: 4 ofObject: methodOop.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"Fetch the instructions pointer"
	instructions := self cCoerce: (interpreterProxy firstIndexableField: instructionsOop) to: 'uint8_t*'.
	instructionsSize := interpreterProxy byteSizeOf: instructionsOop.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"TODO: Maybe I should make a copy of the instructions ?"
	
	"Compile the lowcode method"
	^ self LowcodeLLVM_Compile: interpreterProxy Literals: literalsOop Temporals: numberOfTemporals Arguments: numberOfArguments StackFrameSize: stackFrameSize Instructions: instructions InstructionsSize: instructionsSize
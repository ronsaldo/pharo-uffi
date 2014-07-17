primitives
primitiveInterpretLowcodeMethod
	<export: true>
	<var: #instructions declareC: 'uint8_t *instructions'>
	| stackFrameSize literalsOop methodOop receiverOop temporalsOop instructionsOop instructions|
	
	interpreterProxy methodArgumentCount < 2 ifTrue: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].

	"Fetch the arguments"
	methodOop := interpreterProxy stackObjectValue: 2.
	receiverOop := interpreterProxy stackObjectValue: 1.
	temporalsOop := interpreterProxy stackObjectValue: 0.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"Fetch the method elements"
	literalsOop := interpreterProxy fetchPointer: 0 ofObject: methodOop.
	instructionsOop := interpreterProxy fetchPointer: 1 ofObject: methodOop.
	stackFrameSize := interpreterProxy fetchInteger: 2 ofObject: methodOop.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"Fetch the instructions pointer"
	instructions := self cCoerce: (interpreterProxy firstIndexableField: instructionsOop) to: 'uint8_t*'.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"TODO: Maybe I should make a copy of the instructions ?"
	
	"Interpret the instructions"
	^ self LowcodePlugin_Interpret: interpreterProxy Code: instructions Literals: literalsOop Receiver: receiverOop Temporals: temporalsOop StackFrame: stackFrameSize
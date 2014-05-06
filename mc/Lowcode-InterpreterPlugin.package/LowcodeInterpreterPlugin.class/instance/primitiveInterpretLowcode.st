primitives
primitiveInterpretLowcode
	<export: true>
	<var: #instructions declareC: 'uint8_t *instructions'>
	| instructions |
	
	interpreterProxy methodArgumentCount < 1 ifTrue: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].

	"Fetch the instructions pointer"
	instructions := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: interpreterProxy methodArgumentCount - 1)) to: 'uint8_t*'.
	interpreterProxy failed ifTrue: [ self primitiveFail ].
	
	"TODO: Maybe should make a copy of the instructions ?"
	
	"Interpret the instructions"
	^ self LowcodePlugin_Interpret: interpreterProxy Code: instructions In: interpreterProxy primitiveMethod
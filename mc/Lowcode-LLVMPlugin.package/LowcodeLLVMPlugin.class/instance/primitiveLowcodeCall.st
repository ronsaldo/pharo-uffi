as yet unclassified
primitiveLowcodeCall
	<export: true>
	| handleOop |
	
	"Fetch the arguments"
	handleOop := interpreterProxy literal: 1 ofMethod: (interpreterProxy primitiveMethod).
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"Destroy the lowcode method"
	^ self LowcodeLLVM_Call: interpreterProxy CompiledMethod: handleOop
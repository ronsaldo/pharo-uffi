as yet unclassified
primitiveDumpCompiledMethod
	<export: true>
	| handleOop |
	
	"Fetch the arguments"
	handleOop := interpreterProxy stackObjectValue: interpreterProxy methodArgumentCount.
	interpreterProxy failed ifTrue: [ ^ self primitiveFail ].

	"Destroy the lowcode method"
	^ self LowcodeLLVM_Dump: interpreterProxy CompiledMethod: handleOop
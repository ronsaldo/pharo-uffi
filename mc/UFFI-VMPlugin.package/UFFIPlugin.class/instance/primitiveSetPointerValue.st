pointer memory access
primitiveSetPointerValue
	<export: true>
	<var: #ptr declareC: 'uintptr_t *ptr'>
	<var: #intValue declareC: 'uintptr_t intValue'>
	| offset ptr newValue intValue |

	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 1
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	newValue := interpreterProxy stackValue: 0.
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 1)) to: 'uintptr_t*'.
	
	"Read the pointed element."
	(self sizeof: #'void*') = 4
	ifTrue: [
		intValue := interpreterProxy positive32BitValueOf: newValue.
	]
	ifFalse: [ 
		(self sizeof: #'void*') = 8
		ifTrue: [
			intValue := interpreterProxy positive64BitValueOf: newValue.
		]
		ifFalse: [
			^ interpreterProxy primitiveFail.
		]
	].

	"Ensure the arguments were fetched correctly."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].

	"Set the pointer value."
	self cCode: '*ptr = intValue'.
	interpreterProxy pop: 1
	
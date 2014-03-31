pointer memory access
primitiveGetPointerValue
	<export: true>
	<var: #ptr declareC: 'void **ptr'>
	| offset ptr res |

	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 0
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 0)) to: 'void**'.

	"Ensure the arguments were fetched correctly."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].
	
	"Read the pointed element."
	(self sizeof: #'void*') = 4
	ifTrue: [
		res := interpreterProxy positive32BitIntegerFor: (self cCode: '(size_t)*ptr').
	]
	ifFalse: [ 
		(self sizeof: #'void*') = 8
		ifTrue: [
			res := interpreterProxy positive64BitIntegerFor: (self cCode: '(size_t)*ptr').
		]
		ifFalse: [
			^ interpreterProxy primitiveFail.
		]
	].

	interpreterProxy pop: 1 thenPush: res
	
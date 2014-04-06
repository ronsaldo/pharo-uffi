pointer memory access
primitivePointerUInt32AtOffset
	<export: true>
	<var: #ptr declareC: 'uint8_t **ptr'>
	| offset ptr |

	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 1
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	offset := interpreterProxy positive32BitValueOf: (interpreterProxy stackValue: 0).
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 1)) to: 'uint8_t**'.

	"Ensure the arguments were fetched correctly."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].
	
	"Read the pointed element."
	interpreterProxy pop: 2 thenPush: (interpreterProxy positive32BitIntegerFor: (self cCode: '*((uint32_t*)(*ptr + offset))'))
	
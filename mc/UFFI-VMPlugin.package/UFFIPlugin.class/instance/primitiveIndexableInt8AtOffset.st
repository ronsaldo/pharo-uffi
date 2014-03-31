indexable memory access
primitiveIndexableInt8AtOffset
	<export: true>
	<var: #ptr declareC: 'int8_t *ptr'>
	| offset ptr |

	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 1
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	offset := interpreterProxy positive32BitValueOf: (interpreterProxy stackValue: 0).
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 1)) to: 'int8_t*'.

	"Ensure the arguments were fetched correctly."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].
	
	"Read the pointed element."
	interpreterProxy pop: 2 thenPush: (interpreterProxy integerObjectOf: (self cCode: 'ptr[offset]'))
	
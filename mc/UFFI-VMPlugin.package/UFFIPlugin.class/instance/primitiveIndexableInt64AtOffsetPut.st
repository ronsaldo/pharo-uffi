indexable memory access
primitiveIndexableInt64AtOffsetPut
	<export: true>
	<var: #value declareC: 'sqLong value'>
	<var: #ptr declareC: 'uint8_t *ptr'>
	| value offset ptr |
	
	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 2
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	value := interpreterProxy signed64BitValueOf: (interpreterProxy stackValue: 0).
	offset := interpreterProxy positive32BitValueOf: (interpreterProxy stackValue: 1).
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 2)) to: 'uint8_t*'.
	
	"Ensure the arguments were fetched."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].
	
	"Compute the pointer and set the value"
	self cCode: '*((int64_t*)(ptr + offset))= value'.
	interpreterProxy pop: 2.
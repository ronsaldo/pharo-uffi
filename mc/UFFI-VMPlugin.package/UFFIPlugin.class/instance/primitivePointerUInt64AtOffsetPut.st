pointer memory access
primitivePointerUInt64AtOffsetPut
	<export: true>
	<var: #ptr declareC: 'uint8_t **ptr'>
	<var: #value declareC: 'sqLong value'>
	| value offset ptr |
	
	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 2
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	value := interpreterProxy positive64BitValueOf: (interpreterProxy stackValue: 0).
	offset := interpreterProxy positive32BitValueOf: (interpreterProxy stackValue: 1).
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 2)) to: 'uint8_t**'.
	
	"Ensure the arguments were fetched."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].
	
	"Compute the pointer and set the value"
	self cCode: '*((uint64_t*)(*ptr + offset))= value'.
	interpreterProxy pop: 2.
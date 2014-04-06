pointer memory access
primitivePointerInt8AtOffsetPut
	<export: true>
	<var: #ptr declareC: 'int8_t **ptr'>
	| value offset ptr |
	
	"Read the primitive arguments"
	interpreterProxy methodArgumentCount = 2
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	value := interpreterProxy integerValueOf: (interpreterProxy stackValue: 0).
	offset := interpreterProxy positive32BitValueOf: (interpreterProxy stackValue: 1).
	ptr := self cCoerce: (interpreterProxy firstIndexableField: (interpreterProxy stackObjectValue: 2)) to: 'int8_t**'.
	
	"Ensure the arguments were fetched."
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail. ].
	
	"Set the pointed value."
	self cCode: '(*ptr)[offset] = value'.
	interpreterProxy pop: 2.
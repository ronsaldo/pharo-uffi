C type information
primitiveSizeOfLongLong
	<export: true>

	"Return the sizeof short"
	interpreterProxy pop: interpreterProxy methodArgumentCount + 1 thenPush: 
		(interpreterProxy integerObjectOf: (self cCode: 'sizeof(long long)' )).

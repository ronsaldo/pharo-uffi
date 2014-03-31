accessing
primitiveOperatingSystemId
	<export: true>

	"Return an operating system id code"
	interpreterProxy pop: interpreterProxy methodArgumentCount + 1 thenPush: 
		( interpreterProxy integerObjectOf: OperatingSystemId ).
	

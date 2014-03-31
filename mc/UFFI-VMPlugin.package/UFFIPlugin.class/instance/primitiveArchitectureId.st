accessing
primitiveArchitectureId
	<export: true>

	"Return an architecture id code"
	interpreterProxy pop: interpreterProxy methodArgumentCount + 1 thenPush: 
		( interpreterProxy integerObjectOf: ArchitectureId ).
	

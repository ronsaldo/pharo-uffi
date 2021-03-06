method lookup cache
addNewMethodToCache: class
	"Override to refuse to cache other than compiled methods.
	 This protects open PICs against having to test for compiled methods."
	(objectMemory isOopCompiledMethod: newMethod) ifFalse:
		[primitiveFunctionPointer := #primitiveInvokeObjectAsMethod.
		^self].
	super addNewMethodToCache: class
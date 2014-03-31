class initialization
initialize
	"self initialize"
	NativeCodeTrailerId := 	(CompiledMethodTrailer new nativeCode: #() platformId: 0 sourcePointer: 0) kindAsByte.

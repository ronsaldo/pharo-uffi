plugin extra rules
configureLowcodeInterpreterPlugin: maker 
	"extra rules for SoundPlugin"
	maker addCrossSources:
		#( 'LowcodeInterpreterGenerated.c' 'LowcodeInterpreterCommon.c').

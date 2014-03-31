translation
declareHeaderFilesIn: aCCodeGenerator

	({ 
		BSDOSId.
		SolarisOSId.
		LinuxOSId.
		MacOSId.
	} includes: OperatingSystemId  ) ifTrue: [	
	aCCodeGenerator addHeaderFile: '<dlfcn.h>'
	].
	aCCodeGenerator addHeaderFile: '<setjmp.h>';
						addHeaderFile: '<stdint.h>'.

	OperatingSystemId ifNil: [
		self error: 'target operating system id is not set!' ]
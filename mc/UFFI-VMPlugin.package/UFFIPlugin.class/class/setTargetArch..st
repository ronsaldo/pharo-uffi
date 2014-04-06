setting up
setTargetArch: anArchName
	"
	See UFFIConstants for reference.
	
	For example.
	UFFIPlugin setTargetArch: #WindowsArchId
	"
	ArchitectureId := UFFIConstants classPool at: anArchName
as yet unclassified
setTargetOS: anOSName
	"
	See UFFIConstants for reference.
	
	For example.
	UFFIPlugin setTargetOS: #WindowsOSId
	"
	OperatingSystemId := UFFIConstants classPool at: anOSName
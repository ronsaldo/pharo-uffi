testing
isSuitablePluginForPlatform: platName

	ArchitectureId isNil ifTrue: [
		self inform: ' please set the appropriate ArchitectureId, before generating ', self name, ' code.' .
		^ false
		].
	OperatingSystemId isNil ifTrue: [
		self inform: ' please set the appropriate OperatingSystemId, before generating ', self name, ' code.' .
		^ false
		].

	^ true

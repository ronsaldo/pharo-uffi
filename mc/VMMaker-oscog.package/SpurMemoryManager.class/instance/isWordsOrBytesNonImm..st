object testing
isWordsOrBytesNonImm: objOop
	^(self formatOf: objOop) > self lastPointerFormat
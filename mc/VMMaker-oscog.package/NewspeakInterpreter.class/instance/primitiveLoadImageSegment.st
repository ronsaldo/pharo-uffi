image segment in/out
primitiveLoadImageSegment
	"This primitive is called from Squeak as...
		<imageSegment> loadSegmentFrom: aWordArray outPointers: anArray."

"This primitive will load a binary image segment created by primitiveStoreImageSegment.  It expects the outPointer array to be of the proper size, and the wordArray to be well formed.  It will return as its value the original array of roots, and the erstwhile segmentWordArray will have been truncated to a size of zero.  If this primitive should fail, the segmentWordArray will, sadly, have been reduced to an unrecognizable and unusable jumble.  But what more could you have done with it anyway?"

	| outPointerArray segmentWordArray endSeg segOop fieldPtr fieldOop doingClass lastPtr extraSize mapOop lastOut outPtr hdrTypeBits header data |

	DoAssertionChecks ifTrue: [self verifyCleanHeaders].
	outPointerArray := self stackTop.
	lastOut := outPointerArray + (self lastPointerOf: outPointerArray).
	segmentWordArray := self stackValue: 1.
	endSeg := segmentWordArray + (self sizeBitsOf: segmentWordArray) - BaseHeaderSize.

	"Essential type checks"
	((self formatOf: outPointerArray) = 2				"Must be indexable pointers"
		and: [(self formatOf: segmentWordArray) = 6])	"Must be indexable words"
		ifFalse: [^ self primitiveFail].

	"Version check.  Byte order of the WordArray now"
	data := self longAt: segmentWordArray + BaseHeaderSize.
	(self readableFormat: (data bitAnd: 16rFFFF "low 2 bytes")) ifFalse: [
		"Not readable -- try again with reversed bytes..."
		self reverseBytesFrom: segmentWordArray + BaseHeaderSize to: endSeg + BytesPerWord.
		data := self longAt: segmentWordArray + BaseHeaderSize.
		(self readableFormat: (data bitAnd: 16rFFFF "low 2 bytes")) ifFalse: [
			"Still NG -- put things back and fail"
			self reverseBytesFrom: segmentWordArray + BaseHeaderSize to: endSeg + BytesPerWord.
			DoAssertionChecks ifTrue: [self verifyCleanHeaders].
			^ self primitiveFail]].
	"Reverse the Byte type objects if the data from opposite endian machine"
	"Test top byte.  $d on the Mac or $s on the PC.  Rest of word is equal"
	data = self imageSegmentVersion ifFalse: [
		"Reverse the byte-type objects once"
		segOop := self oopFromChunk: segmentWordArray + BaseHeaderSize + BytesPerWord.
			 "Oop of first embedded object"
		self byteSwapByteObjectsFrom: segOop to: endSeg + BytesPerWord].

	"Proceed through the segment, remapping pointers..."
	segOop := self oopFromChunk: segmentWordArray + BaseHeaderSize + BytesPerWord.
	[segOop <= endSeg] whileTrue:
		[(self headerType: segOop) <= 1
			ifTrue: ["This object has a class field (type = 0 or 1) -- start with that."
					fieldPtr := segOop - BytesPerWord.  doingClass := true]
			ifFalse: ["No class field -- start with first data field"
					fieldPtr := segOop + BaseHeaderSize.  doingClass := false].
		lastPtr := segOop + (self lastPointerOf: segOop).	"last field"
		lastPtr > endSeg ifTrue: [
			DoAssertionChecks ifTrue: [self verifyCleanHeaders].
			^ self primitiveFail "out of bounds"].

		"Go through all oops, remapping them..."
		[fieldPtr > lastPtr] whileFalse:
			["Examine each pointer field"
			fieldOop := self longAt: fieldPtr.
			doingClass ifTrue:
				[hdrTypeBits := self headerType: fieldPtr.
				fieldOop := fieldOop - hdrTypeBits].
			(self isIntegerObject: fieldOop)
				ifTrue:
					["Integer -- nothing to do"
					fieldPtr := fieldPtr + BytesPerWord]
				ifFalse:
					[(fieldOop bitAnd: 3) = 0 ifFalse: [^ self primitiveFail "bad oop"].
					(fieldOop bitAnd: 16r80000000) = 0
						ifTrue: ["Internal pointer -- add segment offset"
								mapOop := fieldOop + segmentWordArray]
						ifFalse: ["External pointer -- look it up in outPointers"
								outPtr := outPointerArray + (fieldOop bitAnd: 16r7FFFFFFF).
								outPtr > lastOut ifTrue: [^ self primitiveFail "out of bounds"].
								mapOop := self longAt: outPtr].
					doingClass
						ifTrue: [self longAt: fieldPtr put: mapOop + hdrTypeBits.
								fieldPtr := fieldPtr + 8.
								doingClass := false]
						ifFalse: [self longAt: fieldPtr put: mapOop.
								fieldPtr := fieldPtr + BytesPerWord].
					segOop < youngStart
						ifTrue: [self possibleRootStoreInto: segOop value: mapOop].
					]].
		segOop := self objectAfter: segOop].

	"Again, proceed through the segment checking consistency..."
	segOop := self oopFromChunk: segmentWordArray + BaseHeaderSize + BytesPerWord.
	[segOop <= endSeg] whileTrue:
		[(self oopHasAcceptableClass: segOop) ifFalse: [^ self primitiveFail "inconsistency"].
		fieldPtr := segOop + BaseHeaderSize.		"first field"
		lastPtr := segOop + (self lastPointerOf: segOop).	"last field"
		"Go through all oops, remapping them..."
		[fieldPtr > lastPtr] whileFalse:
			["Examine each pointer field"
			fieldOop := self longAt: fieldPtr.
			(self oopHasAcceptableClass: fieldOop) ifFalse: [^ self primitiveFail "inconsistency"].
			fieldPtr := fieldPtr + BytesPerWord].
		segOop := self objectAfter: segOop].

	"Truncate the segment word array to size = BytesPerWord (vers stamp only)"
	extraSize := self extraHeaderBytes: segmentWordArray.
	hdrTypeBits := self headerType: segmentWordArray.
	extraSize = 8
		ifTrue: [self longAt: segmentWordArray-extraSize put: BaseHeaderSize + BytesPerWord + hdrTypeBits]
		ifFalse: [header := self longAt: segmentWordArray.
				self longAt: segmentWordArray
					put: header - (header bitAnd: SizeMask) + BaseHeaderSize + BytesPerWord].	
	"and return the roots array which was first in the segment"
	DoAssertionChecks ifTrue: [self verifyCleanHeaders].
	self pop: 3 thenPush: (self oopFromChunk: segmentWordArray + BaseHeaderSize + BytesPerWord).

class table
enterIntoClassTable: aBehavior
	"Enter aBehavior into the class table and answer 0.  Otherwise answer a primitive failure code."
	| initialMajorIndex majorIndex minorIndex page |
	majorIndex := classTableIndex >> self classTableMajorIndexShift.
	initialMajorIndex := majorIndex.
	"classTableIndex should never index the first page; it's reserved for known classes"
	self assert: initialMajorIndex > 0.
	minorIndex := classTableIndex bitAnd: self classTableMinorIndexMask.

	[page := self fetchPointer: majorIndex ofObject: classTableRootObj.
	 page = nilObj ifTrue:
		[page := self allocateSlotsInOldSpace: self classTablePageSize
					format: self arrayFormat
					classIndex: self arrayClassIndexPun.
		 page ifNil:
			[^PrimErrNoMemory].
		 self fillObj: page numSlots: self classTablePageSize with: nilObj.
		 self storePointer: majorIndex
			ofObject: classTableRootObj
			withValue: page.
		 minorIndex := 0].
	 minorIndex to: self classTablePageSize - 1 do:
		[:i|
		(self fetchPointer: i ofObject: page) = nilObj ifTrue:
			[classTableIndex := majorIndex << self classTableMajorIndexShift + i.
			 self storePointer: i
				ofObject: page
				withValue: aBehavior.
			 self setHashBitsOf: aBehavior to: classTableIndex.
			 self assert: (self classAtIndex: (self rawHashBitsOf: aBehavior)) = aBehavior.
			 "now fault-in method lookup chain."
			 self scanClassPostBecome: aBehavior
				effects: BecamePointerObjectFlag+BecameCompiledMethodFlag.
			 ^0]].
	 majorIndex := (majorIndex + 1 bitAnd: self classIndexMask) max: 1.
	 majorIndex = initialMajorIndex ifTrue: "wrapped; table full"
		[^PrimErrLimitExceeded]] repeat
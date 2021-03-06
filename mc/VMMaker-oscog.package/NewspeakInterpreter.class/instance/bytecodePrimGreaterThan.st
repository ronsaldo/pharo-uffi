common selector sends
bytecodePrimGreaterThan
	| rcvr arg aBool |
	rcvr := self internalStackValue: 1.
	arg := self internalStackValue: 0.
	(self areIntegers: rcvr and: arg) ifTrue:
		["The C code can avoid detagging since tagged integers are still signed.
		 But this means the simulator must override to do detagging."
		^self cCode: [self booleanCheat: rcvr > arg]
			inSmalltalk: [self booleanCheat: (self integerValueOf: rcvr) > (self integerValueOf: arg)]].

	self initPrimCall.
	aBool := self primitiveFloatGreater: rcvr thanArg: arg.
	self successful ifTrue: [^self booleanCheat: aBool].

	messageSelector := self specialSelector: 3.
	argumentCount := 1.
	self normalSend
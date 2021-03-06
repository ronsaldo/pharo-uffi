method prototypes
ClassBuilderPROTOTYPEformat: nInstVars variable: isVar words: isWords pointers: isPointers weak: isWeak
	"Compute the format for the given instance specfication.
	 Above Cog Spur the class format is
		<5 bits inst spec><16 bits inst size>
	 where the 5-bit inst spec is
		 0 = 0 sized objects (UndefinedObject True False et al)
		 1 = non-indexable objects with inst vars (Point et al)
		 2 = indexable objects with no inst vars (Array et al)
		 3 = indexable objects with inst vars (MethodContext AdditionalMethodState et al)
		 4 = weak indexable objects with inst vars (WeakArray et al)
		 5 = weak non-indexable objects with inst vars (ephemerons) (Ephemeron)
		 6,7,8 unused
		 9 (?) 64-bit indexable
		 10 - 11 32-bit indexable
		 12 - 15 16-bit indexable
		 16 - 23 byte indexable
		 24 - 31 compiled method"
	| instSpec |
	instSpec := isWeak
					ifTrue: [4]
					ifFalse:
						[isPointers
							ifTrue:
								[isVar
									ifTrue: [nInstVars > 0 ifTrue: [3] ifFalse: [2]]
									ifFalse: [nInstVars > 0 ifTrue: [1] ifFalse: [0]]]
							ifFalse: [isWords ifTrue: [12] ifFalse: [16]]].
	^(instSpec bitShift: 16) + nInstVars
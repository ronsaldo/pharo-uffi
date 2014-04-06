pointer memory access
primitiveFree
	<export: true>
	<var: #ptr declareC: 'void **ptr'>
	| handle ptr |

	"Fetch the primitive arguments"
	interpreterProxy methodArgumentCount = 0
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	handle := interpreterProxy stackObjectValue: 0.
	ptr := self cCoerce: (interpreterProxy firstIndexableField: handle) to: 'void**'.
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail  ].

	"Free the pointer and set it to NULL"
	self cCode: 'free(*ptr)'.
	self cCode: '*ptr = NULL'.	
	
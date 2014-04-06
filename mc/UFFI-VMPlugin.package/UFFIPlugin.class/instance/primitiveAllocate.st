pointer memory access
primitiveAllocate
	<export: true>
	<var: #ptr declareC: 'void **ptr'>
	| amount handleClass handle ptr |

	"Fetch the primitive arguments"
	interpreterProxy methodArgumentCount = 1
		ifFalse: [ ^ interpreterProxy primitiveFailFor: PrimErrBadNumArgs ].
	amount := interpreterProxy stackIntegerValue: 0.
	handleClass := interpreterProxy stackObjectValue: 1.
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail  ].
	
	"Instantiate the pointer handler"
	handle := interpreterProxy instantiateClass: handleClass indexableSize: (self sizeof: #'void*').
	interpreterProxy failed ifTrue: [ ^ interpreterProxy primitiveFail  ].
	
	"Set the pointer value"
	ptr := self cCoerce: (interpreterProxy firstIndexableField: handle) to: 'void**'.
	self cCode: '*ptr = malloc(amount)'.

	interpreterProxy pop: 2 thenPush: handle
	
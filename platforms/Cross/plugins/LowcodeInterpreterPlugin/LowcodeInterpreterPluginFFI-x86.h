/* This is the implementation of the FFI part for the LowcodeInterpreterPlugin. */
/* This implementation of the FFI for Lowcode uses GCC facility to bind a variable
   to the stack pointer register. */

#define GET_STACK_POINTER() currentSP
#define SET_STACK_POINTER(x) currentSP = x

#define LOWCODE_FFI_COMMON() \
    uint8_t *storedSP = 0; \
    register uint8_t *currentSP __asm__ ("esp");

#define BEGIN_CALL(alignment) \
    STACK_ALIGN(alignment); \
    storedSP = GET_STACK_POINTER();

#define CALL_ARGUMENT_INT32(value) STACK_PUSH_INT32(value)
#define CALL_ARGUMENT_INT64(value) STACK_PUSH_INT64(value)
#define CALL_ARGUMENT_POINTER(value) STACK_PUSH_POINTER(value)
#define CALL_ARGUMENT_FLOAT32(value) STACK_PUSH_FLOAT32(value)
#define CALL_ARGUMENT_FLOAT64(value) STACK_PUSH_FLOAT64(value)

#define DO_CALL_INT32(function, result) result = ((int32_t (*)()) function) ()
#define DO_CALL_INT64(function, result) result = ((int64_t (*)()) function) ()
#define DO_CALL_POINTER(function, result) result = ((void* (*)()) function) ()
#define DO_CALL_FLOAT32(function, result) result = ((float (*)()) function) ()
#define DO_CALL_FLOAT64(function, result) result = ((double (*)()) function) ()

#define END_CALL() SET_STACK_POINTER(storedSP)
#define END_CALL_NO_CLEANUP() SET_STACK_POINTER(storedSP)


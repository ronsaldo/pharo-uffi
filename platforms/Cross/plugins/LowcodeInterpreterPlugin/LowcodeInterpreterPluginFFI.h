#ifndef _LOWCODE_INTERPRETER_PLUGIN_FFI_H_
#define _LOWCODE_INTERPRETER_PLUGIN_FFI_H_

/* Lowcode interpreter plugin FFI implementation. This is based in the ideas
    used by the ThreadedFFIPlugin */

/* This header must include a platform specific header with implementations for
the following macros:
    GET_STACK_POINTER()
    SET_STACK_POINTER(x)
    LOWCODE_FFI_COMMON();
    BEGIN_CALL(alignment);
    CALL_ARGUMENT_INT32(value);
    CALL_ARGUMENT_INT64(value);
    CALL_ARGUMENT_POINTER(value);
    CALL_ARGUMENT_STRUCTURE(pointer, size);
    CALL_ARGUMENT_FLOAT32(value)
    CALL_ARGUMENT_FLOAT64(value);
    DO_CALL_INT32(function, result);
    DO_CALL_INT64(function, result);
    DO_CALL_POINTER(function, result);
    DO_CALL_FLOAT32(function, result);
    DO_CALL_FLOAT64(function, result);
    DO_CALL_STRUCTURE(function, result, structureSize);
    END_CALL();
    END_CALL_NO_CLEANUP();
*/

/* Alignment utilities */
#define ALIGN_SIZE(x, alignment) (((x + alignment - 1)/alignment)*alignment) /* TODO: Implement this one*/
#define ALIGN_POINTER(x, alignment) x /* TODO: Implement this one*/

/* Shadow stack manipulation macros */
#define STACK_PUSH_OF_TYPE(x, type) { \
    *((type*)(GET_STACK_POINTER() - sizeof(type))) = x; \
    SET_STACK_POINTER(GET_STACK_POINTER() - sizeof(type)); \
}

#define STACK_ALIGN(alignment) \
    SET_STACK_POINTER(ALIGN_POINTER(GET_STACK_POINTER(), alignment))

#define STACK_PUSH_INT32(x) STACK_PUSH_OF_TYPE(x, uint32_t)
#define STACK_PUSH_INT64(x) STACK_PUSH_OF_TYPE(x, uint64_t)
#define STACK_PUSH_POINTER(x) STACK_PUSH_OF_TYPE(x, void*)
#define STACK_PUSH_FLOAT32(x) STACK_PUSH_OF_TYPE(x, float)
#define STACK_PUSH_FLOAT64(x) STACK_PUSH_OF_TYPE(x, double)
#define STACK_PUSH_STRUCTURE(pointer, size, alignment) { \
    SET_STACK_POINTER(GET_STACK_POINTER() - ALIGN_SIZE(size, alignment)); \
    memcpy(GET_STACK_POINTER(), pointer, size); \
}

#if defined(__i386__)
#include "LowcodeInterpreterPluginFFI-x86.h"
#else
#error Unsupported platform for the lowcode interpreter plugin FFI.
#endif

#endif // _LOWCODE_INTERPRETER_PLUGIN_FFI_H_


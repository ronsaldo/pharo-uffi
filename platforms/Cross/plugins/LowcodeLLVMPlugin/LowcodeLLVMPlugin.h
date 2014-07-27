#ifndef _LOWCODE_LLVM_PLUGIN_H_
#define _LOWCODE_LLVM_PLUGIN_H_

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * This function is used to compile a Lowcode method into an LLVM function
    LowcodeLLVM_Compile:Literals:Temporals:StackFrameSize:Instructions:InstructionsSize:
 */
sqInt LowcodeLLVM_CompileLiteralsTemporalsArgumentsStackFrameSizeInstructionsInstructionsSize
    (VirtualMachine *interpreterProxy,
    sqInt literals,
    size_t numberOfTemporals,
    size_t numberOfArguments,
    size_t stackFrameSize,
    const uint8_t *rawInstructions,
    size_t rawInstructionsSize);

#ifdef __cplusplus
}
#endif

#endif //_LOWCODE_LLVM_PLUGIN_H_

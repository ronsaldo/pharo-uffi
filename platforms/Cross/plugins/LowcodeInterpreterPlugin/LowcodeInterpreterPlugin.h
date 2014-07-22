#ifndef _LOWCODE_INTERPRETER_PLUGIN_H_
#define _LOWCODE_INTERPRETER_PLUGIN_H_

#include <stdint.h>
#include "sqVirtualMachine.h"
/**
 * Lowcode interpreter.
 */
sqInt LowcodePlugin_InterpretCodeLiteralsReceiverTemporalsStackFrame(VirtualMachine *interpreterProxy, uint8_t *instructionStream, sqInt literals, sqInt receiver, sqInt temporals, int stackFrameSize);

#endif /*_LOWCODE_INTERPRETER_H_*/


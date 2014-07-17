#ifndef _LOWCODE_INTERPRETER_PLUGIN_H_
#define _LOWCODE_INTERPRETER_PLUGIN_H_

#include <stdint.h>
#include "sqVirtualMachine.h"

#define MAX_REGISTERS 256

/**
 * Lowcode condition flags
 */
typedef struct LowcodeConditionFlags
{
    int equal;
    int lessSigned;
    int lessUnsigned;
} LowcodeConditionFlags;

/* Condition Codes */
#define LOWCODE_COND_EQ 0	/* Equal */
#define LOWCODE_COND_NE 1	/* Not Equal*/
#define LOWCODE_COND_LT 2	/* Signed Less Than */
#define LOWCODE_COND_LE 3	/* Signed Less or Equal*/
#define LOWCODE_COND_GT 4	/* Signed Great Than */
#define LOWCODE_COND_GE 5	/* Signed Great or Equal*/
#define LOWCODE_COND_ULT 6	/* Unsigned Less Than */
#define LOWCODE_COND_ULE 7	/* Unsigned Less Equal */
#define LOWCODE_COND_UGT 8	/* Unsigned Great Than */
#define LOWCODE_COND_UGE 9	/* Unsigned Great Equal */
#define LOWCODE_COND_OV 10	/* Overflow */
#define LOWCODE_COND_NO 11	/* No Overflow */
#define LOWCODE_COND_PF 12	/* Primitive Failed*/
#define LOWCODE_COND_PS 13	/* Primitive Succeed */

/**
 * Lowcode interpreter.
 */
sqInt LowcodePlugin_InterpretCodeLiteralsReceiverTemporalsStackFrame(VirtualMachine *interpreterProxy, uint8_t *instructionStream, sqInt literals, sqInt receiver, sqInt temporals, int stackFrameSize);

/**
 * Sets the condition flags using substraction between integers.
 */
void Lowcode_setConditionFlagsBySubtractingInteger32With(LowcodeConditionFlags *flags, int32_t first, int32_t second);

/**
 * Sets the condition flags using substraction between integers.
 */
void Lowcode_setConditionFlagsBySubtractingInteger64With(LowcodeConditionFlags *flags, int64_t first, int64_t second);

/**
 * Sets the condition flags using subtraction between floats.
 */
void Lowcode_setConditionFlagsBySubtractingFloat32With(LowcodeConditionFlags *flags, float first, float second);

/**
 * Sets the condition flags using subtraction between floats.
 */
void Lowcode_setConditionFlagsBySubtractingFloat64With(LowcodeConditionFlags *flags, double first, double second);

/**
 * Sets the condition flags using a bitwise and.
 */
void Lowcode_setConditionFlagsByAndingInteger64With(LowcodeConditionFlags *flags, int64_t first, int64_t second);

/**
 * Sets the condition flags using a bitwise and.
 */
void Lowcode_setConditionFlagsByAndingInteger32With(LowcodeConditionFlags *flags, int32_t first, int32_t second);

/**
 * Condition codes.
 */
int Lowcode_isConditionSatisfiedByIn(int conditionCode, LowcodeConditionFlags *conditionFlags, VirtualMachine *interpreterProxy);

#endif /*_LOWCODE_INTERPRETER_H_*/


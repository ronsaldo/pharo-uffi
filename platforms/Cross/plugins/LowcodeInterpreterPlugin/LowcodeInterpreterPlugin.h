#ifndef _LOWCODE_INTERPRETER_PLUGIN_H_
#define _LOWCODE_INTERPRETER_PLUGIN_H_

#include <stdint.h>
#include "sqVirtualMachine.h"

#define MAX_REGISTERS 256

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
 * Lowcode Register structure.
 */
typedef union LowcodeIntegerRegister
{
    /* Integer access */
    uint64_t uintValue;
    int64_t intValue;

    /* Fixed size integer access*/
    uint64_t uint64Value;
    int64_t int64Value;
    uint32_t uint32Value;
    int32_t int32Value;
    uint16_t uint16Value;
    int16_t int16Value;
    uint8_t uint8Value;
    int8_t int8Value;

    /* Pointer */
    uint8_t *pointerValue;
    uintptr_t uintPointer;
} LowcodeIntegerRegister;

/**
 * Lowcode condition flags
 */
typedef struct LowcodeConditionFlags
{
    int equal;
	int lessSigned;
	int lessUnsigned;
} LowcodeConditionFlags;

/**
 * Lowcode Float Register.
 */
typedef double LowcodeFloatRegister;

/**
 * Lowcode Oop Register.
 */
typedef sqInt LowcodeOopRegister;

/**
 * Lowcode interpreter.
 */
sqInt LowcodePlugin_InterpretCodeIn(VirtualMachine *interpreterProxy, uint8_t *instructionStream, sqInt currentMethod);

/**
 * Sets the condition flags using substraction between integers.
 */
void Lowcode_setConditionFlagsBySubtractingIntegerWith(LowcodeConditionFlags *flags, int64_t first, int64_t second);

/**
 * Sets the condition flags using subtraction between floats.
 */
void Lowcode_setConditionFlagsBySubtractingFloatWith(LowcodeConditionFlags *flags, double first, double second);

/**
 * Sets the condition flags using a bitwise and.
 */
void Lowcode_setConditionFlagsByAndingIntegerWith(LowcodeConditionFlags *flags, int64_t first, int64_t second);

/**
 * Condition codes.
 */
int Lowcode_isConditionSatisfiedByIn(int conditionCode, LowcodeConditionFlags *conditionFlags, VirtualMachine *interpreterProxy);

#endif /*_LOWCODE_INTERPRETER_H_*/


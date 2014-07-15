#include "LowcodeInterpreterPlugin.h"

/**
 * Sets the condition flags using substraction between integers.
 */
void Lowcode_setConditionFlagsBySubtractingInteger64With(LowcodeConditionFlags *flags, int64_t first, int64_t second)
{
    flags->equal = first == second;
	flags->lessSigned = first < second;
    flags->lessUnsigned = ((uint64_t)first) < ((uint64_t)second);
}

void Lowcode_setConditionFlagsBySubtractingInteger32With(LowcodeConditionFlags *flags, int32_t first, int32_t second)
{
    flags->equal = first == second;
	flags->lessSigned = first < second;
    flags->lessUnsigned = ((uint64_t)first) < ((uint64_t)second);
}

/**
 * Sets the condition flags using subtraction between floats.
 */
void Lowcode_setConditionFlagsBySubtractingFloat64With(LowcodeConditionFlags *flags, double first, double second)
{
    flags->equal = first == second;
	flags->lessSigned = flags->lessUnsigned = first < second;
}

void Lowcode_setConditionFlagsBySubtractingFloat32With(LowcodeConditionFlags *flags, float first, float second)
{
    flags->equal = first == second;
	flags->lessSigned = flags->lessUnsigned = first < second;
}

/**
 * Sets the condition flags using a bitwise and.
 */
void Lowcode_setConditionFlagsByAndingInteger64With(LowcodeConditionFlags *flags, int64_t first, int64_t second)
{
    flags->equal = first == second;
	flags->lessSigned = flags->lessUnsigned = 0;
}

void Lowcode_setConditionFlagsByAndingInteger32With(LowcodeConditionFlags *flags, int32_t first, int32_t second)
{
    flags->equal = first == second;
	flags->lessSigned = flags->lessUnsigned = 0;
}

/**
 * Condition codes.
 */
int Lowcode_isConditionSatisfiedByIn(int conditionCode, LowcodeConditionFlags *conditionFlags, VirtualMachine *interpreterProxy)
{
    switch(conditionCode)
    {
    case LOWCODE_COND_EQ:
        return conditionFlags->equal;
    case LOWCODE_COND_NE:
        return !conditionFlags->equal;
    case LOWCODE_COND_LT:
        return conditionFlags->lessSigned;
    case LOWCODE_COND_LE:
        return conditionFlags->lessSigned || conditionFlags->equal;
    case LOWCODE_COND_GT:
        return !conditionFlags->equal && !conditionFlags->lessSigned;
    case LOWCODE_COND_GE:
        return !conditionFlags->lessSigned;
    case LOWCODE_COND_ULT:
        return conditionFlags->lessUnsigned;
    case LOWCODE_COND_ULE:
        return conditionFlags->lessUnsigned || conditionFlags->equal;
    case LOWCODE_COND_UGT:
        return !conditionFlags->equal && !conditionFlags->lessUnsigned;
    case LOWCODE_COND_UGE:
        return !conditionFlags->lessUnsigned;
    case LOWCODE_COND_OV:
    case LOWCODE_COND_NO:
        return 0; /* TODO Implement the two. */
    case LOWCODE_COND_PF:
        return interpreterProxy->failed();
    case LOWCODE_COND_PS:
        return !interpreterProxy->failed();
    default: /* Uknown*/
        return 0;
    }
}

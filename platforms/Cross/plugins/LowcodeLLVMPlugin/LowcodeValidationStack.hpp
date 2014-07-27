#ifndef _LOWCODE_VALIDATION_STACK_HPP_
#define _LOWCODE_VALIDATION_STACK_HPP_

#include <stdio.h>
#include <string>
#include <vector>

namespace Lowcode
{

namespace OperandType
{
    /**
     * Stack operand type.
     */
    enum Type
    {
        Oop = 'o',
        Int32 = 'i',
        Int64 = 'l',
        Pointer = 'p',
        Float32 = 'f',
        Float64 = 'd'
    };
} // namespace OperandType

/**
 * Lowcode validation stack.
 * This class is used to perform type validation in a Lowcode method.
 */
class LowcodeValidationStack
{
public:
    void pushOop()
    {
        stack.push_back(OperandType::Oop);
    }

    void pushInt32()
    {
        stack.push_back(OperandType::Int32);
    }

    void pushInt64()
    {
        stack.push_back(OperandType::Int64);
    }

    void pushPointer()
    {
        stack.push_back(OperandType::Pointer);
    }

    void pushFloat32()
    {
        stack.push_back(OperandType::Float32);
    }

    void pushFloat64()
    {
        stack.push_back(OperandType::Float64);
    }

    bool popOop()
    {
        return popType(OperandType::Oop);
    }

    bool popInt32()
    {
        return popType(OperandType::Int32);
    }

    bool popInt64()
    {
        return popType(OperandType::Int64);
    }

    bool popPointer()
    {
        return popType(OperandType::Pointer);
    }

    bool popFloat32()
    {
        return popType(OperandType::Float32);
    }

    bool popFloat64()
    {
        return popType(OperandType::Float64);
    }

    std::string typeSignature() const
    {
        return std::string(stack.begin(), stack.end());
    }

private:
    bool popType(OperandType::Type type)
    {
        if(stack.empty())
            return false;

        if(stack.back() != type)
            return false;

        stack.erase(stack.begin() + stack.size() - 1);
        return true;
    }

    std::vector<OperandType::Type> stack;
};

} // namespace Lowcode
#endif //_LOWCODE_VALIDATION_STACK_HPP_


#ifndef _LOWCODE_VALUE_STACK_HPP_
#define _LOWCODE_VALUE_STACK_HPP_

#include <assert.h>
#include "LowcodeValidationStack.hpp"

namespace Lowcode
{

/**
 * This is used for type checking.
 */
llvm::Type *llvmOperandTypeMap(OperandType::Type type);

/**
 * Lowcode value stack.
 * This class is used to generate LLVM SSA from Lowcode
 */
class LowcodeValueStack
{
public:
    void pushOop(llvm::Value* value)
    {
        pushValueTyped(value, OperandType::Oop);
    }

    void pushInt32(llvm::Value* value)
    {
        pushValueTyped(value, OperandType::Int32);
    }

    void pushInt64(llvm::Value* value)
    {
        pushValueTyped(value, OperandType::Int64);
    }

    void pushPointer(llvm::Value* value)
    {
        pushValueTyped(value, OperandType::Pointer);
    }

    void pushFloat32(llvm::Value* value)
    {
        pushValueTyped(value, OperandType::Float32);
    }

    void pushFloat64(llvm::Value* value)
    {
        pushValueTyped(value, OperandType::Float64);
    }

    llvm::Value *popOop()
    {
        return popType(OperandType::Oop);
    }

    llvm::Value *popInt32()
    {
        return popType(OperandType::Int32);
    }

    llvm::Value *popInt64()
    {
        return popType(OperandType::Int64);
    }

    llvm::Value *popPointer()
    {
        return popType(OperandType::Pointer);
    }

    llvm::Value *popFloat32()
    {
        return popType(OperandType::Float32);
    }

    llvm::Value *popFloat64()
    {
        return popType(OperandType::Float64);
    }

    /**
     * This method is used to get the value stack container.
     */
    std::vector<llvm::Value*> &getValues()
    {
        return stack;
    }

private:
    
    void pushValueTyped(llvm::Value *value, OperandType::Type type)
    {
        assert(value->getType() == llvmOperandTypeMap(type));
        stack.push_back(value);
    }

    llvm::Value * popType(OperandType::Type type)
    {
        llvm::Type *llvmType = llvmOperandTypeMap(type);
        assert(!stack.empty());

        llvm::Value *value = stack.back();
        assert(value->getType() == llvmType);

        stack.erase(stack.begin() + stack.size() - 1);
        return value;
    }

    std::vector<llvm::Value*> stack;
};

} // namespace Lowcode
#endif //_LOWCODE_VALIDATION_STACK_HPP_


#include "LowcodeLLVM.hpp"

namespace Lowcode
{

// Those methods are used to make simpler the compilation job.
LlvmInterpreterProxy *Instruction::getLlvmInterpreterProxy()
{
    return ownerBlock->getLowcodeMethod()->getLlvmInterpreterProxy();
}

llvm::Value *Instruction::getTemporalAt(int index)
{
    return ownerBlock->getLowcodeMethod()->getTemporalAt(index);
}

llvm::Value *Instruction::getReceiverOopValue()
{
    return ownerBlock->getLowcodeMethod()->getReceiverOopValue();
}

llvm::Value *Instruction::getTrueOopValue()
{
    return ownerBlock->getLowcodeMethod()->getTrueOopValue();
}

llvm::Value *Instruction::getFalseOopValue()
{
    return ownerBlock->getLowcodeMethod()->getFalseOopValue();
}

llvm::Value *Instruction::getNilOopValue()
{
    return ownerBlock->getLowcodeMethod()->getNilOopValue();
}

llvm::Value *Instruction::getZeroOopValue()
{
    return ownerBlock->getLowcodeMethod()->getZeroOopValue();
}

llvm::Value *Instruction::getOneOopValue()
{
    return ownerBlock->getLowcodeMethod()->getOneOopValue();
}

llvm::Value *Instruction::getLiteralsOopValue()
{
    return ownerBlock->getLowcodeMethod()->getLiteralsOopValue();
}

llvm::Value *Instruction::getLiteralAt(int index)
{
    return ownerBlock->getLowcodeMethod()->getLiteralAt(index);
}

llvm::Value *Instruction::condToInt32(llvm::Value *cond)
{
    return ownerBlock->getLowcodeMethod()->condToInt32(cond);
}

llvm::Value *Instruction::getLocalPointer(uint64_t baseOffset)
{
    return ownerBlock->getLowcodeMethod()->getLocalPointer(baseOffset);
}

llvm::Value *Instruction::getLocalPointerCasted(uint64_t baseOffset, llvm::Type *valueType)
{
    return ownerBlock->getLowcodeMethod()->getLocalPointerCasted(baseOffset, valueType);
}

llvm::Value *Instruction::getMallocFunction()
{
    return LowcodeLLVMContext::get().getMallocFunction();
}

llvm::Value *Instruction::getFreeFunction()
{
    return LowcodeLLVMContext::get().getFreeFunction();
}

void Instruction::beginCall(size_t alignment)
{
    ownerBlock->getLowcodeMethod()->beginCall(alignment);
}

void Instruction::callArgumentInt32(llvm::Value *value)
{
    ownerBlock->getLowcodeMethod()->callArgumentInt32(value);
}

void Instruction::callArgumentInt64(llvm::Value *value)
{
    ownerBlock->getLowcodeMethod()->callArgumentInt64(value);
}

void Instruction::callArgumentPointer(llvm::Value *value)
{
    ownerBlock->getLowcodeMethod()->callArgumentPointer(value);
}

void Instruction::callArgumentFloat32(llvm::Value *value)
{
    ownerBlock->getLowcodeMethod()->callArgumentFloat32(value);
}

void Instruction::callArgumentFloat64(llvm::Value *value)
{
    ownerBlock->getLowcodeMethod()->callArgumentFloat64(value);
}

void Instruction::callArgumentStructure(size_t structureSize, llvm::Value *value)
{
    ownerBlock->getLowcodeMethod()->callArgumentStructure(structureSize, value);
}

llvm::Value *Instruction::performCall(llvm::Type* returnType, uintptr_t functionPointer)
{
    ownerBlock->getLowcodeMethod()->performCall(returnType, functionPointer);
}

llvm::Value *Instruction::performCallIndirect(llvm::Type* returnType, llvm::Value *functionPointer)
{
    ownerBlock->getLowcodeMethod()->performCallIndirect(returnType, functionPointer);
}

void Instruction::endCall()
{
    ownerBlock->getLowcodeMethod()->endCall();
}

void Instruction::endCallNoCleanup()
{
    ownerBlock->getLowcodeMethod()->endCallNoCleanup();
}

void Instruction::returnOop(llvm::Value *oopValue)
{
    return ownerBlock->getLowcodeMethod()->returnOop(oopValue);
}

void Instruction::checkFailed()
{
    return ownerBlock->getLowcodeMethod()->checkFailed();
}

// Pseudo instruction next block
bool PseudoInstructionNextBlock::validate(LowcodeValidationStack &validationStack)
{
    return getJumpBlock()->validate(validationStack);
}

void PseudoInstructionNextBlock::compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder)
{
    builder.CreateBr(getJumpBlock()->getLlvmBasicBlock());
}

} // namespace Lowcode

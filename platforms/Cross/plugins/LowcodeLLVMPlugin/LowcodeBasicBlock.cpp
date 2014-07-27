#include <stdio.h>
#include "LowcodeLLVM.hpp"

namespace Lowcode
{

LowcodeBasicBlock::LowcodeBasicBlock()
{
    lowcodeMethod = NULL;
    isValidating = false;
    isValid = false;
    llvmBasicBlock = NULL;
    compiled = false;
}

LowcodeBasicBlock::~LowcodeBasicBlock()
{
    for(size_t i = 0; i < instructions.size(); ++i)
    delete instructions[i];
}

void LowcodeBasicBlock::addPredecessor(LowcodeBasicBlock *basicBlock)
{
    predecessors.insert(basicBlock);
}

bool LowcodeBasicBlock::validate(LowcodeValidationStack &stack)
{
    std::string newSignature = stack.typeSignature();
    if(isValidating || isValid)
    {
        return entrySignature == newSignature;
    }

    entrySignature = newSignature;
    isValidating = true;

    if(instructions.empty() || !getLastInstruction()->isBranchingOrTerminator())
        return false;

    bool seenBranchingOrTerminator = false;
    for(size_t i = 0; i < instructions.size(); ++i)
    {
        // Only the last instruction can be a branching or a terminator.
        if(seenBranchingOrTerminator)
            return false;

        // Fetch the instruction
        Instruction *instruction = instructions[i];
        if(!instruction->validate(stack))
            return false;

        // If this is a jump or a branch, I have to validate the subsequent blocks.
        seenBranchingOrTerminator = instruction->isBranchingOrTerminator();
        if(instruction->isJump())
        {
            if(!instruction->getJumpBlock()->validate(stack))
                return false;
            instruction->getJumpBlock()->addPredecessor(this);
        }
        else if(instruction->isBranch())
        {
            // Use a different stack for each one of the branches.
            LowcodeValidationStack branchStack = stack;
            LowcodeValidationStack nextStack = stack;

            if(!instruction->getBranchBlock()->validate(branchStack))
                return false;
            if(!instruction->getNextBlock()->validate(nextStack))
                return false;
            instruction->getBranchBlock()->addPredecessor(this);
            instruction->getNextBlock()->addPredecessor(this);
        }
    }

    isValid = true;
    isValidating = false;
    return true;
}

llvm::Function *LowcodeBasicBlock::getLlvmFunction()
{
    return lowcodeMethod->getLlvmFunction();
}

llvm::IRBuilder<> &LowcodeBasicBlock::getIRBuilder()
{
    return lowcodeMethod->getIRBuilder();
}

void LowcodeBasicBlock::createLlvmBasicBlock()
{
    llvmBasicBlock = llvm::BasicBlock::Create(getLowcodeLlvmContext(), "lowcodeBlock", getLlvmFunction());
}

void LowcodeBasicBlock::compileBlock(LowcodeValueStack &prevStack, llvm::BasicBlock *incomingBlock)
{
    // Just add the stack values to the Phi node, If this is already compiled.
    if(compiled)
    {
        compileBlockAddPredecessor(prevStack, incomingBlock);
        return;
    }

    compiled = true;

    // Start compiling  the block.
    llvm::IRBuilder<> &builder = getIRBuilder();
    builder.SetInsertPoint(llvmBasicBlock);

    // Convert the entries into phi nodes, if having multiples predecessors.
    LowcodeValueStack stack = prevStack;
    if(predecessors.size() > 1)
        createStackPhis(stack, incomingBlock);

    // Compile the instructions.
    for(size_t i = 0; i < instructions.size(); ++i)
    {
        Instruction *instruction = instructions[i];

        // Compile the instruction.
        instruction->compile(stack, builder);

        // Trigger sucessors compilation, if this is a branching instruction.
        if(instruction->isJump())
        {
            instruction->getJumpBlock()->compileBlock(stack, llvmBasicBlock);
        }
        else if(instruction->isBranch())
        {
            LowcodeValueStack branchStack = stack;
            LowcodeValueStack nextStack = stack;
            instruction->getBranchBlock()->compileBlock(branchStack, llvmBasicBlock);
            instruction->getNextBlock()->compileBlock(nextStack, llvmBasicBlock);
        }
    }
}

void LowcodeBasicBlock::compileBlockAddPredecessor(LowcodeValueStack &stack, llvm::BasicBlock *incomingBlock)
{
    std::vector<llvm::Value*> stackValues = stack.getValues();
    assert(stackPhis.size() == stackValues.size());

    for(size_t i = 0; i < stackValues.size(); ++i)
    {
        llvm::Value *value = stackValues[i];
        llvm::PHINode *phiNode = stackPhis[i];
        assert(value->getType() == phiNode->getType());
        phiNode->addIncoming(value, incomingBlock);
    }
}

void LowcodeBasicBlock::createStackPhis(LowcodeValueStack &stack, llvm::BasicBlock *incomingBlock)
{
    llvm::IRBuilder<> &builder = getIRBuilder();
    size_t numPredecessors = predecessors.size();

    std::vector<llvm::Value*> &stackValues = stack.getValues();
    stackPhis.reserve(stackValues.size());
    for(size_t i = 0; i < stackValues.size(); ++i)
    {
        llvm::Value *value = stackValues[i];

        llvm::PHINode *phiNode = builder.CreatePHI(value->getType(), numPredecessors);
        phiNode->addIncoming(value, incomingBlock);

        stackValues[i] = phiNode;
        stackPhis.push_back(phiNode);
    }
}

} // namespace Lowcode


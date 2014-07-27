#ifndef _LOWCODE_BASIC_BLOCK_HPP
#define _LOWCODE_BASIC_BLOCK_HPP

#include <vector>
#include <set>

#include "LowcodeInstruction.hpp"

namespace Lowcode
{
class LowcodeMethod;

/**
 * Lowcode Basic Block
 * This class is used to represent a basic block of a lowcode method.
 */
class LowcodeBasicBlock
{
public:
    LowcodeBasicBlock();
    ~LowcodeBasicBlock();

    /**
     * This method adds a new predecessor to the basic block
     */
    void addPredecessor(LowcodeBasicBlock *basicBlock);

    /**
     * This method adds the instruction to the basic block.
     */
    void addInstruction(Instruction* instruction)
    {
        instruction->setOwnerBlock(this);
        instructions.push_back(instruction);
    }

    /**
     * This method gives the last instruction present in this basic block.
     */
    Instruction *getLastInstruction() const
    {
        if(instructions.empty())
            return NULL;
        return instructions.back();
    }

    /**
     * This method sets the lowcode method that owns this basic block.
     */
    void setLowcodeMethod(LowcodeMethod *owner)
    {
        lowcodeMethod = owner;
    }

    /**
     * This method gets the lowcode method that owns this basic block.
     */
    LowcodeMethod *getLowcodeMethod()
    {
        return lowcodeMethod;
    }

    bool validate(LowcodeValidationStack &stack);

    /**
     * This method is used to create the Llvm basic block that represents this block.
     */
    void createLlvmBasicBlock();

    /**
     * This method gets the llvm basic block used for compilation.
     */
    llvm::BasicBlock *getLlvmBasicBlock()
    {
        return llvmBasicBlock;
    }

    /**
     * This method is used to compile the basic block.
     */
    void compileBlock(LowcodeValueStack &stack, llvm::BasicBlock *incomingBlock);

private:

    llvm::Function *getLlvmFunction();
    llvm::IRBuilder<> &getIRBuilder();

    /**
     * This method is used to add another predecessor to the block.
     */
    void compileBlockAddPredecessor(LowcodeValueStack &stack, llvm::BasicBlock *incomingBlock);

    /**
     * This is used to convert the entry values into phi nodes
     */
    void createStackPhis(LowcodeValueStack &stack, llvm::BasicBlock *incomingBlock);

    std::vector<Instruction*> instructions;
    std::set<LowcodeBasicBlock*> predecessors;

    LowcodeMethod *lowcodeMethod;
    bool isValid;
    bool isValidating;
    std::string entrySignature;

    llvm::BasicBlock *llvmBasicBlock;
    bool compiled;
    std::vector<llvm::PHINode*> stackPhis;
};

} // namespace Lowcode

#endif //_LOWCODE_BASIC_BLOCK_HPP

#ifndef _LOWCODE_INSTRUCTION_HPP_
#define _LOWCODE_INSTRUCTION_HPP_

#include <inttypes.h>
#include <stdlib.h>
#include "LowcodeValidationStack.hpp"
#include "LowcodeValueStack.hpp"
#include "sqVirtualMachine.h"

namespace Lowcode
{

class LowcodeBasicBlock;
class LlvmInterpreterProxy;

namespace InstructionKind
{
    /**
     * Lowcode instruction kind
     */
    enum Type
    {
        Operation = 0,
        Branch,
        Jump,
        Terminator,
    };
}

/**
 * Generic decoded instruction.
 */
class Instruction
{
public:
    Instruction(const int opcode, const uint64_t extendA, const uint64_t extendB)
        : opcode(opcode), extendA(extendA), extendB(extendB),
          pc(-1), nextPC(-1), ownerBlock(NULL), jumpBlock(NULL), nextBlock(NULL),
          branchBlock(NULL) {}

    virtual ~Instruction()
    {
        // Nothing to do
    }

    /**
     * This function tells the instruction opcode.
     */
    int getOpcode() const
    {
        return opcode;
    }

    /**
     * This function tells the value of the extension A prefix preceeding the instruction.
     */
    uint64_t getExtendA() const
    {
        return extendA;
    }

    /**
     * This function tells the value of the extension B prefix preceeding the instruction.
     */
    uint64_t getExtendB() const
    {
        return extendB;
    }

    /**
     * This function tells the instruction pc.
     */
    int getPC() const
    {
        return pc;
    }

    /**
     * This functions sets the instruction pc.
     */
    void setPC(const int newPC)
    {
        pc = newPC;
    }

    /**
     * This function tells the next instruction pc.
     */
    int getNextPC() const
    {
        return nextPC;
    }

    /**
     * This functions sets the next instruction pc.
     */
    void setNextPC(const int newNextPC)
    {
        nextPC = newNextPC;
    }

    /**
     * This function tells the owner block of this instruction.
     */
    LowcodeBasicBlock *getOwnerBlock() const
    {
        return ownerBlock;
    }

    /**
     * This function sets the owner block of this instruction.
     */
    void setOwnerBlock(LowcodeBasicBlock *newOwnerBlock)
    {
        ownerBlock = newOwnerBlock;
    }

    /**
     * This function tells the jump block.
     */
    LowcodeBasicBlock *getJumpBlock() const
    {
        return jumpBlock;
    }

    /**
     * This function sets the jump block.
     */
    void setJumpBlock(LowcodeBasicBlock *newJumpBlock)
    {
        jumpBlock = newJumpBlock;
    }

    /**
     * This function tells the next block.
     */
    LowcodeBasicBlock *getNextBlock() const
    {
        return nextBlock;
    }

    /**
     * This function sets the next block.
     */
    void setNextBlock(LowcodeBasicBlock *newNextBlock)
    {
        nextBlock = newNextBlock;
    }

    /**
     * This function tells the branch block.
     */
    LowcodeBasicBlock *getBranchBlock() const
    {
        return branchBlock;
    }

    /**
     * This function sets the branch block.
     */
    void setBranchBlock(LowcodeBasicBlock *newBranchBlock)
    {
        branchBlock = newBranchBlock;
    }
    /**
     * This function tells the instruction kind.
     */
    virtual InstructionKind::Type getKind() const = 0;

    /**
     * This function gives the jump PC.
     */
    virtual int getJumpPC(VirtualMachine *interpreterProxy, sqInt literals) const = 0;

    /**
     * This function gives the branch PC.
     */
    virtual int getBranchPC(VirtualMachine *interpreterProxy, sqInt literals) const = 0;

    /**
     * This function is used to validate the instruction by simulating its operation.
     */
    virtual bool validate(LowcodeValidationStack &validationStack) = 0;

    /**
     * This function tells if this is a jump instruction.
     */
    bool isJump() const
    {
        return getKind() == InstructionKind::Jump;
    }

    /**
     * This function tells if this is a branch instruction.
     */
    bool isBranch() const
    {
        return getKind() == InstructionKind::Branch;
    }

    /**
     * This function tells if this is a terminator instruction.
     */
    bool isTerminator() const
    {
        return getKind() == InstructionKind::Terminator;
    }

    /**
     * This function tells if this is a jump or a branch instruction.
     */
    bool isJumpOrBranch() const
    {
        return isJump() || isBranch();
    }

    /**
     * This function tells if this is a branching or terminator instruction.
     */
    bool isBranchingOrTerminator() const
    {
        return isJumpOrBranch() || isTerminator();
    }

    /**
     * This function tells if this is a sista extended instruction.
     */
    virtual bool isSistaExtendedInstruction() const
    {
        return false;
    }

    /**
     * This function tells if this is a lowcode instruction.
     */
    virtual bool isLowcodeInstruction() const
    {
        return false;
    }

    /**
     * This function tells if this is a pseudo instruction.
     */
    virtual bool isPseudoInstruction() const
    {
        return false;
    }

    /**
     * This method is used to compile the instruction into LLVM IR.
     */
    virtual void compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder) = 0;

protected:
    // Those methods are used to make simpler the compilation job.
    LlvmInterpreterProxy *getLlvmInterpreterProxy();

    llvm::Value *getTemporalAt(int index);
    llvm::Value *getReceiverOopValue();
    llvm::Value *getTrueOopValue();
    llvm::Value *getFalseOopValue();
    llvm::Value *getNilOopValue();
    llvm::Value *getZeroOopValue();
    llvm::Value *getOneOopValue();
    llvm::Value *getLiteralsOopValue();
    llvm::Value *getLiteralAt(int index);

    llvm::Value *condToInt32(llvm::Value *cond);
    llvm::Value *getLocalPointer(uint64_t baseOffset);
    llvm::Value *getLocalPointerCasted(uint64_t baseOffset, llvm::Type *valueType);

    llvm::Value *getMallocFunction();
    llvm::Value *getFreeFunction();

    void beginCall(size_t alignment);
    void callArgumentInt32(llvm::Value *value);
    void callArgumentInt64(llvm::Value *value);
    void callArgumentPointer(llvm::Value *value);
    void callArgumentFloat32(llvm::Value *value);
    void callArgumentFloat64(llvm::Value *value);
    void callArgumentStructure(size_t structureSize, llvm::Value *value);
    llvm::Value *performCall(llvm::Type* returnType, uintptr_t functionPointer);
    llvm::Value *performCallIndirect(llvm::Type* returnType, llvm::Value *functionPointer);

    void endCall();
    void endCallNoCleanup();

    void returnOop(llvm::Value *oopValue);
    void checkFailed();

private:
    int opcode;
    uint64_t extendA;
    uint64_t extendB;

    int pc, nextPC;
    LowcodeBasicBlock *ownerBlock;
    LowcodeBasicBlock *branchBlock, *nextBlock;
    LowcodeBasicBlock *jumpBlock;
};

/**
 * Sista extended byte code instruction.
 * This class is used to represent an instruction that belongs to the sista extended
 * bytecode set.
 */ 
class SistaExtendedInstruction: public Instruction
{
public:
    SistaExtendedInstruction(const int opcode, const uint64_t extendA, const uint64_t extendB,
                             const int firstByte=-1, const int secondByte=-1)
        : Instruction(opcode, extendA, extendB), firstByte(firstByte),
          secondByte(secondByte) {}


    virtual InstructionKind::Type getKind() const; /* override */

    virtual bool validate(LowcodeValidationStack &validationStack);
    virtual void compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder);

    virtual bool isSistaExtendedInstruction() const /* override */
    {
        return true;
    }

    virtual int getJumpPC(VirtualMachine *interpreterProxy, sqInt literals) const /* override */
    {
        abort();
    }

    virtual int getBranchPC(VirtualMachine *interpreterProxy, sqInt literals) const /* override */
    {
        abort();
    }

    /**
     * This function tells the first argument byte of a Sista instruction. If the
     * argument is not present (e.g. one byte instructions) this function returns
     * a negative value.
     */
    int getFirstByte() const
    {
        return firstByte;
    }

    /**
     * This function tells the second argument byte of a Sista instruction. If the
     * argument is not present (e.g. one and two bytes instructions) this function returns
     * a negative value.
     */
    int getSecondByte() const
    {
        return secondByte;
    }

private:
    int firstByte;
    int secondByte;
};

/**
 * Lowcode instruction
 * This class is used to represent a Lowcode instruction or a Sista inlined primitive.
 */
class LowcodeInstruction: public Instruction
{
public:
    LowcodeInstruction(const int opcode, const uint64_t extendA, const uint64_t extendB)
        : Instruction(opcode, extendA, extendB)
    {
    }

    virtual bool validate(LowcodeValidationStack &validationStack);
    virtual void compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder);

    virtual int getJumpPC(VirtualMachine *interpreterProxy, sqInt literals) const /* override */
    {
        // TODO: Validate the index.
        return interpreterProxy->fetchIntegerofObject(getExtendA(), literals);
    }

    virtual int getBranchPC(VirtualMachine *interpreterProxy, sqInt literals) const /* override */
    {
        return getJumpPC(interpreterProxy, literals);
    }

    virtual InstructionKind::Type getKind() const; /* override */

    virtual bool isLowcodeInstruction() const /* override */
    {
        return true;
    }
};

/**
 * Pseudo instruction
 * This class is used to represent pseudo instructions. Pseudo instructions are
 * synthetized to aid in the transformation from stack based code into SSA form.
 */
class PseudoInstruction: public Instruction
{
public:
    PseudoInstruction(const int opcode)
        : Instruction(opcode, -1, -1)
    {
    }

    virtual int getJumpPC(VirtualMachine *interpreterProxy, sqInt literals) const /* override */
    {
        return getNextPC();
    }

    virtual int getBranchPC(VirtualMachine *interpreterProxy, sqInt literals) const /* override */
    {
        return getNextPC();
    }

    virtual bool isPseudoInstruction() const /* override */
    {
        return true;
    }
};

/**
 * Pseudo instruction used to build self contained basic blocks.
 */
class PseudoInstructionNextBlock: public PseudoInstruction
{
public:
    PseudoInstructionNextBlock(LowcodeBasicBlock *jumpBlock)
        : PseudoInstruction(1)
    {
        setJumpBlock(jumpBlock);
    }

    virtual InstructionKind::Type getKind() const
    {
        return InstructionKind::Jump;
    }

    virtual bool validate(LowcodeValidationStack &validationStack);
    virtual void compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder);
};

} // namespace Lowcode

#endif //_LOWCODE_INSTRUCTION_HPP_

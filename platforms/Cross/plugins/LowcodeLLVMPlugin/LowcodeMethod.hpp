#ifndef _LOWCODE_METHOD_HPP_
#define _LOWCODE_METHOD_HPP_

#include <vector>
#include <map>

#include <inttypes.h>
#include "LowcodeBasicBlock.hpp"

namespace Lowcode
{

class LowcodeCompiledMethod;

/**
 * Lowcode method
 * This class is used to hold the decoded information for lowcode method that is
 * required for the Lowcode LLVM backend.
 */
class LowcodeMethod
{
public:
    LowcodeMethod(VirtualMachine *interpreterProxy, sqInt literals,
                size_t numberOfTemporals, size_t numberOfArguments, size_t stackFrameSize);
    ~LowcodeMethod();

    /**
     * This method returns the basic block that is mapped in the requested pc.
     */
    LowcodeBasicBlock *basicBlockAtPC(int pc);

    /**
     * This method validate the well formedness of the instructions used by this method.
     */
    bool validate();

    /**
     * This method is used to compile from Lowcode into the LLVM IR.
     */
    LowcodeCompiledMethod *compile();

    /**
     * The llvm function being compiled.
     */
    llvm::Function *getLlvmFunction();

    /**
     * The current IR builder.
     */
    llvm::IRBuilder<> &getIRBuilder();

    /**
     * This function is used to decode a lowcode method.
     */
    static LowcodeMethod *decodeLowcodeMethod(VirtualMachine *interpreterProxy,
                                    sqInt literals,
                                    size_t numberOfTemporals, size_t numberOfArguments,
                                    size_t stackFrameSize,
                                    const uint8_t *rawInstructions, size_t rawInstructionsSize);

public:
    // Those methods are used to assist in the compilatio task.

    /**
     * Gets the llvm version of the interpreter proxy.
     */
    LlvmInterpreterProxy *getLlvmInterpreterProxy();

    /**
     * Gets the temporal location in the specified index.
     */
    llvm::Value *getTemporalAt(int index);

    /**
     * Gets the literal oop value.
     */
    llvm::Value *getLiteralAt(int index);

    /**
     * Gets the receiver Oop value.
     */
    llvm::Value *getReceiverOopValue();

    /**
     * Gets the true object value.
     */
    llvm::Value *getTrueOopValue();

    /**
     * Gets the false object value.
     */
    llvm::Value *getFalseOopValue();

    /**
     * Gets the nil object value.
     */
    llvm::Value *getNilOopValue();

    /**
     * Gets the zero object value.
     */
    llvm::Value *getZeroOopValue();

    /**
     * Gets the one object value.
     */
    llvm::Value *getOneOopValue();

    /**
     * Gets the one object value.
     */
    llvm::Value *getLiteralsOopValue();

    /**
     * Converts a boolean condition into a int32 boolean value.
     */
    llvm::Value *condToInt32(llvm::Value *cond);

    /**
     * Gets a pointer to a local variable.
     */
    llvm::Value *getLocalPointer(uint64_t baseOffset);

    /**
     * Gets a casted pointer to a local variable.
     */
    llvm::Value *getLocalPointerCasted(uint64_t baseOffset, llvm::Type *valueType);

    /**
     * Returns an Oop.
     */
    void returnOop(llvm::Value *value);

    /**
     * Check for primitive failure.
     */
    void checkFailed();

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


private:
    typedef std::map<int, LowcodeBasicBlock*> PcMapType;

    /**
     * Adds a basic block to the method which maps to the specified pc.
     */
    void addBasicBlock(LowcodeBasicBlock *basicBlock, int pc);

    /**
     * This function gives an unique basic block that maps to the specified pc.
     */
    LowcodeBasicBlock *newBasicBlockFor(int pc);

    /**
     * This method is used to fetch the arguments and allocate temporals
     */
    void compilePrologue();

    /**
     * This method is used to create llvm basic blocks.
     */
    void createLlvmBasicBlocks();

    // Instructions decoding and validation
    VirtualMachine *interpreterProxy;
    sqInt literals;
    size_t numberOfTemporals;
    size_t numberOfArguments;
    size_t stackFrameSize;
    std::vector<LowcodeBasicBlock*> basicBlocks;
    PcMapType pcMap;

    bool isValid;
    bool isValidated;

    // Llvm compilation.
    LowcodeCompiledMethod *compiledMethod;
    llvm::IRBuilder<> builder;

    std::vector<llvm::Value*> temporals;
    llvm::Value *basePointer;
    llvm::BasicBlock *prologueBlock;

    // Interpreter proxy and common objects.
    LlvmInterpreterProxy *llvmInterpreterProxy;
    llvm::Value *receiverOopValue;
    llvm::Value *trueOopValue;
    llvm::Value *falseOopValue;
    llvm::Value *nilOopValue;
    llvm::Value *zeroOopValue;
    llvm::Value *oneOopValue;
    llvm::Value *literalsOopValue;

    // Begin/End call
    bool insideCallBlock;
    std::vector<llvm::Value*> callArguments;
    llvm::CallInst *currentCallInst;
    size_t stackAlignment;
};

/**
 * Lowcode compiled method
 * This class is used as a handle to fully compiled lowcode methods.
 */
class LowcodeCompiledMethod
{
public:
    LowcodeCompiledMethod(VirtualMachine *interpreterProxy, llvm::Function *function, sqInt literals);
    ~LowcodeCompiledMethod();

    /**
     * This method gives the LLVM function.
     */
    llvm::Function *getFunction();

    /**
     * This method gives the literals handle.
     */
    sqInt *getLiteralsPointer();

private:
    VirtualMachine *interpreterProxy;
    llvm::Function *function;
    sqInt literals;
};

}

#endif //_LOWCODE_METHOD_HPP_

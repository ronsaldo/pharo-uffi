#include <stdio.h>
#include "LowcodeLLVM.hpp"

namespace Lowcode
{
LowcodeMethod::LowcodeMethod(VirtualMachine *interpreterProxy, sqInt literals,
                size_t numberOfTemporals, size_t numberOfArguments, size_t stackFrameSize)
    : interpreterProxy(interpreterProxy), literals(literals),
      numberOfTemporals(numberOfTemporals), numberOfArguments(numberOfArguments),
      stackFrameSize(stackFrameSize), isValid(false), isValidated(false),
      builder(getLowcodeLlvmContext())
{
    compiledMethod = NULL;

    llvmInterpreterProxy = NULL;
    receiverOopValue = NULL;
    trueOopValue = NULL;
    falseOopValue = NULL;
    nilOopValue = NULL;
    zeroOopValue = NULL;
    oneOopValue = NULL;
    literalsOopValue = NULL;
    insideCallBlock = false;
}

LowcodeMethod::~LowcodeMethod()
{
    delete llvmInterpreterProxy;
    for(size_t i = 0; i < basicBlocks.size(); ++i)
        delete basicBlocks[i];
}

LowcodeBasicBlock *LowcodeMethod::basicBlockAtPC(int pc)
{
    PcMapType::iterator it = pcMap.find(pc);
    if(it != pcMap.end())
        return it->second;
    return NULL;
}

void LowcodeMethod::addBasicBlock(LowcodeBasicBlock *basicBlock, int pc)
{
    basicBlock->setLowcodeMethod(this);
    basicBlocks.push_back(basicBlock);
    pcMap.insert(std::make_pair(pc, basicBlock));
}

LowcodeBasicBlock *LowcodeMethod::newBasicBlockFor(int pc)
{
    PcMapType::iterator it = pcMap.find(pc);
    if(it != pcMap.end())
        return it->second;

    LowcodeBasicBlock *bb = new LowcodeBasicBlock();
    addBasicBlock(bb, pc);
    return bb;
}

bool LowcodeMethod::validate()
{
    if(isValidated)
        return isValid;

    if(basicBlocks.empty())
        return false;

    LowcodeValidationStack stack;
    isValid = basicBlocks[0]->validate(stack);
    isValidated = true;
    return isValid;
}

LowcodeCompiledMethod *LowcodeMethod::compile()
{
    if(compiledMethod)
        return compiledMethod;

    // Create the llvm interpreter proxy.
    llvmInterpreterProxy = new LlvmInterpreterProxy(interpreterProxy, builder);

    // Get some llvm context data.
    llvm::LLVMContext &context = getLowcodeLlvmContext();
    llvm::Module *module = LowcodeLLVMContext::get().getLlvmModule();
    llvm::FunctionType *functionType = LowcodeLLVMContext::get().getPrimitiveFunctionType();

    // Create the llvm function.
    llvm::Function *function = llvm::Function::Create(functionType,
                                llvm::Function::PrivateLinkage, "LowcodeMethod",
                                module);

    // Create the compiled method object.
    compiledMethod = new LowcodeCompiledMethod(interpreterProxy, function, literals);

    // Compile the prologue.
    compilePrologue();

    // Create the basic blocks.
    createLlvmBasicBlocks();

    // Jump and compile the first basic block
    builder.CreateBr(basicBlocks[0]->getLlvmBasicBlock());
    LowcodeValueStack stack;
    basicBlocks[0]->compileBlock(stack, prologueBlock);

    // Assume generation of valid functions.
    llvm::verifyFunction(*function);

    // Optimize the function.
    LowcodeLLVMContext::get().getFunctionPasses()->run(*function);

    return compiledMethod;
}

llvm::Function *LowcodeMethod::getLlvmFunction()
{
    return compiledMethod->getFunction();
}

llvm::IRBuilder<> &LowcodeMethod::getIRBuilder()
{
    return builder;
}

void LowcodeMethod::compilePrologue()
{
    llvm::LLVMContext &context = getLowcodeLlvmContext();
    prologueBlock = llvm::BasicBlock::Create(context, "entry", getLlvmFunction());
    builder.SetInsertPoint(prologueBlock);

    llvm::Type *oopType = LowcodeLLVMContext::get().getOopType();

    // Allocate space for the temporals.
    for(size_t i = 0; i < numberOfTemporals; ++i)
        temporals.push_back(builder.CreateAlloca(oopType));

    // Allocate space for the stack frame.
    if(stackFrameSize > 0)
    {
        basePointer = builder.CreateAlloca(builder.getInt8Ty(), builder.getInt32(stackFrameSize));
    }
    else
    {
        basePointer = NULL;
    }

    // Fetch the arguments.
    for(size_t i = 0; i < numberOfArguments; ++i)
    {
        llvm::Value *argumentValue = llvmInterpreterProxy->stackValue(numberOfArguments - i - 1);
        builder.CreateStore(argumentValue, temporals[i]);
    }

    // Fetch the receiver.
    receiverOopValue = llvmInterpreterProxy->stackValue(numberOfArguments);

    // Fetch the special objects.
    trueOopValue = llvmInterpreterProxy->trueObject();
    falseOopValue = llvmInterpreterProxy->falseObject();
    nilOopValue = llvmInterpreterProxy->nilObject();
    zeroOopValue = LowcodeLLVMContext::get().getSqIntValue((0<<1) | 1);
    oneOopValue = LowcodeLLVMContext::get().getSqIntValue((1<<1) | 1);

    // Set the remaining temporals to nil.
    for(size_t i = numberOfArguments; i < numberOfTemporals; ++i)
        builder.CreateStore(nilOopValue, temporals[i]);

    // Fetch the literals oop value
    llvm::Type *pointerType = llvm::PointerType::getUnqual(oopType);
    llvm::Type *uintptr = LowcodeLLVMContext::get().getUIntPtrType();
    llvm::Value *literalsPointer = llvm::ConstantExpr::getIntToPtr(
                        llvm::ConstantInt::get(uintptr, (uintptr_t)compiledMethod->getLiteralsPointer()),
                        pointerType);
    literalsOopValue = builder.CreateLoad(literalsPointer);
}

void LowcodeMethod::createLlvmBasicBlocks()
{
    for(size_t i = 0; i < basicBlocks.size(); ++i)
        basicBlocks[i]->createLlvmBasicBlock();
}

LlvmInterpreterProxy *LowcodeMethod::getLlvmInterpreterProxy()
{
    return llvmInterpreterProxy;
}

llvm::Value *LowcodeMethod::getTemporalAt(int index)
{
    assert(index < temporals.size());
    return temporals[index];
}

llvm::Value *LowcodeMethod::getLiteralAt(int index)
{
    return llvmInterpreterProxy->fetchPointerofObject(index, literalsOopValue);
}

llvm::Value *LowcodeMethod::getReceiverOopValue()
{
    return receiverOopValue;
}

llvm::Value *LowcodeMethod::getTrueOopValue()
{
    return trueOopValue;
}

llvm::Value *LowcodeMethod::getFalseOopValue()
{
    return falseOopValue;
}

llvm::Value *LowcodeMethod::getNilOopValue()
{
    return nilOopValue;
}

llvm::Value *LowcodeMethod::getZeroOopValue()
{
    return zeroOopValue;
}

llvm::Value *LowcodeMethod::getOneOopValue()
{
    return oneOopValue;
}

llvm::Value *LowcodeMethod::getLiteralsOopValue()
{
    return literalsOopValue;
}

llvm::Value *LowcodeMethod::condToInt32(llvm::Value *cond)
{
    return builder.CreateSelect(cond, builder.getInt32(1), builder.getInt32(0));
}

llvm::Value *LowcodeMethod::getLocalPointer(uint64_t baseOffset)
{
    return builder.CreateConstGEP1_64(basePointer, baseOffset);
}

llvm::Value *LowcodeMethod::getLocalPointerCasted(uint64_t baseOffset, llvm::Type *valueType)
{
    llvm::Type *pointerType = llvm::PointerType::getUnqual(valueType);
    return builder.CreatePointerCast(getLocalPointer(baseOffset), pointerType);
}

void LowcodeMethod::checkFailed()
{
    llvm::LLVMContext &context = getLowcodeLlvmContext();
    llvm::BasicBlock *failedBlock = llvm::BasicBlock::Create(context, "failed", getLlvmFunction());
    llvm::BasicBlock *notFailedBlock = llvm::BasicBlock::Create(context, "notFailed", getLlvmFunction());

    // Check if the last primitive failed
    llvm::Value *failedRes = llvmInterpreterProxy->failed();
    llvm::Value *sqIntZero = LowcodeLLVMContext::get().getSqIntValue(0);
    llvm::Value *cond = builder.CreateICmpEQ(failedRes, sqIntZero);
    builder.CreateCondBr(cond, notFailedBlock, failedBlock);
    
    // Failure case.
    builder.SetInsertPoint(failedBlock);
    builder.CreateRet(sqIntZero);

    // Non failure
    builder.SetInsertPoint(notFailedBlock);
}

void LowcodeMethod::returnOop(llvm::Value *value)
{
    llvm::Value *res = llvmInterpreterProxy->popthenPush(numberOfArguments + 1, value);
    builder.CreateRet(res);
}

void LowcodeMethod::beginCall(size_t alignment)
{
    assert(!insideCallBlock);
    if(insideCallBlock)
        abort(); // Should never reach here. This should be catched by the validation process

    insideCallBlock = true;
    callArguments.clear();
    stackAlignment = alignment;
}

void LowcodeMethod::callArgumentInt32(llvm::Value *value)
{
    assert(insideCallBlock);
    assert(value->getType() == builder.getInt32Ty());
    callArguments.push_back(value);
}

void LowcodeMethod::callArgumentInt64(llvm::Value *value)
{
    assert(insideCallBlock);
    assert(value->getType() == builder.getInt64Ty());
    callArguments.push_back(value);
}

void LowcodeMethod::callArgumentPointer(llvm::Value *value)
{
    assert(insideCallBlock);
    assert(value->getType() == builder.getInt8PtrTy());
    callArguments.push_back(value);
}

void LowcodeMethod::callArgumentFloat32(llvm::Value *value)
{
    assert(insideCallBlock);
    assert(value->getType() == builder.getFloatTy());
    callArguments.push_back(value);
}

void LowcodeMethod::callArgumentFloat64(llvm::Value *value)
{
    assert(insideCallBlock);
    assert(value->getType() == builder.getDoubleTy());
    callArguments.push_back(value);
}

void LowcodeMethod::callArgumentStructure(size_t structureSize, llvm::Value *value)
{
    assert(insideCallBlock);
    assert(value->getType() == builder.getInt8PtrTy());

    // Get the structure type.
    llvm::Type *content = llvm::ArrayType::get(builder.getInt8Ty(), structureSize);
    llvm::Type *structType = llvm::StructType::get(content, NULL);
    llvm::Type *structPointerType = llvm::PointerType::getUnqual(structType);

    // Cast and load the structure
    llvm::Value *structPointer = builder.CreatePointerCast(value, structPointerType);
    llvm::Value *structure = builder.CreateLoad(structPointer);
    callArguments.push_back(structure);
}

llvm::Value *LowcodeMethod::performCall(llvm::Type* returnType, uintptr_t functionPointer)
{
    // Create the function pointer constant.
    llvm::Type *pointerType = builder.getInt8PtrTy();
    llvm::Type *uintptr = LowcodeLLVMContext::get().getUIntPtrType();
    llvm::Value *functionPointerValue = llvm::ConstantExpr::getIntToPtr(
                        llvm::ConstantInt::get(uintptr, functionPointer),
                        pointerType);

    // Perform the call.
    return performCallIndirect(returnType, functionPointerValue);
}

llvm::Value *LowcodeMethod::performCallIndirect(llvm::Type* returnType, llvm::Value *functionPointer)
{
    // Get the actual arguments in the right order.
    std::vector<llvm::Value*> actualArguments(callArguments.rbegin(), callArguments.rend());

    // Extract the argument types.
    std::vector<llvm::Type*> argumentTypes;
    argumentTypes.reserve(actualArguments.size());
    for(size_t i = 0; i < actualArguments.size(); ++i)
        argumentTypes.push_back(actualArguments[i]->getType());

    // Create the function type.
    llvm::FunctionType *functionType = llvm::FunctionType::get(returnType, argumentTypes, false);
    llvm::Type *functionPointerType = llvm::PointerType::getUnqual(functionType);

    // Cast the function and call it.
    llvm::Value *function = builder.CreatePointerCast(functionPointer, functionPointerType);
    currentCallInst = builder.CreateCall(function, actualArguments);
    return currentCallInst;
}

void LowcodeMethod::endCall()
{
    assert(insideCallBlock);
    assert(currentCallInst);
    insideCallBlock = false;
}

void LowcodeMethod::endCallNoCleanup()
{
    assert(insideCallBlock);
    assert(currentCallInst);
    currentCallInst->setCallingConv(llvm::CallingConv::X86_StdCall);
    insideCallBlock = false;

}

// LowcodeCompiledMethod
LowcodeCompiledMethod::LowcodeCompiledMethod(VirtualMachine *interpreterProxy, llvm::Function *function, sqInt literals)
    : interpreterProxy(interpreterProxy), function(function), literals(literals)
{
    interpreterProxy->addGCRoot(&this->literals);
    compiledFunction = NULL;
}

LowcodeCompiledMethod::~LowcodeCompiledMethod()
{
    interpreterProxy->removeGCRoot(&this->literals);
    function->eraseFromParent();
}

llvm::Function *LowcodeCompiledMethod::getFunction()
{
    return function;
}

sqInt *LowcodeCompiledMethod::getLiteralsPointer()
{
    return &this->literals;
}

sqInt LowcodeCompiledMethod::callPrimitive()
{
    // Ensure the function is compiled.
    if(!compiledFunction)
    {
        llvm::ExecutionEngine *ee = LowcodeLLVMContext::get().getExecutionEngine();
        compiledFunction = ee->getPointerToFunction(function);
    }

    // Cast the primitive function.
    typedef sqInt (*PrimitiveFunction)();
    PrimitiveFunction casted = (PrimitiveFunction)compiledFunction;

    // Call the casted function.
    return casted();
}

/**
 * Lowcode instruction decoder
 */
class LowcodeInstructionDecoder
{
public:
    LowcodeInstructionDecoder(size_t rawInstructionsSize, const uint8_t *rawInstructions)
        : position(0), rawInstructionsSize(rawInstructionsSize), rawInstructions(rawInstructions),
          extendA(0), extendB(0), instructionStart(0)
    {
    }

    bool decodeInstructions();

    std::vector<Instruction*> &getInstructions()
    {
        return instructions;
    }

private:
    void addInstruction(Instruction *instruction);

    int fetchByte();

    bool decodeInstruction();
    bool decodeSistaOneByteInstruction(int opcode);
    bool decodeSistaTwoBytesInstruction(int opcode);
    bool decodeSistaThreeBytesInstruction(int opcode);

    size_t position;
    size_t rawInstructionsSize;
    const uint8_t *rawInstructions;
    uint64_t extendA, extendB;
    size_t instructionStart;
    std::vector<Instruction*> instructions;
};

void LowcodeInstructionDecoder::addInstruction(Instruction *instruction)
{
    if(!instructions.empty())
        instructions.back()->setNextPC(instructionStart);
    instruction->setPC(instructionStart);
    instructions.push_back(instruction);

    extendA = 0;
    extendB = 0;
    instructionStart = position;
}

bool LowcodeInstructionDecoder::decodeInstructions()
{
    while(position < rawInstructionsSize)
    {
        if(!decodeInstruction())
            return false;
    }

    return position == rawInstructionsSize;
}

bool LowcodeInstructionDecoder::decodeInstruction()
{
    int opcode = fetchByte();
    if(opcode < 0)
        return false;

    if(opcode < 224)
        return decodeSistaOneByteInstruction(opcode);
    if(opcode < 248)
        return decodeSistaTwoBytesInstruction(opcode);
    return decodeSistaThreeBytesInstruction(opcode);
}

bool LowcodeInstructionDecoder::decodeSistaOneByteInstruction(int opcode)
{
    addInstruction(new SistaExtendedInstruction(opcode, extendA, extendB));
    return true;
}

bool LowcodeInstructionDecoder::decodeSistaTwoBytesInstruction(int opcode)
{
    int firstByte = fetchByte();
    if(firstByte < 0)
        return false;

    if(opcode == /* Extend A */ 224)
    {
        extendA = extendA * 256 + firstByte;
    }
    else if(opcode == /* Extend B */ 225)
    {
        extendB = extendB * 256 + firstByte;
    }
    else
    {
        addInstruction(new SistaExtendedInstruction(opcode, extendA, extendB, firstByte));
    }

    return true;
}

bool LowcodeInstructionDecoder::decodeSistaThreeBytesInstruction(int opcode)
{
    int firstByte = fetchByte();
    int secondByte = fetchByte();
    if(firstByte < 0 || secondByte < 0)
        return false;

    if(opcode == 248 && (secondByte & (1<<7)))
    {
        secondByte &= ~(1<<7);
        addInstruction(new LowcodeInstruction(firstByte + secondByte*256, extendA, extendB));
    }
    else
    {
        addInstruction(new SistaExtendedInstruction(opcode, extendA, extendB, firstByte, secondByte));
    }

    return true;
}

int LowcodeInstructionDecoder::fetchByte()
{
    if(position >= rawInstructionsSize)
        return -1;
    return rawInstructions[position++];
}

typedef std::map<int, Instruction*> PcInstructionMap;

inline bool isValidInstructionPC(PcInstructionMap &pcMap, int pc)
{
    return pcMap.find(pc) != pcMap.end();
}

LowcodeMethod *LowcodeMethod::decodeLowcodeMethod(VirtualMachine *interpreterProxy,
                                    sqInt literals,
                                    size_t numberOfTemporals, size_t numberOfArguments,
                                    size_t stackFrameSize,
                                    const uint8_t *rawInstructions, size_t rawInstructionsSize)
{
    // Decode the instructions.
    LowcodeInstructionDecoder decoder(rawInstructionsSize, rawInstructions);
    if(!decoder.decodeInstructions())
    {
        fprintf(stderr, "Failed to decode lowcode method instructions\n");
        return NULL;
    }

    std::vector<Instruction*> &allInstructions = decoder.getInstructions();

    // Create the method.
    LowcodeMethod *result = new LowcodeMethod(interpreterProxy, literals,
                                              numberOfTemporals, numberOfArguments,
                                              stackFrameSize);

    // Build the pc -> instruction map.
    PcInstructionMap pcInstructionMap;
    for(size_t i = 0; i < allInstructions.size(); ++i)
    {
        Instruction *instruction = allInstructions[i];
        pcInstructionMap[instruction->getPC()] = instruction;
    }

    // Build the pc -> basic block map.
    allInstructions[0]->setOwnerBlock(result->newBasicBlockFor(0));
    bool invalid = false;
    for(size_t i = 0; i < allInstructions.size(); ++i)
    {
        Instruction *instruction = allInstructions[i];
        if(instruction->isJump())
        {
            int jumpPC = instruction->getJumpPC(interpreterProxy, literals);
            if(!isValidInstructionPC(pcInstructionMap, jumpPC))
            {
                invalid = true;
                break;
            }

            // Set the jump instruction links.
            Instruction *jumpInstruction = pcInstructionMap[jumpPC];
            jumpInstruction->setOwnerBlock(result->newBasicBlockFor(jumpPC));
            instruction->setJumpBlock(jumpInstruction->getOwnerBlock());
        }
        else if(instruction->isBranch())
        {
            int branchPC = instruction->getBranchPC(interpreterProxy, literals);
            int nextPC = instruction->getNextPC();
            if(!isValidInstructionPC(pcInstructionMap, branchPC) || !isValidInstructionPC(pcInstructionMap, nextPC))
            {
                invalid = true;
                break;
            }

            // Set the branch instruction links.
            Instruction *branchInstruction = pcInstructionMap[branchPC];
            branchInstruction->setOwnerBlock(result->newBasicBlockFor(branchPC));
            instruction->setBranchBlock(branchInstruction->getOwnerBlock());

            // Set the next instruction links.
            Instruction *nextInstruction = pcInstructionMap[nextPC];
            nextInstruction->setOwnerBlock(result->newBasicBlockFor(nextPC));
            instruction->setNextBlock(nextInstruction->getOwnerBlock());
        }
    }    

    // Delete if invalid.
    if(invalid)
    {
        delete result;
        for(size_t i = 0; i < allInstructions.size(); ++i)
            delete allInstructions[i];
        fprintf(stderr, "Invalid lowcode method branch or jump address.\n");
        return NULL;
    }

    // Put the instructions in their basic blocks
    LowcodeBasicBlock *currentBlock = NULL;
    for(size_t i = 0; i < allInstructions.size(); ++i)
    {
        Instruction *instruction = allInstructions[i];
        LowcodeBasicBlock *newBlock = instruction->getOwnerBlock();
        if(newBlock != NULL)
        {
            if(currentBlock != NULL && newBlock != currentBlock &&
               !currentBlock->getLastInstruction()->isBranchingOrTerminator())
            {
                currentBlock->addInstruction(new PseudoInstructionNextBlock(newBlock));
            }

            currentBlock = newBlock;
        }

        currentBlock->addInstruction(instruction);
    }

    if(!result->validate())
    {
        delete result;
        fprintf(stderr, "Failed to validate Lowcode method instructions\n");
        return NULL;
    }

    return result;
}

} // namespace Lowcode


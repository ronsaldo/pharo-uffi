#include <stdio.h>
#include <time.h>
#include "LowcodeLLVM.hpp"
#include "LowcodeLLVMPlugin.h"

namespace Lowcode
{
LowcodeLLVMContext *LowcodeLLVMContext::uniqueInstance = NULL;

LowcodeLLVMContext::LowcodeLLVMContext()
    : llvmContext(llvm::getGlobalContext())
{
    llvmModule = new llvm::Module("Lowcode", llvmContext);

    createExecutionEngine();
    initializeFunctionPasses();
    createTypes();
    createCommonFunctions();

    // Try to grab some entropy
    sessionIdentifier ^= ((uint32_t)(size_t)llvmModule) ^ time(NULL);
}

LowcodeLLVMContext::~LowcodeLLVMContext()
{
}

LowcodeLLVMContext &LowcodeLLVMContext::get()
{
    if(!uniqueInstance)
        uniqueInstance = new LowcodeLLVMContext();
    return *uniqueInstance;
}

void LowcodeLLVMContext::createExecutionEngine()
{
    llvm::InitializeNativeTarget();

    std::string errStr;
    executionEngine = llvm::EngineBuilder(llvmModule).setErrorStr(&errStr).create();
    if (!executionEngine) {
        fprintf(stderr, "Could not create ExecutionEngine: %s\n", errStr.c_str());
        exit(1);
    } 
}

void LowcodeLLVMContext::initializeFunctionPasses()
{
    functionPasses = new llvm::FunctionPassManager(llvmModule);

    // Set up the optimizer pipeline.  Start with registering info about how the
    // target lays out data structures.
    functionPasses->add(new llvm::DataLayout(*executionEngine->getDataLayout()));
    // Provide basic AliasAnalysis support for GVN.
    functionPasses->add(llvm::createBasicAliasAnalysisPass());
    // Do simple "peephole" optimizations and bit-twiddling optzns.
    functionPasses->add(llvm::createInstructionCombiningPass());
    // Reassociate expressions.
    functionPasses->add(llvm::createReassociatePass());
    // Eliminate Common SubExpressions.
    functionPasses->add(llvm::createGVNPass());
    // Simplify the control flow graph (deleting unreachable blocks, etc).
    functionPasses->add(llvm::createCFGSimplificationPass());

    functionPasses->doInitialization();
}

void LowcodeLLVMContext::createCommonFunctions()
{
    // Malloc
    {
        llvm::Type *args = { sizeType };
        llvm::FunctionType *functionType = llvm::FunctionType::get(pointerType, args, false);
        mallocFunction = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, "malloc", llvmModule);
    }

    // Free
    {
        llvm::Type *voidType = llvm::Type::getVoidTy(llvmContext);
        llvm::Type *args = { pointerType };
        llvm::FunctionType *functionType = llvm::FunctionType::get(voidType, args, false);
        freeFunction = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, "free", llvmModule);
    }
    
}

void LowcodeLLVMContext::createTypes()
{
    sqIntType = llvm::IntegerType::get(llvmContext, sizeof(sqInt)*8);
    sizeType = llvm::IntegerType::get(llvmContext, sizeof(size_t)*8);
    oopType = sqIntType;
    int32Type = llvm::Type::getInt32Ty(llvmContext);
    int64Type = llvm::Type::getInt64Ty(llvmContext);
    float32Type = llvm::Type::getFloatTy(llvmContext);
    float64Type = llvm::Type::getDoubleTy(llvmContext);
    pointerType = llvm::Type::getInt8PtrTy(llvmContext);
    uintptrType = llvm::IntegerType::get(llvmContext, sizeof(uintptr_t)*8);
    primitiveFunctionType = llvm::FunctionType::get(sqIntType, false);
}

llvm::LLVMContext &LowcodeLLVMContext::getLlvmContext()
{
    return llvmContext;
}

llvm::Module *LowcodeLLVMContext::getLlvmModule()
{
    return llvmModule;
}

llvm::ExecutionEngine *LowcodeLLVMContext::getExecutionEngine()
{
    return executionEngine;
}

llvm::FunctionPassManager *LowcodeLLVMContext::getFunctionPasses()
{
    return functionPasses;
}

llvm::Type *LowcodeLLVMContext::getSqIntType()
{
    return sqIntType;
}

llvm::Type *LowcodeLLVMContext::getInt32Type()
{
    return int32Type;
}

llvm::Type *LowcodeLLVMContext::getInt64Type()
{
    return int64Type;
}

llvm::Type *LowcodeLLVMContext::getOopType()
{
    return oopType;
}

llvm::Type *LowcodeLLVMContext::getFloat32Type()
{
    return float32Type;
}

llvm::Type *LowcodeLLVMContext::getFloat64Type()
{
    return float64Type;
}

llvm::Type *LowcodeLLVMContext::getPointerType()
{
    return pointerType;
}

llvm::Type *LowcodeLLVMContext::getUIntPtrType()
{
    return uintptrType;
}

llvm::Type *LowcodeLLVMContext::getSizeType()
{
    return sizeType;
}

llvm::FunctionType *LowcodeLLVMContext::getPrimitiveFunctionType()
{
    return primitiveFunctionType;
}

llvm::Value *LowcodeLLVMContext::getSqIntValue(sqInt val)
{
    return llvm::ConstantInt::get(sqIntType, val);
}

uint32_t LowcodeLLVMContext::getSessionIdentifier() const
{
    return sessionIdentifier;
}

llvm::Function *LowcodeLLVMContext::getMallocFunction()
{
    return mallocFunction;
}

llvm::Function *LowcodeLLVMContext::getFreeFunction()
{
    return freeFunction;
}

llvm::Type *llvmOperandTypeMap(OperandType::Type type)
{
    switch(type)
    {
    case OperandType::Oop:
        return LowcodeLLVMContext::get().getOopType();
    case OperandType::Int32:
        return LowcodeLLVMContext::get().getInt32Type();
    case OperandType::Int64:
        return LowcodeLLVMContext::get().getInt64Type();
    case OperandType::Pointer:
        return LowcodeLLVMContext::get().getPointerType();
    case OperandType::Float32:
        return LowcodeLLVMContext::get().getFloat32Type();
    case OperandType::Float64:
        return LowcodeLLVMContext::get().getFloat64Type();
    default:
        abort();
    }
}

}

using namespace Lowcode;
extern "C" sqInt LowcodeLLVM_CompileLiteralsTemporalsArgumentsStackFrameSizeInstructionsInstructionsSize
    (VirtualMachine *interpreterProxy,
    sqInt literals,
    size_t numberOfTemporals,
    size_t numberOfArguments,
    size_t stackFrameSize,
    const uint8_t *rawInstructions,
    size_t rawInstructionsSize)
{

    // Decode the Lowcode method.
    LowcodeMethod *method = LowcodeMethod::decodeLowcodeMethod(interpreterProxy, literals,
                            numberOfTemporals, numberOfArguments, stackFrameSize,
                            rawInstructions, rawInstructionsSize);
    if(!method)
        return interpreterProxy->primitiveFail();

    // Compile the lowcode method.
    LowcodeCompiledMethod *compiledMethod = method->compile();
    delete method;

    // Make sure the compilation was a success.
    if(!compiledMethod)
        return interpreterProxy->primitiveFail();

    // Dump the compiled method function.
    compiledMethod->getFunction()->dump();

    // Return the compiled method handle.
    sqInt compiledMethodHandle;
    if(sizeof(void*) == 4)
        compiledMethodHandle = interpreterProxy->positive32BitIntegerFor((uintptr_t)compiledMethod);
    else if(sizeof(void*) == 8)
        compiledMethodHandle = interpreterProxy->positive64BitIntegerFor((uintptr_t)compiledMethod);
    if(interpreterProxy->failed()) // Very Bad luck in this moment.
        return 0;

    return interpreterProxy->popthenPush(interpreterProxy->methodArgumentCount() + 1, compiledMethodHandle);
}


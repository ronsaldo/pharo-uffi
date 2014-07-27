#ifndef _LOWCODE_LLVM_HPP_
#define _LOWCODE_LLVM_HPP_

#include <assert.h>
#include "llvm/Analysis/Passes.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/JIT.h" 
#include "llvm/DerivedTypes.h"
#include "llvm/IRBuilder.h"
#include "llvm/LLVMContext.h"
#include "llvm/Module.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Scalar.h"

#include "LowcodeMethod.hpp"
#include "LowcodeLLVMInterpreterProxy.hpp"

namespace Lowcode
{

/**
 * Lowcode LLVM context
 * This is used as a context for the Lowcode llvm related generation.
 */
class LowcodeLLVMContext
{
private:
    LowcodeLLVMContext();
    ~LowcodeLLVMContext();

    static LowcodeLLVMContext *uniqueInstance;
public:

    static LowcodeLLVMContext &get();

    llvm::LLVMContext &getLlvmContext();
    llvm::Module *getLlvmModule();
    llvm::ExecutionEngine *getExecutionEngine();
    llvm::FunctionPassManager *getFunctionPasses();

    llvm::Type *getSqIntType();
    llvm::Type *getInt32Type();
    llvm::Type *getInt64Type();
    llvm::Type *getOopType();
    llvm::Type *getFloat32Type();
    llvm::Type *getFloat64Type();
    llvm::Type *getPointerType();
    llvm::Type *getUIntPtrType();
    llvm::Type *getSizeType();

    llvm::FunctionType *getPrimitiveFunctionType();

    llvm::Value *getSqIntValue(sqInt val);

    llvm::Function *getMallocFunction();
    llvm::Function *getFreeFunction();

    uint32_t getSessionIdentifier() const;

private:
    void createExecutionEngine();
    void initializeFunctionPasses();
    void createTypes();
    void createCommonFunctions();

    llvm::LLVMContext &llvmContext;
    llvm::Module *llvmModule;
    llvm::ExecutionEngine *executionEngine;
    llvm::FunctionPassManager *functionPasses;

    llvm::Type *sqIntType;
    llvm::Type *int32Type;
    llvm::Type *int64Type;
    llvm::Type *oopType;
    llvm::Type *float32Type;
    llvm::Type *float64Type;
    llvm::Type *pointerType;
    llvm::Type *uintptrType;
    llvm::Type *sizeType;
    llvm::FunctionType *primitiveFunctionType;

    llvm::Function *mallocFunction;
    llvm::Function *freeFunction;

    uint32_t sessionIdentifier;
};

inline llvm::LLVMContext &getLowcodeLlvmContext()
{
    return LowcodeLLVMContext::get().getLlvmContext();
}

} // namespace Lowcode

#endif // _LOWCOW_LLVM_HPP_


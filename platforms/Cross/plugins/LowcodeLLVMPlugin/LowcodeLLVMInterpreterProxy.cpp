#include "LowcodeLLVM.hpp"

namespace Lowcode
{

LlvmInterpreterProxy::LlvmInterpreterProxy(VirtualMachine *interpreterProxy, llvm::IRBuilder<> &builder)
    : interpreterProxy(interpreterProxy), builder(builder)
{
    sqIntType = LowcodeLLVMContext::get().getSqIntType();
    uintPtrType = LowcodeLLVMContext::get().getUIntPtrType();
    longType = LowcodeLLVMContext::get().getInt64Type();
    doubleType = LowcodeLLVMContext::get().getFloat64Type();
    pointerType = LowcodeLLVMContext::get().getPointerType();

    createFunctionTypes();
}

LlvmInterpreterProxy::~LlvmInterpreterProxy()
{
}

void LlvmInterpreterProxy::createFunctionTypes()
{
    // Void -> sqInt
    {
        functionTypeVoidToOop = llvm::FunctionType::get(sqIntType, false);
    }

    // sqInt -> sqInt
    {
        llvm::Type *argTypes[] = {
            sqIntType
        };

        functionTypeOopToOop = llvm::FunctionType::get(sqIntType, argTypes, false);
    }

    // sqInt sqInt -> sqInt
    {
        llvm::Type *argTypes[] = {
            sqIntType,
            sqIntType,
        };

        functionTypeOopOopToOop = llvm::FunctionType::get(sqIntType, argTypes, false);
    }

    // sqInt sqInt sqInt -> sqInt
    {
        llvm::Type *argTypes[] = {
            sqIntType,
            sqIntType,
            sqIntType,
        };

        functionTypeOopOopOopToOop = llvm::FunctionType::get(sqIntType, argTypes, false);
    }

    // sqInt -> Pointer
    {
        llvm::Type *argTypes[] = {
            sqIntType,
        };

        functionTypeOopToPtr = llvm::FunctionType::get(pointerType, argTypes, false);
    }

    // Double -> sqInt
    {
        llvm::Type *argTypes[] = {
            doubleType
        };

        functionTypeDoubleToOop = llvm::FunctionType::get(sqIntType, argTypes, false);
    }

    // sqInt -> Double
    {
        llvm::Type *argTypes[] = {
            sqIntType
        };

        functionTypeOopToDouble = llvm::FunctionType::get(doubleType, argTypes, false);
    }

    // long -> sqInt
    {
        llvm::Type *argTypes[] = {
            longType
        };

        functionTypeLongToOop = llvm::FunctionType::get(sqIntType, argTypes, false);
    }

    // sqInt -> long
    {
        llvm::Type *argTypes[] = {
            sqIntType
        };

        functionTypeOopToLong = llvm::FunctionType::get(longType, argTypes, false);
    }

}

// Stack manipulation
llvm::Value *LlvmInterpreterProxy::popthenPush(llvm::Value *nItems, llvm::Value * oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopOopToOop,
                            (void*)interpreterProxy->popthenPush, "popthenPush");
    return builder.CreateCall2(function, nItems, oop, "popthenPush");
}

llvm::Value *LlvmInterpreterProxy::popthenPush(int nItems, llvm::Value * oop)
{
    return popthenPush(intAsSqIntValue(nItems), oop);
}

llvm::Value *LlvmInterpreterProxy::stackValue(llvm::Value *offset)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->stackValue, "stackValue");
    return builder.CreateCall(function, offset, "stackValue");
}

llvm::Value *LlvmInterpreterProxy::stackValue(int offset)
{
    return stackValue(intAsSqIntValue(offset));
}

// Object accesssing
llvm::Value *LlvmInterpreterProxy::byteSizeOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->byteSizeOf, "byteSizeOf");
    return builder.CreateCall(function, oop, "byteSizeOf");
}

llvm::Value *LlvmInterpreterProxy::fetchPointerofObject(llvm::Value *fieldIndex, llvm::Value *oopValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopOopToOop, (void*)interpreterProxy->fetchPointerofObject, "fetchPointerofObject");
    return builder.CreateCall2(function, fieldIndex, oopValue, "fetchPointerofObject");
}

llvm::Value *LlvmInterpreterProxy::fetchPointerofObject(int fieldIndex, llvm::Value *oopValue)
{
    return fetchPointerofObject(intAsSqIntValue(fieldIndex), oopValue);
}

llvm::Value *LlvmInterpreterProxy::fetchClassOf(llvm::Value *oopValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->fetchClassOf, "fetchClassOf");
    return builder.CreateCall(function, oopValue, "fetchClassOf");
}

llvm::Value *LlvmInterpreterProxy::firstIndexableField(llvm::Value *oopValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToPtr, (void*)interpreterProxy->firstIndexableField, "firstIndexableField");
    return builder.CreateCall(function, oopValue, "firstIndexableField");
}

llvm::Value *LlvmInterpreterProxy::firstFixedField(llvm::Value *oopValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToPtr, (void*)interpreterProxy->firstFixedField, "firstFixedField");
    return builder.CreateCall(function, oopValue, "firstFixedField");
}

llvm::Value *LlvmInterpreterProxy::storePointerofObjectwithValue(llvm::Value *fieldIndex, llvm::Value *oop, llvm::Value *valuePointer)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopOopOopToOop, (void*)interpreterProxy->storePointerofObjectwithValue, "storePointerofObjectwithValue");
    return builder.CreateCall3(function, fieldIndex, oop, valuePointer, "storePointerofObjectwithValue");
}

llvm::Value *LlvmInterpreterProxy::storePointerofObjectwithValue(int fieldIndex, llvm::Value *oop, llvm::Value *valuePointer)
{
    return storePointerofObjectwithValue(intAsSqIntValue(fieldIndex), oop, valuePointer);
}

// Testing methods
llvm::Value *LlvmInterpreterProxy::isBytes(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isBytes, "isBytes");
    return builder.CreateCall(function, oop, "isBytes");
}

llvm::Value *LlvmInterpreterProxy::isFloatObject(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isFloatObject, "isFloatObject");
    return builder.CreateCall(function, oop, "isFloatObject");
}

llvm::Value *LlvmInterpreterProxy::isIndexable(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isIndexable, "isIndexable");
    return builder.CreateCall(function, oop, "isIndexable");
}

llvm::Value *LlvmInterpreterProxy::isIntegerObject(llvm::Value *objectPointer)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isIntegerObject, "isIntegerObject");
    return builder.CreateCall(function, objectPointer, "isIntegerObject");
}

llvm::Value *LlvmInterpreterProxy::isIntegerValue(llvm::Value *intValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isIntegerValue, "isIntegerValue");
    return builder.CreateCall(function, intValue, "isIntegerValue");
}

llvm::Value *LlvmInterpreterProxy::isPointers(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isPointers, "isPointers");
    return builder.CreateCall(function, oop, "isPointers");
}

llvm::Value *LlvmInterpreterProxy::isWeak(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isWeak, "isWeak");
    return builder.CreateCall(function, oop, "isWeak");
}

llvm::Value *LlvmInterpreterProxy::isWords(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isWords, "isWords");
    return builder.CreateCall(function, oop, "isWords");
}

llvm::Value *LlvmInterpreterProxy::isWordsOrBytes(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->isWordsOrBytes, "isWordsOrBytes");
    return builder.CreateCall(function, oop, "isWordsOrBytes");
}

// Special objects
llvm::Value *LlvmInterpreterProxy::falseObject()
{
    llvm::Value *function = getFunctionConstant(functionTypeVoidToOop, (void*)interpreterProxy->falseObject, "falseObject");
    return builder.CreateCall(function, "falseObject");
}

llvm::Value *LlvmInterpreterProxy::nilObject()
{
    llvm::Value *function = getFunctionConstant(functionTypeVoidToOop, (void*)interpreterProxy->nilObject, "nilObject");
    return builder.CreateCall(function, "nilObject");
}

llvm::Value *LlvmInterpreterProxy::trueObject()
{
    llvm::Value *function = getFunctionConstant(functionTypeVoidToOop, (void*)interpreterProxy->trueObject, "trueObject");
    return builder.CreateCall(function, "trueObject");
}

// Instance creation.
llvm::Value *LlvmInterpreterProxy::instantiateClassindexableSize(llvm::Value *classPointer, llvm::Value *size)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopOopToOop, (void*)interpreterProxy->instantiateClassindexableSize, "instantiateClassindexableSize");
    return builder.CreateCall2(function, classPointer, size, "instantiateClassindexableSize");
}

llvm::Value *LlvmInterpreterProxy::instantiateClassindexableSize(llvm::Value *classPointer, int size)
{
    return instantiateClassindexableSize(classPointer, intAsSqIntValue(size));
}

// Other methods.
llvm::Value *LlvmInterpreterProxy::failed()
{
    llvm::Value *function = getFunctionConstant(functionTypeVoidToOop, (void*)interpreterProxy->failed, "failed");
    return builder.CreateCall(function, "failed");
}

llvm::Value *LlvmInterpreterProxy::primitiveFail()
{
    llvm::Value *function = getFunctionConstant(functionTypeVoidToOop, (void*)interpreterProxy->primitiveFail, "primitiveFail");
    return builder.CreateCall(function, "primitiveFail");
}

llvm::Value *LlvmInterpreterProxy::primitiveFailFor(llvm::Value *errorCode)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->primitiveFail, "primitiveFailFor");
    return builder.CreateCall(function, errorCode, "primitiveFailFor");
}

llvm::Value *LlvmInterpreterProxy::primitiveFailFor(int errorCode)
{
    return primitiveFailFor(intAsSqIntValue(errorCode));
}

// Primitive - Oop conversion
llvm::Value *LlvmInterpreterProxy::booleanValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->booleanValueOf, "booleanValueOf");
    return builder.CreateCall(function, oop, "booleanValueOf");
}

llvm::Value *LlvmInterpreterProxy::floatObjectOf(llvm::Value *aFloat)
{
    llvm::Value *function = getFunctionConstant(functionTypeDoubleToOop, (void*)interpreterProxy->floatObjectOf, "floatObjectOf");
    return builder.CreateCall(function, aFloat, "floatObjectOf");
}

llvm::Value *LlvmInterpreterProxy::floatValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToDouble, (void*)interpreterProxy->floatValueOf, "floatValueOf");
    return builder.CreateCall(function, oop, "floatValueOf");
}

llvm::Value *LlvmInterpreterProxy::integerObjectOf(llvm::Value *value)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->integerObjectOf, "integerObjectOf");
    return builder.CreateCall(function, value, "integerObjectOf");
}

llvm::Value *LlvmInterpreterProxy::integerValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->integerValueOf, "integerValueOf");
    return builder.CreateCall(function, oop, "integerValueOf");
}

llvm::Value *LlvmInterpreterProxy::positive32BitIntegerFor(llvm::Value *integerValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->positive32BitIntegerFor, "positive32BitIntegerFor");
    return builder.CreateCall(function, integerValue, "positive32BitIntegerFor");
}

llvm::Value *LlvmInterpreterProxy::positive32BitValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->positive32BitValueOf, "positive32BitValueOf");
    return builder.CreateCall(function, oop, "positive32BitValueOf");
}

llvm::Value *LlvmInterpreterProxy::signed32BitIntegerFor(llvm::Value *integerValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->signed32BitIntegerFor, "signed32BitIntegerFor");
    return builder.CreateCall(function, integerValue, "signed32BitIntegerFor");
}

llvm::Value *LlvmInterpreterProxy::signed32BitValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToOop, (void*)interpreterProxy->signed32BitValueOf, "signed32BitValueOf");
    return builder.CreateCall(function, oop, "signed32BitValueOf");
}

llvm::Value *LlvmInterpreterProxy::positive64BitIntegerFor(llvm::Value *integerValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeLongToOop, (void*)interpreterProxy->positive64BitIntegerFor, "positive64BitIntegerFor");
    return builder.CreateCall(function, integerValue, "positive64BitIntegerFor");
}

llvm::Value *LlvmInterpreterProxy::positive64BitValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToLong, (void*)interpreterProxy->positive64BitValueOf, "positive64BitValueOf");
    return builder.CreateCall(function, oop, "positive64BitValueOf");

}

llvm::Value *LlvmInterpreterProxy::signed64BitIntegerFor(llvm::Value *integerValue)
{
    llvm::Value *function = getFunctionConstant(functionTypeLongToOop, (void*)interpreterProxy->signed64BitIntegerFor, "signed64BitIntegerFor");
    return builder.CreateCall(function, integerValue, "signed64BitIntegerFor");
}

llvm::Value *LlvmInterpreterProxy::signed64BitValueOf(llvm::Value *oop)
{
    llvm::Value *function = getFunctionConstant(functionTypeOopToLong, (void*)interpreterProxy->signed64BitValueOf, "signed64BitValueOf");
    return builder.CreateCall(function, oop, "signed64BitValueOf");
}

// Helper methods.
llvm::Value *LlvmInterpreterProxy::intAsSqIntValue(int value)
{
    return llvm::ConstantInt::get(sqIntType, value);
}

llvm::Value *LlvmInterpreterProxy::getFunctionConstant(llvm::FunctionType *type, void *functionPointer, const char *name)
{
    llvm::Type *pointerType = llvm::PointerType::getUnqual(type);
    return getPointerConstant(pointerType, functionPointer);
}

llvm::Value *LlvmInterpreterProxy::getPointerConstant(llvm::Type *type, void *pointer)
{
    llvm::Constant *intptr = llvm::ConstantInt::get(uintPtrType, reinterpret_cast<uintptr_t> (pointer));
    return llvm::ConstantExpr::getIntToPtr(intptr, type);
}

} // namespace Lowcode


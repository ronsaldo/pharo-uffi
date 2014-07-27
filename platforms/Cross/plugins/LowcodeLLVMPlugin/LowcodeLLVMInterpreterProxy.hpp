#ifndef _LOWCODW_LLVM_INTERPRETER_PROXY_HPP_
#define _LOWCODW_LLVM_INTERPRETER_PROXY_HPP_

namespace Lowcode
{

/**
 * This is the Llvm version of the interpreter proxy.
 */
class LlvmInterpreterProxy
{
public:
    LlvmInterpreterProxy(VirtualMachine *interpreterProxy, llvm::IRBuilder<> &builder);
    ~LlvmInterpreterProxy();

    // Stack accessing
	llvm::Value *popthenPush(llvm::Value *nItems, llvm::Value * oop);
	llvm::Value *popthenPush(int nItems, llvm::Value * oop);
	llvm::Value *stackValue(llvm::Value *offset);
	llvm::Value *stackValue(int offset);

    // Object accessing
	llvm::Value *byteSizeOf(llvm::Value *oop);
    llvm::Value *fetchPointerofObject(llvm::Value *fieldIndex, llvm::Value *oopValue);
    llvm::Value *fetchPointerofObject(int fieldIndex, llvm::Value *oopValue);
    llvm::Value *fetchClassOf(llvm::Value *oopValue);
    llvm::Value *firstIndexableField(llvm::Value *oopValue);
    llvm::Value *firstFixedField(llvm::Value *oopValue);
	llvm::Value *storePointerofObjectwithValue(llvm::Value *fieldIndex, llvm::Value *oop, llvm::Value *valuePointer);
	llvm::Value *storePointerofObjectwithValue(int fieldIndex, llvm::Value *oop, llvm::Value *valuePointer);

    // Testing
	llvm::Value *isBytes(llvm::Value *oop);
	llvm::Value *isFloatObject(llvm::Value *oop);
	llvm::Value *isIndexable(llvm::Value *oop);
	llvm::Value *isIntegerObject(llvm::Value *objectPointer);
	llvm::Value *isIntegerValue(llvm::Value *intValue);
	llvm::Value *isPointers(llvm::Value *oop);
	llvm::Value *isWeak(llvm::Value *oop);
	llvm::Value *isWords(llvm::Value *oop);
	llvm::Value *isWordsOrBytes(llvm::Value *oop);

    // Special objects.
	llvm::Value *falseObject();
	llvm::Value *nilObject();
	llvm::Value *trueObject();

    // Instance creation.
	llvm::Value *instantiateClassindexableSize(llvm::Value *classPointer, llvm::Value *size);
	llvm::Value *instantiateClassindexableSize(llvm::Value *classPointer, int size);

    // Others
	llvm::Value *failed();
	llvm::Value *primitiveFail();
	llvm::Value *primitiveFailFor(llvm::Value *errorCode);
	llvm::Value *primitiveFailFor(int errorCode);

    // Primitive - Oop conversion
	llvm::Value *booleanValueOf(llvm::Value *oop);

	llvm::Value *floatObjectOf(llvm::Value *aFloat);
	llvm::Value *floatValueOf(llvm::Value *oop);

	llvm::Value *integerObjectOf(llvm::Value *value);
	llvm::Value *integerValueOf(llvm::Value *oop);

	llvm::Value *positive32BitIntegerFor(llvm::Value *integerValue);
	llvm::Value *positive32BitValueOf(llvm::Value *oop);

	llvm::Value *signed32BitIntegerFor(llvm::Value *integerValue);
	llvm::Value *signed32BitValueOf(llvm::Value *oop);

	llvm::Value *positive64BitIntegerFor(llvm::Value *integerValue);
	llvm::Value *positive64BitValueOf(llvm::Value *oop);

	llvm::Value *signed64BitIntegerFor(llvm::Value *integerValue);
	llvm::Value *signed64BitValueOf(llvm::Value *oop);


private:
    void createFunctionTypes();

    llvm::Value *intAsSqIntValue(int value);
    llvm::Value *getFunctionConstant(llvm::FunctionType *type, void *functionPointer, const char *name);
    llvm::Value *getPointerConstant(llvm::Type *type, void *pointer);

    VirtualMachine *interpreterProxy;
    llvm::IRBuilder<> &builder;
    llvm::Type *sqIntType;
    llvm::Type *uintPtrType;
    llvm::Type *longType;
    llvm::Type *doubleType;
    llvm::Type *pointerType;

    // Function types.
    llvm::FunctionType *functionTypeVoidToOop;
    llvm::FunctionType *functionTypeOopToOop;
    llvm::FunctionType *functionTypeOopOopToOop;
    llvm::FunctionType *functionTypeOopOopOopToOop;
    llvm::FunctionType *functionTypeOopToPtr;

    llvm::FunctionType *functionTypeDoubleToOop;
    llvm::FunctionType *functionTypeOopToDouble;
    llvm::FunctionType *functionTypeLongToOop;
    llvm::FunctionType *functionTypeOopToLong;
};

} // namespace Lowcode

#endif //_LOWCODW_LLVM_INTERPRETER_PROXY_HPP_

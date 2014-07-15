/** * WARNING: This file was automatically generated. DO NOT MODIFY. */#include <stdlib.h>#include <stdio.h>#include <string.h>#include <math.h>#include "LowcodeInterpreterPlugin.h"/* Sista bytecode decoding constants */#define SISTA_OPCODE_ONE_BYTE_LAST 223#define SISTA_OPCODE_TWO_BYTE_LAST 247#define SISTA_OPCODE_EXT_A 224#define SISTA_OPCODE_EXT_B 225/* Primitive types stack. */#define DEFAULT_PRIMITIVE_STACK_SIZE 256#define STACK_CHECK_REMAINING_CAPACITY(size) {\	if(primitiveStackCapacity - primitiveStackSize < size) { \		fprintf(stderr, "FATAL ERROR: Lowcode Primitive Stack Overflow\n"); \		abort();\	}\}#define STACK_CHECK_MINIMAL_SIZE(size) {\	if(primitiveStackSize < size) { \		fprintf(stderr, "FATAL ERROR: Lowcode Primitive Stack Underflow\n"); \		abort();\	}\}#define PUSH_VALUE_OF_TYPE(x, type) {\	STACK_CHECK_REMAINING_CAPACITY(sizeof(type));\	*((type*)(primitiveStack + primitiveStackSize) )= x;\	primitiveStackSize += sizeof(type);\}#define PUSH_INT32(x) PUSH_VALUE_OF_TYPE(x, int32_t)#define PUSH_INT64(x) PUSH_VALUE_OF_TYPE(x, int64_t)#define PUSH_FLOAT32(x) PUSH_VALUE_OF_TYPE(x, float)#define PUSH_FLOAT64(x) PUSH_VALUE_OF_TYPE(x, double)#define PUSH_POINTER(x) PUSH_VALUE_OF_TYPE(x, void*)#define POP_VALUE_OF_TYPE(dest, type) { \	STACK_CHECK_MINIMAL_SIZE(sizeof(type)); \	primitiveStackSize -= sizeof(type); \	dest = *((type*)(primitiveStack + primitiveStackSize)); \}#define POP_INT32_TO(x) POP_VALUE_OF_TYPE(x, int32_t)#define POP_INT64_TO(x) POP_VALUE_OF_TYPE(x, int64_t)#define POP_FLOAT32_TO(x) POP_VALUE_OF_TYPE(x, float)#define POP_FLOAT64_TO(x) POP_VALUE_OF_TYPE(x, double)#define POP_POINTER_TO(x) POP_VALUE_OF_TYPE(x, void*)/* Oop macros */#define POP_OOP_TO(x) {x = interpreterProxy->pop(1); oopStackSize--; }#define PUSH_OOP(x) { interpreterProxy->push(x); oopStackSize++; }#define PUSH_OOP_INTEGER(x) { interpreterProxy->pushInteger(x); oopStackSize++; }/* Special macros */#define LABEL_AT_TO(id, dest) { \	sqInt literalOop = interpreterProxy->stObjectat(literals, id + 1); \	CHECK_FAILED(); \	dest = instructionStream + interpreterProxy->integerValueOf(literalOop); \}/* Utility macros */#define CHECK_FAILED() { \	if(interpreterProxy->failed()) \		return interpreterProxy->primitiveFail(); \}#define RETURN_OOP(oop) return interpreterProxy->popthenPush(oopStackSize, oop);
/* Lowcode instructions opcode constants */
#define OPCODE_PUSHZERO32 256
#define OPCODE_PUSHONE32 257
#define OPCODE_LOADEFFECTIVEADDRESS32 258
#define OPCODE_LOADUINT8FROMMEMORY 259
#define OPCODE_LOADUINT16FROMMEMORY 260
#define OPCODE_LOADUINT32FROMMEMORY 261
#define OPCODE_LOADUINT64FROMMEMORY 262
#define OPCODE_LOADINT8FROMMEMORY 263
#define OPCODE_LOADINT16FROMMEMORY 264
#define OPCODE_LOADINT32FROMMEMORY 265
#define OPCODE_LOADINT64FROMMEMORY 266
#define OPCODE_LOADPOINTERFROMMEMORY 267
#define OPCODE_LOADFLOAT32FROMMEMORY 268
#define OPCODE_LOADFLOAT64FROMMEMORY 269
#define OPCODE_STOREINT8TOMEMORY 270
#define OPCODE_STOREINT16TOMEMORY 271
#define OPCODE_STOREINT32TOMEMORY 272
#define OPCODE_STOREINT64TOMEMORY 273
#define OPCODE_STOREPOINTERTOMEMORY 274
#define OPCODE_STOREFLOAT32TOMEMORY 275
#define OPCODE_STOREFLOAT64TOMEMORY 276
#define OPCODE_SIGNEXTEND32FROM8 277
#define OPCODE_SIGNEXTEND32FROM16 278
#define OPCODE_SIGNEXTEND64FROM8 279
#define OPCODE_SIGNEXTEND64FROM16 280
#define OPCODE_SIGNEXTEND64FROM32 281
#define OPCODE_ZEROEXTEND32FROM8 282
#define OPCODE_ZEROEXTEND32FROM16 283
#define OPCODE_ZEROEXTEND64FROM8 284
#define OPCODE_ZEROEXTEND64FROM16 285
#define OPCODE_ZEROEXTEND64FROM32 286
#define OPCODE_TRUNCATE32TO8 287
#define OPCODE_TRUNCATE32TO16 288
#define OPCODE_TRUNCATE64TO8 289
#define OPCODE_TRUNCATE64TO16 290
#define OPCODE_TRUNCATE64TO32 291
#define OPCODE_UINT32TOFLOAT32 292
#define OPCODE_UINT32TOFLOAT64 293
#define OPCODE_INT32TOFLOAT32 294
#define OPCODE_INT32TOFLOAT64 295
#define OPCODE_UINT64TOFLOAT32 296
#define OPCODE_UINT64TOFLOAT64 297
#define OPCODE_INT64TOFLOAT32 298
#define OPCODE_INT64TOFLOAT64 299
#define OPCODE_FLOAT32TOINT32 300
#define OPCODE_FLOAT64TOINT32 301
#define OPCODE_FLOAT32TOINT64 302
#define OPCODE_FLOAT64TOINT64 303
#define OPCODE_ADD32 304
#define OPCODE_SUB32 305
#define OPCODE_MUL32 306
#define OPCODE_UMUL32 307
#define OPCODE_DIV32 308
#define OPCODE_UDIV32 309
#define OPCODE_REM32 310
#define OPCODE_UREM32 311
#define OPCODE_ADD64 312
#define OPCODE_SUB64 313
#define OPCODE_MUL64 314
#define OPCODE_UMUL64 315
#define OPCODE_DIV64 316
#define OPCODE_UDIV64 317
#define OPCODE_REM64 318
#define OPCODE_UREM64 319
#define OPCODE_NOT32 320
#define OPCODE_AND32 321
#define OPCODE_OR32 322
#define OPCODE_XOR32 323
#define OPCODE_LEFTSHIFT32 324
#define OPCODE_RIGHTSHIFT32 325
#define OPCODE_ARITHMETICRIGHTSHIFT32 326
#define OPCODE_NOT64 327
#define OPCODE_AND64 328
#define OPCODE_OR64 329
#define OPCODE_XOR64 330
#define OPCODE_LEFTSHIFT64 331
#define OPCODE_RIGHTSHIFT64 332
#define OPCODE_ARITHMETICRIGHTSHIFT64 333
#define OPCODE_FLOAT32ADD 334
#define OPCODE_FLOAT32SUB 335
#define OPCODE_FLOAT32MUL 336
#define OPCODE_FLOAT32DIV 337
#define OPCODE_FLOAT64ADD 338
#define OPCODE_FLOAT64SUB 339
#define OPCODE_FLOAT64MUL 340
#define OPCODE_FLOAT64DIV 341
#define OPCODE_PIN 342
#define OPCODE_UNPIN 343
#define OPCODE_OOPTOPOINTER 344
#define OPCODE_POINTERTOOOP 345
#define OPCODE_OOPTOBOOLEAN 346
#define OPCODE_OOPSMALLINTTOINT32 347
#define OPCODE_OOPTOINT32 348
#define OPCODE_OOPTOUINT32 349
#define OPCODE_OOPSMALLINTEGERTOINT64 350
#define OPCODE_OOPTOINT64 351
#define OPCODE_OOPTOUINT64 352
#define OPCODE_OOPTOFLOAT32 353
#define OPCODE_OOPTOFLOAT64 354
#define OPCODE_BOOLEANTOOOP32 355
#define OPCODE_SMALLINT32TOOOP 356
#define OPCODE_INT32TOOOP 357
#define OPCODE_UINT32TOOOP 358
#define OPCODE_INT64TOOOP 359
#define OPCODE_UINT64TOOOP 360
#define OPCODE_FLOAT32TOOOP 361
#define OPCODE_FLOAT64TOOOP 362
#define OPCODE_FIRSTFIELDPTR 363
#define OPCODE_FIRSTINDEXPTR 364
#define OPCODE_COMPARE32 365
#define OPCODE_COMPARE64 366
#define OPCODE_FLOAT32COMPARE 367
#define OPCODE_FLOAT64COMPARE 368
#define OPCODE_TEST32 369
#define OPCODE_TEST64 370
#define OPCODE_JUMP 371
#define OPCODE_BRANCHEQUAL 372
#define OPCODE_BRANCHNOTEQUAL 373
#define OPCODE_BRANCHLESS 374
#define OPCODE_BRANCHLESSEQUAL 375
#define OPCODE_BRANCHGREATER 376
#define OPCODE_BRANCHGREATEQUAL 377
#define OPCODE_BRANCHUNSIGNEDLESS 378
#define OPCODE_BRANCHUNSIGNEDLESSEQUAL 379
#define OPCODE_BRANCHUNSIGNEDGREATER 380
#define OPCODE_BRANCHUNSIGNEDGREATEQUAL 381
#define OPCODE_BRANCHOVERFLOW 382
#define OPCODE_BRANCHNOTOVERFLOW 383
#define OPCODE_BRANCHPRIMITIVEFAILED 384
#define OPCODE_BRANCHPRIMITIVESUCCEED 385
#define OPCODE_RETURNINT32 390
#define OPCODE_RETURNINT64 391
#define OPCODE_RETURNPOINTER 392
#define OPCODE_RETURNFLOAT32 393
#define OPCODE_RETURNFLOAT64 394
#define OPCODE_LOCKVM 395
#define OPCODE_UNLOCKVM 396
#define OPCODE_COMPAREANDSWAP32 397
#define OPCODE_ALLOCA32 398
#define OPCODE_ALLOCA64 399
#define OPCODE_MALLOC32 400
#define OPCODE_MALLOC64 401
#define OPCODE_FREE 402
#define OPCODE_BEGINCALL 403
#define OPCODE_CALLARGUMENTINT32 404
#define OPCODE_CALLARGUMENTINT64 405
#define OPCODE_CALLARGUMENTFLOAT32 406
#define OPCODE_CALLARGUMENTFLOAT64 407
#define OPCODE_PERFORMCALL 408
#define OPCODE_PERFORMCALLINDIRECT 409
#define OPCODE_ENDCALL 410
#define OPCODE_ENDCALLNOCLEANUP 411
#define OPCODE_PLAFTORMCODE 412
#define OPCODE_LOCKREGISTERS 413
#define OPCODE_UNLOCKREGISTERS 414
#define OPCODE_MOVEINT32TOPHYSICAL 415
#define OPCODE_MOVEINT64TOPHYSICAL 416
#define OPCODE_MOVEPOINTERTOPHYSICAL 417
#define OPCODE_MOVEFLOAT32TOPHYSICAL 418
#define OPCODE_MOVEFLOAT64TOPHYSICAL 419
#define OPCODE_PUSHPHYSICALINT32 420
#define OPCODE_PUSHPHYSICALINT64 421
#define OPCODE_PUSHPHYSICALPOINTER 422
#define OPCODE_PUSHPHYSICALFLOAT32 423
#define OPCODE_PUSHPHYSICALFLOAT64 424
#define OPCODE_CALLPHYSICAL 425
#define OPCODE_CALLINSTRUCTION 426
sqInt LowcodePlugin_InterpretCodeLiteralsReceiverArguments(VirtualMachine *interpreterProxy, uint8_t *instructionStream, sqInt literals, sqInt receiver, sqInt arguments){	/* Allocate space for the primitive stack */	char* primitiveStack = alloca(DEFAULT_PRIMITIVE_STACK_SIZE);	size_t primitiveStackCapacity = DEFAULT_PRIMITIVE_STACK_SIZE;	size_t primitiveStackSize = 0;	/* Oop stack tracking */	size_t oopStackSize = interpreterProxy->methodArgumentCount() + 1;		/* Some counts */	size_t numberLiterals = interpreterProxy->stSizeOf(literals);	size_t numberOfArguments = interpreterProxy->stSizeOf(arguments);	/* Condition Flags */	LowcodeConditionFlags currentConditionFlags;		/* The current program counter. */	uint8_t *pc = instructionStream;	uint32_t extA = 0;	uint32_t extB = 0;	{		size_t i;		/* Push the receiver and arguments in the stack */		interpreterProxy->push(receiver);		for(i = 0; i < numberOfArguments; ++i)			interpreterProxy->push(interpreterProxy->stObjectat(arguments, i + 1));		oopStackSize += 1 + numberOfArguments;		CHECK_FAILED();	}		/* Execute all the instructions without verification */	for(;;)	{		/* Fetch the first Sista extended bytecode opcode. */		uint8_t sistaOpcode = *(pc++);		/* Sista instructions are variable sized */		if(sistaOpcode <= SISTA_OPCODE_ONE_BYTE_LAST)		{			switch(sistaOpcode)			{
			/* 'pushReceiverVariable'*/
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			{
            /* TODO: Implement this*/        
			}				break;
			/* 'pushLiteralVariable'*/
			case 16:
			case 17:
			case 18:
			case 19:
			case 20:
			case 21:
			case 22:
			case 23:
			case 24:
			case 25:
			case 26:
			case 27:
			case 28:
			case 29:
			case 30:
			case 31:
			{
            /* TODO: Implement this*/        
			}				break;
			/* 'pushLiteral'*/
			case 32:
			case 33:
			case 34:
			case 35:
			case 36:
			case 37:
			case 38:
			case 39:
			case 40:
			case 41:
			case 42:
			case 43:
			case 44:
			case 45:
			case 46:
			case 47:
			case 48:
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
			case 56:
			case 57:
			case 58:
			case 59:
			case 60:
			case 61:
			case 62:
			case 63:
			{
            /* TODO: Implement this*/        
			}				break;
			/* 'pushTemp'*/
			case 64:
			case 65:
			case 66:
			case 67:
			case 68:
			case 69:
			case 70:
			case 71:
			{
            /* TODO: Implement this*/        
			}				break;
			/* 'pushTempP8'*/
			case 72:
			case 73:
			case 74:
			case 75:
			{
            /* TODO: Implement this*/        
			}				break;
			/* 'pushReceiver'*/
			case 76:
			{
            PUSH_OOP(receiver);        
			}				break;
			/* 'pushTrue'*/
			case 77:
			{
            PUSH_OOP(interpreterProxy->trueObject());        
			}				break;
			/* 'pushFalse'*/
			case 78:
			{
            PUSH_OOP(interpreterProxy->falseObject());        
			}				break;
			/* 'pushNil'*/
			case 79:
			{
            PUSH_OOP(interpreterProxy->nilObject());        
			}				break;
			/* 'pushZero'*/
			case 80:
			{
            PUSH_OOP_INTEGER(0);        
			}				break;
			/* 'pushOne'*/
			case 81:
			{
            PUSH_OOP_INTEGER(1);        
			}				break;
			/* 'pushThisContext'*/
			case 82:
			{
            /* Not Supported*/        
			}				break;
			/* 'dupTop'*/
			case 83:
			{
            PUSH_OOP(interpreterProxy->stackValue(0));        
			}				break;
			/* 'returnReceiver'*/
			case 88:
			{
            RETURN_OOP(receiver);        
			}				break;
			/* 'returnTrue'*/
			case 89:
			{
            RETURN_OOP(interpreterProxy->trueObject());        
			}				break;
			/* 'returnFalse'*/
			case 90:
			{
            RETURN_OOP(interpreterProxy->falseObject());        
			}				break;
			/* 'returnNil'*/
			case 91:
			{
            RETURN_OOP(interpreterProxy->nilObject());        
			}				break;
			/* 'returnTop'*/
			case 92:
			{
            sqInt top = interpreterProxy->stackValue(0);            RETURN_OOP(top);        
			}				break;
			/* 'nop'*/
			case 95:
			{
            /* Do nothing*/        
			}				break;
			/* 'popStackTop'*/
			case 216:
			{
            sqInt dummy;            POP_OOP_TO(dummy);        
			}				break;
			default:				return interpreterProxy->primitiveFail();			}		}		else if(sistaOpcode <= SISTA_OPCODE_TWO_BYTE_LAST)		{			/* Read the extension values. */			if(sistaOpcode == SISTA_OPCODE_EXT_A)			{				extA  = extA*256 + (*(pc++));			}			else if(sistaOpcode == SISTA_OPCODE_EXT_B)			{				extB  = extB*256 + (*(pc++)); 			}			else			{ 				/* TODO: Wait for Christmas */ 				return interpreterProxy->primitiveFail(); /* Unsupported here. */			}		}		else		{			/* Only interested in line primitives */ 			if(sistaOpcode != 248)				return interpreterProxy->primitiveFail(); /* Unsupported here. */			/* Decode the inline primitive opcode. */			uint16_t opcode = (*pc++);			opcode |=(*pc++) << 8;			/* Ensure it is a inline primitive. */			if((opcode & (1<<15)) == 0)				return interpreterProxy->primitiveFail(); /* Unsupported here. */			opcode &= ~(1<<15);			/* Fetch the instruction OpCode */			switch(opcode)			{
			case OPCODE_PUSHZERO32:			{
				int32_t result;
            result = 0;        
				PUSH_INT32(result);
			}				break;			case OPCODE_PUSHONE32:			{
				int32_t result;
            result = 1;        
				PUSH_INT32(result);
			}				break;			case OPCODE_LOADEFFECTIVEADDRESS32:			{
				void* base;
				int32_t index;
				int32_t scale;
				int32_t offset;
				void* result;
				POP_INT32_TO(offset);
				POP_INT32_TO(scale);
				POP_INT32_TO(index);
				POP_POINTER_TO(base);
            result = ((char*)base) + index*scale + offset;        
				PUSH_POINTER(result);
			}				break;			case OPCODE_LOADUINT8FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = (uint32_t)*((uint8_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADUINT16FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = (uint32_t)*((uint16_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADUINT32FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = *((uint32_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADUINT64FROMMEMORY:			{
				void* pointer;
				int64_t value;
				POP_POINTER_TO(pointer);
            value = *((uint64_t*)pointer);        
				PUSH_INT64(value);
			}				break;			case OPCODE_LOADINT8FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = *((int8_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADINT16FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = *((int16_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADINT32FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = *((int32_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADINT64FROMMEMORY:			{
				void* pointer;
				int32_t value;
				POP_POINTER_TO(pointer);
            value = *((int64_t*)pointer);        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADPOINTERFROMMEMORY:			{
				void* pointer;
				void* value;
				POP_POINTER_TO(pointer);
            value = *((void**)pointer);        
				PUSH_POINTER(value);
			}				break;			case OPCODE_LOADFLOAT32FROMMEMORY:			{
				void* pointer;
				float value;
				POP_POINTER_TO(pointer);
            value = *((float*)pointer);        
				PUSH_FLOAT32(value);
			}				break;			case OPCODE_LOADFLOAT64FROMMEMORY:			{
				void* pointer;
				double value;
				POP_POINTER_TO(pointer);
            value = *((double*)pointer);        
				PUSH_FLOAT64(value);
			}				break;			case OPCODE_STOREINT8TOMEMORY:			{
				void* pointer;
				int32_t value;
				POP_INT32_TO(value);
				POP_POINTER_TO(pointer);
            *((int8_t*)pointer) = value;        
			}				break;			case OPCODE_STOREINT16TOMEMORY:			{
				void* pointer;
				int32_t value;
				POP_INT32_TO(value);
				POP_POINTER_TO(pointer);
            *((int16_t*)pointer) = value;        
			}				break;			case OPCODE_STOREINT32TOMEMORY:			{
				void* pointer;
				int32_t value;
				POP_INT32_TO(value);
				POP_POINTER_TO(pointer);
            *((int32_t*)pointer) = value;        
			}				break;			case OPCODE_STOREINT64TOMEMORY:			{
				void* pointer;
				int64_t value;
				POP_INT64_TO(value);
				POP_POINTER_TO(pointer);
            *((int64_t*)pointer) = value;        
			}				break;			case OPCODE_STOREPOINTERTOMEMORY:			{
				void* memoryPointer;
				void* value;
				POP_POINTER_TO(value);
				POP_POINTER_TO(memoryPointer);
            *((void**)memoryPointer) = value;        
			}				break;			case OPCODE_STOREFLOAT32TOMEMORY:			{
				void* pointer;
				float value;
				POP_FLOAT32_TO(value);
				POP_POINTER_TO(pointer);
            *((float*)pointer) = value;        
			}				break;			case OPCODE_STOREFLOAT64TOMEMORY:			{
				void* pointer;
				double value;
				POP_FLOAT64_TO(value);
				POP_POINTER_TO(pointer);
            *((double*)pointer) = value;        
			}				break;			case OPCODE_SIGNEXTEND32FROM8:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = (int8_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_SIGNEXTEND32FROM16:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = (int16_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_SIGNEXTEND64FROM8:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (int8_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_SIGNEXTEND64FROM16:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (int16_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_SIGNEXTEND64FROM32:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (int32_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_ZEROEXTEND32FROM8:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = (uint8_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_ZEROEXTEND32FROM16:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = (uint16_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_ZEROEXTEND64FROM8:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (uint8_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_ZEROEXTEND64FROM16:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (uint16_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_ZEROEXTEND64FROM32:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (uint32_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_TRUNCATE32TO8:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = (uint8_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_TRUNCATE32TO16:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = (uint16_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_TRUNCATE64TO8:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (uint8_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_TRUNCATE64TO16:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (uint16_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_TRUNCATE64TO32:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = (uint32_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_UINT32TOFLOAT32:			{
				int32_t value;
				float result;
				POP_INT32_TO(value);
            result = (uint32_t)value;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_UINT32TOFLOAT64:			{
				int32_t value;
				double result;
				POP_INT32_TO(value);
            result = (uint32_t)value;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_INT32TOFLOAT32:			{
				int32_t value;
				float result;
				POP_INT32_TO(value);
            result = (int32_t)value;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_INT32TOFLOAT64:			{
				int32_t value;
				double result;
				POP_INT32_TO(value);
            result = (int32_t)value;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_UINT64TOFLOAT32:			{
				int64_t value;
				float result;
				POP_INT64_TO(value);
            result = (uint64_t)value;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_UINT64TOFLOAT64:			{
				int64_t value;
				double result;
				POP_INT64_TO(value);
            result = (uint64_t)value;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_INT64TOFLOAT32:			{
				int64_t value;
				double result;
				POP_INT64_TO(value);
            result = (int64_t)value;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_INT64TOFLOAT64:			{
				int64_t value;
				double result;
				POP_INT64_TO(value);
            result = (int64_t)value;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_FLOAT32TOINT32:			{
				float value;
				int32_t result;
				POP_FLOAT32_TO(value);
            result = (int32_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_FLOAT64TOINT32:			{
				double value;
				int32_t result;
				POP_FLOAT64_TO(value);
            result = (int32_t)value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_FLOAT32TOINT64:			{
				float value;
				int64_t result;
				POP_FLOAT32_TO(value);
            result = (int64_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_FLOAT64TOINT64:			{
				double value;
				int64_t result;
				POP_FLOAT64_TO(value);
            result = (int64_t)value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_ADD32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first + second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_SUB32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first - second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_MUL32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first * second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_UMUL32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = (uint32_t)first * (uint32_t)second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_DIV32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first / second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_UDIV32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = ((uint32_t)first) / ((uint32_t)second);        
				PUSH_INT32(result);
			}				break;			case OPCODE_REM32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first % second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_UREM32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = ((uint32_t)first) % ((uint32_t)second);        
				PUSH_INT32(result);
			}				break;			case OPCODE_ADD64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first + second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_SUB64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first - second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_MUL64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first * second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_UMUL64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = (uint64_t)first * (uint64_t)second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_DIV64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first / second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_UDIV64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = ((uint64_t)first) / ((uint64_t)second);        
				PUSH_INT64(result);
			}				break;			case OPCODE_REM64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first % second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_UREM64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = ((uint64_t)first) % ((uint64_t)second);        
				PUSH_INT64(result);
			}				break;			case OPCODE_NOT32:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = ~value;        
				PUSH_INT32(result);
			}				break;			case OPCODE_AND32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first & second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_OR32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first | second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_XOR32:			{
				int32_t first;
				int32_t second;
				int32_t result;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            result = first ^ second;        
				PUSH_INT32(result);
			}				break;			case OPCODE_LEFTSHIFT32:			{
				int32_t value;
				int32_t shiftAmount;
				int32_t result;
				POP_INT32_TO(shiftAmount);
				POP_INT32_TO(value);
            result = value << shiftAmount;        
				PUSH_INT32(result);
			}				break;			case OPCODE_RIGHTSHIFT32:			{
				int32_t value;
				int32_t shiftAmount;
				int32_t result;
				POP_INT32_TO(shiftAmount);
				POP_INT32_TO(value);
            result = ((uint32_t)value) >> ((uint32_t)shiftAmount);        
				PUSH_INT32(result);
			}				break;			case OPCODE_ARITHMETICRIGHTSHIFT32:			{
				int32_t value;
				int32_t shiftAmount;
				int32_t result;
				POP_INT32_TO(shiftAmount);
				POP_INT32_TO(value);
            result = value >> shiftAmount;        
				PUSH_INT32(result);
			}				break;			case OPCODE_NOT64:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = ~value;        
				PUSH_INT64(result);
			}				break;			case OPCODE_AND64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first & second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_OR64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first | second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_XOR64:			{
				int64_t first;
				int64_t second;
				int64_t result;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            result = first ^ second;        
				PUSH_INT64(result);
			}				break;			case OPCODE_LEFTSHIFT64:			{
				int64_t value;
				int64_t shiftAmount;
				int64_t result;
				POP_INT64_TO(shiftAmount);
				POP_INT64_TO(value);
            result = value << shiftAmount;        
				PUSH_INT64(result);
			}				break;			case OPCODE_RIGHTSHIFT64:			{
				int64_t value;
				int64_t shiftAmount;
				int64_t result;
				POP_INT64_TO(shiftAmount);
				POP_INT64_TO(value);
            result = ((uint64_t)value) >> ((uint64_t)shiftAmount);        
				PUSH_INT64(result);
			}				break;			case OPCODE_ARITHMETICRIGHTSHIFT64:			{
				int64_t value;
				int64_t shiftAmount;
				int64_t result;
				POP_INT64_TO(shiftAmount);
				POP_INT64_TO(value);
            result = value >> shiftAmount;        
				PUSH_INT64(result);
			}				break;			case OPCODE_FLOAT32ADD:			{
				float first;
				float second;
				float result;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            result = first + second;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_FLOAT32SUB:			{
				float first;
				float second;
				float result;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            result = first - second;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_FLOAT32MUL:			{
				float first;
				float second;
				float result;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            result = first * second;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_FLOAT32DIV:			{
				float first;
				float second;
				float result;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            result = first / second;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_FLOAT64ADD:			{
				double first;
				double second;
				double result;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            result = first + second;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_FLOAT64SUB:			{
				double first;
				double second;
				double result;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            result = first - second;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_FLOAT64MUL:			{
				double first;
				double second;
				double result;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            result = first * second;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_FLOAT64DIV:			{
				double first;
				double second;
				double result;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            result = first / second;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_PIN:			{
				sqInt object;
				POP_OOP_TO(object);
            /* TODO: Requires Spur */        
			}				break;			case OPCODE_UNPIN:			{
				sqInt object;
				POP_OOP_TO(object);
            /* TODO: Requires Spur */        
			}				break;			case OPCODE_OOPTOPOINTER:			{
				sqInt object;
				void* pointer;
				POP_OOP_TO(object);
            pointer = (void*)object;        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_POINTERTOOOP:			{
				void* pointer;
				sqInt object;
				POP_POINTER_TO(pointer);
            object = (sqInt)pointer;        
				PUSH_OOP(object);
			}				break;			case OPCODE_OOPTOBOOLEAN:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->booleanValueOf(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPSMALLINTTOINT32:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->integerValueOf(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPTOINT32:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->signed32BitValueOf(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPTOUINT32:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->positive32BitValueOf(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPSMALLINTEGERTOINT64:			{
				sqInt object;
				int64_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->integerValueOf(object);        
				PUSH_INT64(value);
			}				break;			case OPCODE_OOPTOINT64:			{
				sqInt object;
				int64_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->signed64BitValueOf(object);        
				PUSH_INT64(value);
			}				break;			case OPCODE_OOPTOUINT64:			{
				sqInt object;
				int64_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->positive64BitValueOf(object);        
				PUSH_INT64(value);
			}				break;			case OPCODE_OOPTOFLOAT32:			{
				sqInt object;
				float value;
				POP_OOP_TO(object);
            value = interpreterProxy->floatValueOf(object);        
				PUSH_FLOAT32(value);
			}				break;			case OPCODE_OOPTOFLOAT64:			{
				sqInt object;
				double value;
				POP_OOP_TO(object);
            value = interpreterProxy->floatValueOf(object);        
				PUSH_FLOAT64(value);
			}				break;			case OPCODE_BOOLEANTOOOP32:			{
				int32_t value;
				sqInt object;
				POP_INT32_TO(value);
            object = value ? interpreterProxy->trueObject() : interpreterProxy->falseObject();        
				PUSH_OOP(object);
			}				break;			case OPCODE_SMALLINT32TOOOP:			{
				int32_t value;
				sqInt object;
				POP_INT32_TO(value);
            object = interpreterProxy->integerObjectOf(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_INT32TOOOP:			{
				int32_t value;
				sqInt object;
				POP_INT32_TO(value);
            object = interpreterProxy->signed32BitIntegerFor(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_UINT32TOOOP:			{
				int32_t value;
				sqInt object;
				POP_INT32_TO(value);
            object = interpreterProxy->positive32BitIntegerFor(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_INT64TOOOP:			{
				int64_t value;
				sqInt object;
				POP_INT64_TO(value);
            object = interpreterProxy->signed64BitIntegerFor(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_UINT64TOOOP:			{
				int64_t value;
				sqInt object;
				POP_INT64_TO(value);
            object = interpreterProxy->positive64BitIntegerFor(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_FLOAT32TOOOP:			{
				double value;
				sqInt object;
				POP_FLOAT64_TO(value);
            object = interpreterProxy->floatObjectOf(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_FLOAT64TOOOP:			{
				float value;
				sqInt object;
				POP_FLOAT32_TO(value);
            object = interpreterProxy->floatObjectOf(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_FIRSTFIELDPTR:			{
				sqInt object;
				void* pointer;
				POP_OOP_TO(object);
            pointer = interpreterProxy->firstFixedField(object);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_FIRSTINDEXPTR:			{
				sqInt object;
				void* pointer;
				POP_OOP_TO(object);
            pointer = interpreterProxy->firstIndexableField(object);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_COMPARE32:			{
				int32_t first;
				int32_t second;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            Lowcode_setConditionFlagsBySubtractingInteger32With(&currentConditionFlags, first, second);        
			}				break;			case OPCODE_COMPARE64:			{
				int64_t first;
				int64_t second;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            Lowcode_setConditionFlagsBySubtractingInteger64With(&currentConditionFlags, first, second);        
			}				break;			case OPCODE_FLOAT32COMPARE:			{
				float first;
				float second;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            Lowcode_setConditionFlagsBySubtractingFloat32With(&currentConditionFlags, first, second);        
			}				break;			case OPCODE_FLOAT64COMPARE:			{
				double first;
				double second;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            Lowcode_setConditionFlagsBySubtractingFloat64With(&currentConditionFlags, first, second);        
			}				break;			case OPCODE_TEST32:			{
				int32_t first;
				int32_t second;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            Lowcode_setConditionFlagsByAndingInteger32With(&currentConditionFlags, first, second);        
			}				break;			case OPCODE_TEST64:			{
				int64_t first;
				int64_t second;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            Lowcode_setConditionFlagsByAndingInteger64With(&currentConditionFlags, first, second);        
			}				break;			case OPCODE_JUMP:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            pc = dest;        
			}				break;			case OPCODE_BRANCHEQUAL:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_EQ, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHNOTEQUAL:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_NE, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHLESS:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_LT, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHLESSEQUAL:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_LE, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHGREATER:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_GT, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHGREATEQUAL:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_GE, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHUNSIGNEDLESS:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_ULT, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHUNSIGNEDLESSEQUAL:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_ULE, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHUNSIGNEDGREATER:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_GT, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHUNSIGNEDGREATEQUAL:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_UGE, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHOVERFLOW:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_OV, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHNOTOVERFLOW:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_NO, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHPRIMITIVEFAILED:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_PF, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_BRANCHPRIMITIVESUCCEED:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);
            if(Lowcode_isConditionSatisfiedByIn(LOWCODE_COND_PS, &currentConditionFlags, interpreterProxy))                pc = dest;        
			}				break;			case OPCODE_RETURNINT32:			{
				int32_t value;
				POP_INT32_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_RETURNINT64:			{
				int32_t value;
				POP_INT32_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_RETURNPOINTER:			{
				void* value;
				POP_POINTER_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_RETURNFLOAT32:			{
				float value;
				POP_FLOAT32_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_RETURNFLOAT64:			{
				double value;
				POP_FLOAT64_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_LOCKVM:			{
            /* TODO */        
			}				break;			case OPCODE_UNLOCKVM:			{
            /* TODO */        
			}				break;			case OPCODE_COMPAREANDSWAP32:			{
				void* check;
				int32_t newValue;
				int32_t oldValue;
				int32_t value;
				POP_INT32_TO(oldValue);
				POP_INT32_TO(newValue);
				POP_POINTER_TO(check);
            /* TODO */        
				PUSH_INT32(value);
			}				break;			case OPCODE_ALLOCA32:			{
				int32_t size;
				void* pointer;
				POP_INT32_TO(size);
            pointer = (uint8_t*)alloca(size);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_ALLOCA64:			{
				int64_t size;
				void* pointer;
				POP_INT64_TO(size);
            pointer = alloca(size);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_MALLOC32:			{
				int32_t size;
				void* pointer;
				POP_INT32_TO(size);
            pointer = malloc(size);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_MALLOC64:			{
				int64_t size;
				void* pointer;
				POP_INT64_TO(size);
            pointer = malloc(size);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_FREE:			{
				void* pointer;
				POP_POINTER_TO(pointer);
            free(pointer);        
			}				break;			case OPCODE_BEGINCALL:			{
				uint32_t alignment;
				alignment = extA;
            /* TODO: */        
			}				break;			case OPCODE_CALLARGUMENTINT32:			{
				int32_t value;
				POP_INT32_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_CALLARGUMENTINT64:			{
				int32_t value;
				POP_INT32_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_CALLARGUMENTFLOAT32:			{
				float value;
				POP_FLOAT32_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_CALLARGUMENTFLOAT64:			{
				double value;
				POP_FLOAT64_TO(value);
            /* TODO: */        
			}				break;			case OPCODE_PERFORMCALL:			{
				uint32_t function;
				function = extA;
            /* TODO: */        
			}				break;			case OPCODE_PERFORMCALLINDIRECT:			{
				void* function;
				POP_POINTER_TO(function);
            /* TODO: */        
			}				break;			case OPCODE_ENDCALL:			{
            /* TODO: */        
			}				break;			case OPCODE_ENDCALLNOCLEANUP:			{
            /* TODO: */        
			}				break;			case OPCODE_PLAFTORMCODE:			{
				int32_t code;
            /* TODO */        
				PUSH_INT32(code);
			}				break;			case OPCODE_LOCKREGISTERS:			{
            /* Cannot be done here */        
			}				break;			case OPCODE_UNLOCKREGISTERS:			{
            /* Cannot be done here */        
			}				break;			case OPCODE_MOVEINT32TOPHYSICAL:			{
				uint32_t registerID;
				int32_t value;
				registerID = extA;
				POP_INT32_TO(value);
            /* Cannot be done here */        
			}				break;			case OPCODE_MOVEINT64TOPHYSICAL:			{
				uint32_t registerID;
				int64_t value;
				registerID = extA;
				POP_INT64_TO(value);
            /* Cannot be done here */        
			}				break;			case OPCODE_MOVEPOINTERTOPHYSICAL:			{
				uint32_t registerID;
				void* value;
				registerID = extA;
				POP_POINTER_TO(value);
            /* Cannot be done here */        
			}				break;			case OPCODE_MOVEFLOAT32TOPHYSICAL:			{
				uint32_t registerID;
				float value;
				registerID = extA;
				POP_FLOAT32_TO(value);
            /* Cannot be done here */        
			}				break;			case OPCODE_MOVEFLOAT64TOPHYSICAL:			{
				uint32_t registerID;
				double value;
				registerID = extA;
				POP_FLOAT64_TO(value);
            /* Cannot be done here */        
			}				break;			case OPCODE_PUSHPHYSICALINT32:			{
				uint32_t registerID;
				int32_t value;
				registerID = extA;
            /* Cannot be done here */        
				PUSH_INT32(value);
			}				break;			case OPCODE_PUSHPHYSICALINT64:			{
				uint32_t registerID;
				int64_t value;
				registerID = extA;
            /* Cannot be done here */        
				PUSH_INT64(value);
			}				break;			case OPCODE_PUSHPHYSICALPOINTER:			{
				uint32_t registerID;
				void* value;
				registerID = extA;
            /* Cannot be done here */        
				PUSH_POINTER(value);
			}				break;			case OPCODE_PUSHPHYSICALFLOAT32:			{
				uint32_t registerID;
				float value;
				registerID = extA;
            /* Cannot be done here */        
				PUSH_FLOAT32(value);
			}				break;			case OPCODE_PUSHPHYSICALFLOAT64:			{
				uint32_t registerID;
				double value;
				registerID = extA;
            /* Cannot be done here */        
				PUSH_FLOAT64(value);
			}				break;			case OPCODE_CALLPHYSICAL:			{
				uint32_t registerID;
				registerID = extA;
            /* Cannot be done here */        
			}				break;			case OPCODE_CALLINSTRUCTION:			{
				uint32_t function;
				function = extA;
            /* Cannot be done here */        
			}				break;			default:				/* Unsupported inline primitive. */				return interpreterProxy->primitiveFail();			}		}	}	/* Should never reach here. */	abort();	return 0;}
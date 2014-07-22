/** * WARNING: This file was automatically generated. DO NOT MODIFY. */#include <stdlib.h>#include <stdio.h>#include <string.h>#include <math.h>#include <time.h>#include "LowcodeInterpreterPlugin.h"#include "LowcodeInterpreterPluginFFI.h"/* Sista bytecode decoding constants */#define SISTA_OPCODE_ONE_BYTE_LAST 223#define SISTA_OPCODE_TWO_BYTE_LAST 247#define SISTA_OPCODE_EXT_A 224#define SISTA_OPCODE_EXT_B 225/* Primitive types stack. */#define DEFAULT_PRIMITIVE_STACK_SIZE 256#define FATAL_ERROR(message) {  \		fprintf(stderr, "FATAL ERROR: " message " in %s at line %d\n", __FILE__, __LINE__); \		abort(); \}#define STACK_CHECK_REMAINING_CAPACITY(size) {\	if(primitiveStackCapacity - primitiveStackSize < size) \		FATAL_ERROR("Lowcode Primitive Stack Overflow"); \}#define STACK_CHECK_MINIMAL_SIZE(size) {\	if(primitiveStackSize < size)  \		FATAL_ERROR("Lowcode Primitive Stack Underflow"); \}#define PUSH_VALUE_OF_TYPE(x, type) {\	STACK_CHECK_REMAINING_CAPACITY(sizeof(type));\	*((type*)(primitiveStack + primitiveStackSize) )= x;\	primitiveStackSize += sizeof(type);\}#define PUSH_INT32(x) PUSH_VALUE_OF_TYPE(x, int32_t)#define PUSH_INT64(x) PUSH_VALUE_OF_TYPE(x, int64_t)#define PUSH_FLOAT32(x) PUSH_VALUE_OF_TYPE(x, float)#define PUSH_FLOAT64(x) PUSH_VALUE_OF_TYPE(x, double)#define PUSH_POINTER(x) PUSH_VALUE_OF_TYPE(x, void*)#define POP_VALUE_OF_TYPE(dest, type) { \	STACK_CHECK_MINIMAL_SIZE(sizeof(type)); \	primitiveStackSize -= sizeof(type); \	dest = *((type*)(primitiveStack + primitiveStackSize)); \}#define POP_INT32_TO(x) POP_VALUE_OF_TYPE(x, int32_t)#define POP_INT64_TO(x) POP_VALUE_OF_TYPE(x, int64_t)#define POP_FLOAT32_TO(x) POP_VALUE_OF_TYPE(x, float)#define POP_FLOAT64_TO(x) POP_VALUE_OF_TYPE(x, double)#define POP_POINTER_TO(x) POP_VALUE_OF_TYPE(x, void*)/* Oop macros */#define POP_OOP_TO(x) { \	x = interpreterProxy->stackValue(0); \	interpreterProxy->pop(1);  \	oopStackSize--; \}#define PUSH_OOP(x) { \	interpreterProxy->push(x); \	oopStackSize++; \}#define PUSH_OOP_INTEGER(x) { \	interpreterProxy->pushInteger(x); \	oopStackSize++; \}/* Special macros */#define LITERAL_AT_TO(id, dest) { \	dest = interpreterProxy->fetchPointerofObject(id, literals); \	CHECK_FAILED(); \}#define LABEL_AT_TO(id, dest) { \	sqInt literalOop; \	LITERAL_AT_TO(id, literalOop); \	dest = instructionStream + interpreterProxy->integerValueOf(literalOop); \}/* Utility macros */#define UNIMPLEMENTED() { \	fprintf(stderr, "Unimplemented Lowcode instruction at %s line %d\n", __FILE__, __LINE__); \	abort(); \}#define UNSUPPORTED() { \	fprintf(stderr, "Unimplemented Lowcode instruction at %s line %d\n", __FILE__, __LINE__); \	abort(); \}#define CHECK_FAILED() { \	if(interpreterProxy->failed()) \		return interpreterProxy->primitiveFail(); \}#define RETURN_OOP(oop) return interpreterProxy->popthenPush(oopStackSize, oop);
/* Lowcode instructions opcode constants */
#define OPCODE_DUPLICATEINT32 256
#define OPCODE_DUPLICATEINT64 257
#define OPCODE_DUPLICATEPOINTER 258
#define OPCODE_DUPLICATEFLOAT32 259
#define OPCODE_DUPLICATEFLOAT64 260
#define OPCODE_POPINT32 261
#define OPCODE_POPINT64 262
#define OPCODE_POPPOINTER 263
#define OPCODE_POPFLOAT32 264
#define OPCODE_POPFLOAT64 265
#define OPCODE_PUSHZERO32 266
#define OPCODE_PUSHONE32 267
#define OPCODE_PUSHZERO64 268
#define OPCODE_PUSHONE64 269
#define OPCODE_PUSHCONSTANTUINT32 270
#define OPCODE_PUSHCONSTANTUINT64 271
#define OPCODE_PUSHZEROFLOAT32 272
#define OPCODE_PUSHONEFLOAT32 273
#define OPCODE_PUSHZEROFLOAT64 274
#define OPCODE_PUSHONEFLOAT64 275
#define OPCODE_PUSHNULLPOINTER 276
#define OPCODE_PUSHSESSIONIDENTIFIER 277
#define OPCODE_CHECKSESSIONIDENTIFIER 278
#define OPCODE_POINTEROFFSET32 279
#define OPCODE_POINTEROFFSET64 280
#define OPCODE_EFFECTIVEADDRESS32 281
#define OPCODE_EFFECTIVEADDRESS64 282
#define OPCODE_LOADUINT8FROMMEMORY 283
#define OPCODE_LOADUINT16FROMMEMORY 284
#define OPCODE_LOADUINT32FROMMEMORY 285
#define OPCODE_LOADUINT64FROMMEMORY 286
#define OPCODE_LOADINT8FROMMEMORY 287
#define OPCODE_LOADINT16FROMMEMORY 288
#define OPCODE_LOADINT32FROMMEMORY 289
#define OPCODE_LOADINT64FROMMEMORY 290
#define OPCODE_LOADPOINTERFROMMEMORY 291
#define OPCODE_LOADFLOAT32FROMMEMORY 292
#define OPCODE_LOADFLOAT64FROMMEMORY 293
#define OPCODE_STOREINT8TOMEMORY 294
#define OPCODE_STOREINT16TOMEMORY 295
#define OPCODE_STOREINT32TOMEMORY 296
#define OPCODE_STOREINT64TOMEMORY 297
#define OPCODE_STOREPOINTERTOMEMORY 298
#define OPCODE_STOREFLOAT32TOMEMORY 299
#define OPCODE_STOREFLOAT64TOMEMORY 300
#define OPCODE_LOADLOCALADDRESS 301
#define OPCODE_LOADLOCALUINT8 302
#define OPCODE_LOADLOCALUINT16 303
#define OPCODE_LOADLOCALUINT32 304
#define OPCODE_LOADLOCALUINT64 305
#define OPCODE_LOADLOCALINT8 306
#define OPCODE_LOADLOCALINT16 307
#define OPCODE_LOADLOCALINT32 308
#define OPCODE_LOADLOCALINT64 309
#define OPCODE_LOADLOCALPOINTER 310
#define OPCODE_LOADLOCALFLOAT32 311
#define OPCODE_LOADLOCALFLOAT64 312
#define OPCODE_STORELOCALINT8 313
#define OPCODE_STORELOCALINT16 314
#define OPCODE_STORELOCALINT32 315
#define OPCODE_STORELOCALINT64 316
#define OPCODE_STORELOCALPOINTER 317
#define OPCODE_STORELOCALFLOAT32 318
#define OPCODE_STORELOCALFLOAT64 319
#define OPCODE_SIGNEXTEND32FROM8 320
#define OPCODE_SIGNEXTEND32FROM16 321
#define OPCODE_SIGNEXTEND64FROM8 322
#define OPCODE_SIGNEXTEND64FROM16 323
#define OPCODE_SIGNEXTEND64FROM32 324
#define OPCODE_ZEROEXTEND32FROM8 325
#define OPCODE_ZEROEXTEND32FROM16 326
#define OPCODE_ZEROEXTEND64FROM8 327
#define OPCODE_ZEROEXTEND64FROM16 328
#define OPCODE_ZEROEXTEND64FROM32 329
#define OPCODE_TRUNCATE32TO8 330
#define OPCODE_TRUNCATE32TO16 331
#define OPCODE_TRUNCATE64TO8 332
#define OPCODE_TRUNCATE64TO16 333
#define OPCODE_TRUNCATE64TO32 334
#define OPCODE_UINT32TOFLOAT32 335
#define OPCODE_UINT32TOFLOAT64 336
#define OPCODE_INT32TOFLOAT32 337
#define OPCODE_INT32TOFLOAT64 338
#define OPCODE_UINT64TOFLOAT32 339
#define OPCODE_UINT64TOFLOAT64 340
#define OPCODE_INT64TOFLOAT32 341
#define OPCODE_INT64TOFLOAT64 342
#define OPCODE_FLOAT32TOINT32 343
#define OPCODE_FLOAT64TOINT32 344
#define OPCODE_FLOAT32TOINT64 345
#define OPCODE_FLOAT64TOINT64 346
#define OPCODE_POINTERTOINT32 347
#define OPCODE_POINTERTOINT64 348
#define OPCODE_INT32TOPOINTER 349
#define OPCODE_INT64TOPOINTER 350
#define OPCODE_ADD32 351
#define OPCODE_SUB32 352
#define OPCODE_NEG32 353
#define OPCODE_MUL32 354
#define OPCODE_UMUL32 355
#define OPCODE_DIV32 356
#define OPCODE_UDIV32 357
#define OPCODE_REM32 358
#define OPCODE_UREM32 359
#define OPCODE_ADD64 360
#define OPCODE_SUB64 361
#define OPCODE_NEG64 362
#define OPCODE_MUL64 363
#define OPCODE_UMUL64 364
#define OPCODE_DIV64 365
#define OPCODE_UDIV64 366
#define OPCODE_REM64 367
#define OPCODE_UREM64 368
#define OPCODE_NOT32 369
#define OPCODE_AND32 370
#define OPCODE_OR32 371
#define OPCODE_XOR32 372
#define OPCODE_LEFTSHIFT32 373
#define OPCODE_RIGHTSHIFT32 374
#define OPCODE_ARITHMETICRIGHTSHIFT32 375
#define OPCODE_NOT64 376
#define OPCODE_AND64 377
#define OPCODE_OR64 378
#define OPCODE_XOR64 379
#define OPCODE_LEFTSHIFT64 380
#define OPCODE_RIGHTSHIFT64 381
#define OPCODE_ARITHMETICRIGHTSHIFT64 382
#define OPCODE_FLOAT32ADD 383
#define OPCODE_FLOAT32SUB 384
#define OPCODE_FLOAT32MUL 385
#define OPCODE_FLOAT32DIV 386
#define OPCODE_FLOAT64ADD 387
#define OPCODE_FLOAT64SUB 388
#define OPCODE_FLOAT64MUL 389
#define OPCODE_FLOAT64DIV 390
#define OPCODE_PIN 391
#define OPCODE_UNPIN 392
#define OPCODE_OOPTOPOINTER 393
#define OPCODE_OOPTOPOINTERREINTERPRET 394
#define OPCODE_POINTERTOOOP 395
#define OPCODE_POINTERTOOOPREINTERPRER 396
#define OPCODE_INSTANTIATEOOP 397
#define OPCODE_INSTANTIATEINDEXABLEOOP 398
#define OPCODE_INSTANTIATEINDEXABLE32OOP 399
#define OPCODE_OOPTOBOOLEAN32 400
#define OPCODE_OOPTOBOOLEAN64 401
#define OPCODE_OOPSMALLINTEGERTOINT32 402
#define OPCODE_OOPTOINT32 403
#define OPCODE_OOPTOUINT32 404
#define OPCODE_OOPSMALLINTEGERTOINT64 405
#define OPCODE_OOPTOINT64 406
#define OPCODE_OOPTOUINT64 407
#define OPCODE_OOPTOFLOAT32 408
#define OPCODE_OOPTOFLOAT64 409
#define OPCODE_BOOLEAN32TOOOP 410
#define OPCODE_BOOLEAN64TOOOP 411
#define OPCODE_SMALLINT32TOOOP 412
#define OPCODE_INT32TOOOP 413
#define OPCODE_UINT32TOOOP 414
#define OPCODE_INT64TOOOP 415
#define OPCODE_UINT64TOOOP 416
#define OPCODE_FLOAT32TOOOP 417
#define OPCODE_FLOAT64TOOOP 418
#define OPCODE_LOADOBJECTFIELD 419
#define OPCODE_STOREOBJECTFIELD 420
#define OPCODE_LOADOBJECTAT 421
#define OPCODE_STOREOBJECTFIELDAT 422
#define OPCODE_FIRSTFIELDPOINTER 423
#define OPCODE_FIRSTINDEXABLEFIELDPOINTER 424
#define OPCODE_BYTESIZEOF 425
#define OPCODE_ISBYTES 426
#define OPCODE_ISFLOATOBJECT 427
#define OPCODE_ISINDEXABLE 428
#define OPCODE_ISINTEGEROBJECT 429
#define OPCODE_ISWORDS 430
#define OPCODE_ISWORDSORBYTES 431
#define OPCODE_ISPOINTERS 432
#define OPCODE_POINTEREQUAL 433
#define OPCODE_POINTERNOTEQUAL 434
#define OPCODE_OOPEQUAL 435
#define OPCODE_OOPNOTEQUAL 436
#define OPCODE_INT32EQUAL 437
#define OPCODE_INT32NOTEQUAL 438
#define OPCODE_INT32LESS 439
#define OPCODE_INT32LESSEQUAL 440
#define OPCODE_INT32GREAT 441
#define OPCODE_INT32GREATEQUAL 442
#define OPCODE_UINT32LESS 443
#define OPCODE_UINT32LESSEQUAL 444
#define OPCODE_UINT32GREAT 445
#define OPCODE_UINT32GREATEQUAL 446
#define OPCODE_INT64EQUAL 447
#define OPCODE_INT64NOTEQUAL 448
#define OPCODE_INT64LESS 449
#define OPCODE_INT64LESSEQUAL 450
#define OPCODE_INT64GREAT 451
#define OPCODE_INT64GREATEQUAL 452
#define OPCODE_UINT64LESS 453
#define OPCODE_UINT64LESSEQUAL 454
#define OPCODE_UINT64GREAT 455
#define OPCODE_UINT64GREATEQUAL 456
#define OPCODE_FLOAT32EQUAL 457
#define OPCODE_FLOAT32NOTEQUAL 458
#define OPCODE_FLOAT32LESS 459
#define OPCODE_FLOAT32LESSEQUAL 460
#define OPCODE_FLOAT32GREAT 461
#define OPCODE_FLOAT32GREATEQUAL 462
#define OPCODE_FLOAT64EQUAL 463
#define OPCODE_FLOAT64NOTEQUAL 464
#define OPCODE_FLOAT64LESS 465
#define OPCODE_FLOAT64LESSEQUAL 466
#define OPCODE_FLOAT64GREAT 467
#define OPCODE_FLOAT64GREATEQUAL 468
#define OPCODE_JUMP 469
#define OPCODE_BRANCHTRUE32 470
#define OPCODE_BRANCHFALSE32 471
#define OPCODE_BRANCHTRUE64 472
#define OPCODE_BRANCHFALSE64 473
#define OPCODE_RETURNSMALLINTEGER 478
#define OPCODE_RETURNBOOLEAN32ASOOP 479
#define OPCODE_RETURNBOOLEAN64ASOOP 480
#define OPCODE_RETURNINT32ASOOP 481
#define OPCODE_RETURNINT64ASOOP 482
#define OPCODE_RETURNUINT32ASOOP 483
#define OPCODE_RETURNUINT64ASOOP 484
#define OPCODE_RETURNPOINTERASOOP 485
#define OPCODE_RETURNFLOAT32ASOOP 486
#define OPCODE_RETURNFLOAT64ASOOP 487
#define OPCODE_FAIL 488
#define OPCODE_FAILWITHCODE 489
#define OPCODE_LOCKVM 490
#define OPCODE_UNLOCKVM 491
#define OPCODE_COMPAREANDSWAP32 492
#define OPCODE_ALLOCA32 493
#define OPCODE_ALLOCA64 494
#define OPCODE_MALLOC32 495
#define OPCODE_MALLOC64 496
#define OPCODE_FREE 497
#define OPCODE_MEMCPYFIXED 498
#define OPCODE_MEMCPY32 499
#define OPCODE_MEMCPY64 500
#define OPCODE_BEGINCALL 501
#define OPCODE_CALLARGUMENTINT32 502
#define OPCODE_CALLARGUMENTINT64 503
#define OPCODE_CALLARGUMENTPOINTER 504
#define OPCODE_CALLARGUMENTSTRUCTURE 505
#define OPCODE_CALLARGUMENTFLOAT32 506
#define OPCODE_CALLARGUMENTFLOAT64 507
#define OPCODE_PERFORMCALLINT32 508
#define OPCODE_PERFORMCALLINT64 509
#define OPCODE_PERFORMCALLPOINTER 510
#define OPCODE_PERFORMCALLFLOAT32 511
#define OPCODE_PERFORMCALLFLOAT64 512
#define OPCODE_PERFORMCALLINDIRECTINT32 513
#define OPCODE_PERFORMCALLINDIRECTINT64 514
#define OPCODE_PERFORMCALLINDIRECTPOINTER 515
#define OPCODE_PERFORMCALLINDIRECTFLOAT32 516
#define OPCODE_PERFORMCALLINDIRECTFLOAT64 517
#define OPCODE_ENDCALL 518
#define OPCODE_ENDCALLNOCLEANUP 519
#define OPCODE_PLAFTORMCODE 520
#define OPCODE_LOCKREGISTERS 521
#define OPCODE_UNLOCKREGISTERS 522
#define OPCODE_MOVEINT32TOPHYSICAL 523
#define OPCODE_MOVEINT64TOPHYSICAL 524
#define OPCODE_MOVEPOINTERTOPHYSICAL 525
#define OPCODE_MOVEFLOAT32TOPHYSICAL 526
#define OPCODE_MOVEFLOAT64TOPHYSICAL 527
#define OPCODE_PUSHPHYSICALINT32 528
#define OPCODE_PUSHPHYSICALINT64 529
#define OPCODE_PUSHPHYSICALPOINTER 530
#define OPCODE_PUSHPHYSICALFLOAT32 531
#define OPCODE_PUSHPHYSICALFLOAT64 532
#define OPCODE_CALLPHYSICAL 533
#define OPCODE_CALLINSTRUCTION 534
static int Lowcode_sessionInitialized = 0;static uint32_t Lowcode_sessionIdentifier; /* Must be keep uninitialized for more randomness */static void Lowcode_initializeSession() { 	uint32_t *p = (uint32_t*)malloc(4);	/* Produce a random value for the session identifier */	Lowcode_sessionIdentifier ^= ((uint32_t)((size_t)p)) ^ (uint32_t)time(NULL) ^ *p;	free(p);	Lowcode_sessionInitialized = 1;}	sqInt LowcodePlugin_InterpretCodeLiteralsReceiverTemporalsStackFrame(VirtualMachine *interpreterProxy, uint8_t *instructionStream, sqInt literals, sqInt receiver, sqInt temporals, int stackFrameSize){	/* Allocate space for the primitive stack */	char* primitiveStack = (char*)alloca(DEFAULT_PRIMITIVE_STACK_SIZE);	size_t primitiveStackCapacity = DEFAULT_PRIMITIVE_STACK_SIZE;	size_t primitiveStackSize = 0;		/* Allocate space for the stack frame base. */	char* basePointer = (char*)alloca(stackFrameSize);	/* Oop stack tracking */	size_t oopStackSize = interpreterProxy->methodArgumentCount() + 1;		/* Some counts */	size_t numberLiterals = interpreterProxy->stSizeOf(literals);	size_t numberOfTemporals = interpreterProxy->stSizeOf(temporals);	/* The current program counter. */	uint8_t *pc = instructionStream;	uint32_t extA = 0;	uint32_t extB = 0;		/* For calling*/	LOWCODE_FFI_COMMON();		/* Execute all the instructions without verification */	for(;;)	{		/* Fetch the first Sista extended bytecode opcode. */		uint8_t sistaOpcode = *(pc++);		/* Sista instructions are variable sized */		if(sistaOpcode <= SISTA_OPCODE_ONE_BYTE_LAST)		{			switch(sistaOpcode)			{
			/* 'pushReceiverVariableSmallIndex'*/
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
            PUSH_OOP(interpreterProxy->fetchPointerofObject(sistaOpcode & 15, receiver));        
			}				break;
			/* 'pushLiteralVariableSmallIndex'*/
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
            UNIMPLEMENTED();        
			}				break;
			/* 'pushLiteralSmallIndex'*/
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
            PUSH_OOP(interpreterProxy->fetchPointerofObject(sistaOpcode & 31, literals));        
			}				break;
			/* 'pushTempSmallIndex'*/
			case 64:
			case 65:
			case 66:
			case 67:
			case 68:
			case 69:
			case 70:
			case 71:
			{
            PUSH_OOP(interpreterProxy->fetchPointerofObject(sistaOpcode & 7, temporals));        
			}				break;
			/* 'pushTempSmallIndex2'*/
			case 72:
			case 73:
			case 74:
			case 75:
			{
            PUSH_OOP(interpreterProxy->fetchPointerofObject((sistaOpcode & 3) + 8, temporals));        
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
            UNSUPPORTED();        
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
			/* 'sendSpecialMessageClass'*/
			case 119:
			{
            sqInt object;            sqInt classObject;            POP_OOP_TO(object);            classObject = interpreterProxy->fetchClassOf(object);            CHECK_FAILED();            PUSH_OOP(classObject);        
			}				break;
			/* 'popAndStoreTemp'*/
			case 208:
			case 209:
			case 210:
			case 211:
			case 212:
			case 213:
			case 214:
			case 215:
			{
            sqInt value;            POP_OOP_TO(value);            interpreterProxy->storePointerofObjectwithValue(sistaOpcode & 7, temporals, value);            CHECK_FAILED();        
			}				break;
			/* 'popStackTop'*/
			case 216:
			{
            sqInt dummy;            POP_OOP_TO(dummy);        
			}				break;
			default:				return interpreterProxy->primitiveFail();			}		}		else if(sistaOpcode <= SISTA_OPCODE_TWO_BYTE_LAST)		{			/* Read the extension values. */			if(sistaOpcode == SISTA_OPCODE_EXT_A)			{				extA  = extA*256 + (*(pc++));			}			else if(sistaOpcode == SISTA_OPCODE_EXT_B)			{				extB  = extB*256 + (*(pc++)); 			}			else			{ 				/* TODO: Wait for Christmas */ 				return interpreterProxy->primitiveFail(); /* Unsupported here. */			}		}		else		{			/* Only interested in line primitives */ 			if(sistaOpcode != 248)				return interpreterProxy->primitiveFail(); /* Unsupported here. */			/* Decode the inline primitive opcode. */			uint16_t opcode = (*pc++);			opcode |=(*pc++) << 8;			/* Ensure it is a inline primitive. */			if((opcode & (1<<15)) == 0)				return interpreterProxy->primitiveFail(); /* Unsupported here. */			opcode &= ~(1<<15);			/* Fetch the instruction OpCode */			switch(opcode)			{
			case OPCODE_DUPLICATEINT32:			{
				int32_t value;
				int32_t dup1;
				int32_t dup2;
				POP_INT32_TO(value);
            dup1 = value;            dup2 = value;        
				PUSH_INT32(dup1);
				PUSH_INT32(dup2);
			}				break;			case OPCODE_DUPLICATEINT64:			{
				int64_t value;
				int64_t dup1;
				int64_t dup2;
				POP_INT64_TO(value);
            dup1 = value;            dup2 = value;        
				PUSH_INT64(dup1);
				PUSH_INT64(dup2);
			}				break;			case OPCODE_DUPLICATEPOINTER:			{
				void* value;
				void* dup1;
				void* dup2;
				POP_POINTER_TO(value);
            dup1 = value;            dup2 = value;        
				PUSH_POINTER(dup1);
				PUSH_POINTER(dup2);
			}				break;			case OPCODE_DUPLICATEFLOAT32:			{
				float value;
				float dup1;
				float dup2;
				POP_FLOAT32_TO(value);
            dup1 = value;            dup2 = value;        
				PUSH_FLOAT32(dup1);
				PUSH_FLOAT32(dup2);
			}				break;			case OPCODE_DUPLICATEFLOAT64:			{
				double value;
				double dup1;
				double dup2;
				POP_FLOAT64_TO(value);
            dup1 = value;            dup2 = value;        
				PUSH_FLOAT64(dup1);
				PUSH_FLOAT64(dup2);
			}				break;			case OPCODE_POPINT32:			{
				int32_t value;
				POP_INT32_TO(value);

			}				break;			case OPCODE_POPINT64:			{
				int64_t value;
				POP_INT64_TO(value);

			}				break;			case OPCODE_POPPOINTER:			{
				void* value;
				POP_POINTER_TO(value);

			}				break;			case OPCODE_POPFLOAT32:			{
				float value;
				POP_FLOAT32_TO(value);

			}				break;			case OPCODE_POPFLOAT64:			{
				double value;
				POP_FLOAT64_TO(value);

			}				break;			case OPCODE_PUSHZERO32:			{
				int32_t result;
            result = 0;        
				PUSH_INT32(result);
			}				break;			case OPCODE_PUSHONE32:			{
				int32_t result;
            result = 1;        
				PUSH_INT32(result);
			}				break;			case OPCODE_PUSHZERO64:			{
				int64_t result;
            result = 0;        
				PUSH_INT64(result);
			}				break;			case OPCODE_PUSHONE64:			{
				int64_t result;
            result = 1;        
				PUSH_INT64(result);
			}				break;			case OPCODE_PUSHCONSTANTUINT32:			{
				uint32_t constant;
				int32_t result;
				constant = extA;
				extA = 0;
            result = constant;        
				PUSH_INT32(result);
			}				break;			case OPCODE_PUSHCONSTANTUINT64:			{
				uint32_t constant;
				int64_t result;
				constant = extA;
				extA = 0;
            result = constant;        
				PUSH_INT64(result);
			}				break;			case OPCODE_PUSHZEROFLOAT32:			{
				float result;
            result = 0;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_PUSHONEFLOAT32:			{
				float result;
            result = 1;        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_PUSHZEROFLOAT64:			{
				double result;
            result = 0;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_PUSHONEFLOAT64:			{
				double result;
            result = 1;        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_PUSHNULLPOINTER:			{
				void* result;
            result = 0;        
				PUSH_POINTER(result);
			}				break;			case OPCODE_PUSHSESSIONIDENTIFIER:			{
				int32_t value;
            if(!Lowcode_sessionInitialized)                Lowcode_initializeSession();            value = Lowcode_sessionIdentifier;        
				PUSH_INT32(value);
			}				break;			case OPCODE_CHECKSESSIONIDENTIFIER:			{
				uint32_t expectedSession;
				int32_t value;
				expectedSession = extA;
				extA = 0;
            if(!Lowcode_sessionInitialized)                Lowcode_initializeSession();            value = expectedSession == Lowcode_sessionIdentifier;        
				PUSH_INT32(value);
			}				break;			case OPCODE_POINTEROFFSET32:			{
				void* base;
				int32_t offset;
				void* result;
				POP_INT32_TO(offset);
				POP_POINTER_TO(base);
            result = ((char*)base) + offset;        
				PUSH_POINTER(result);
			}				break;			case OPCODE_POINTEROFFSET64:			{
				void* base;
				int64_t offset;
				void* result;
				POP_INT64_TO(offset);
				POP_POINTER_TO(base);
            result = ((char*)base) + offset;        
				PUSH_POINTER(result);
			}				break;			case OPCODE_EFFECTIVEADDRESS32:			{
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
			}				break;			case OPCODE_EFFECTIVEADDRESS64:			{
				void* base;
				int64_t index;
				int64_t scale;
				int64_t offset;
				void* result;
				POP_INT64_TO(offset);
				POP_INT64_TO(scale);
				POP_INT64_TO(index);
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
				int64_t value;
				POP_POINTER_TO(pointer);
            value = *((int64_t*)pointer);        
				PUSH_INT64(value);
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
			}				break;			case OPCODE_LOADLOCALADDRESS:			{
				uint32_t baseOffset;
				void* pointer;
				baseOffset = extA;
				extA = 0;
            pointer = basePointer + baseOffset;        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_LOADLOCALUINT8:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
            value = (uint32_t)*((uint8_t*)(basePointer + baseOffset));        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADLOCALUINT16:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
            value = (uint32_t)*((uint16_t*)(basePointer + baseOffset));        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADLOCALUINT32:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
            value = (uint32_t)*((uint32_t*)(basePointer + baseOffset));        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADLOCALUINT64:			{
				uint32_t baseOffset;
				int64_t value;
				baseOffset = extA;
				extA = 0;
            value = (uint64_t)*((uint64_t*)(basePointer + baseOffset));        
				PUSH_INT64(value);
			}				break;			case OPCODE_LOADLOCALINT8:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
            value = (int32_t)*((int8_t*)(basePointer + baseOffset));        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADLOCALINT16:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
            value = (int32_t)*((int16_t*)(basePointer + baseOffset));        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADLOCALINT32:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
            value = (int32_t)*((int32_t*)(basePointer + baseOffset));        
				PUSH_INT32(value);
			}				break;			case OPCODE_LOADLOCALINT64:			{
				uint32_t baseOffset;
				int64_t value;
				baseOffset = extA;
				extA = 0;
            value = (int64_t)*((int64_t*)(basePointer + baseOffset));        
				PUSH_INT64(value);
			}				break;			case OPCODE_LOADLOCALPOINTER:			{
				uint32_t baseOffset;
				void* value;
				baseOffset = extA;
				extA = 0;
            value = (void*)*((void**)(basePointer + baseOffset));        
				PUSH_POINTER(value);
			}				break;			case OPCODE_LOADLOCALFLOAT32:			{
				uint32_t baseOffset;
				float value;
				baseOffset = extA;
				extA = 0;
            value = *((float*)(basePointer + baseOffset));        
				PUSH_FLOAT32(value);
			}				break;			case OPCODE_LOADLOCALFLOAT64:			{
				uint32_t baseOffset;
				double value;
				baseOffset = extA;
				extA = 0;
            value = *((double*)(basePointer + baseOffset));        
				PUSH_FLOAT64(value);
			}				break;			case OPCODE_STORELOCALINT8:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
				POP_INT32_TO(value);
            *((int8_t*)(basePointer + baseOffset)) = value;        
			}				break;			case OPCODE_STORELOCALINT16:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
				POP_INT32_TO(value);
            *((int16_t*)(basePointer + baseOffset)) = value;        
			}				break;			case OPCODE_STORELOCALINT32:			{
				uint32_t baseOffset;
				int32_t value;
				baseOffset = extA;
				extA = 0;
				POP_INT32_TO(value);
            *((int32_t*)(basePointer + baseOffset)) = value;        
			}				break;			case OPCODE_STORELOCALINT64:			{
				uint32_t baseOffset;
				int64_t value;
				baseOffset = extA;
				extA = 0;
				POP_INT64_TO(value);
            *((int64_t*)(basePointer + baseOffset)) = value;        
			}				break;			case OPCODE_STORELOCALPOINTER:			{
				uint32_t baseOffset;
				void* value;
				baseOffset = extA;
				extA = 0;
				POP_POINTER_TO(value);
            *((void**)(basePointer + baseOffset)) = value;        
			}				break;			case OPCODE_STORELOCALFLOAT32:			{
				uint32_t baseOffset;
				float value;
				baseOffset = extA;
				extA = 0;
				POP_FLOAT32_TO(value);
            *((float*)(basePointer + baseOffset)) = value;        
			}				break;			case OPCODE_STORELOCALFLOAT64:			{
				uint32_t baseOffset;
				double value;
				baseOffset = extA;
				extA = 0;
				POP_FLOAT64_TO(value);
            *((double*)(basePointer + baseOffset)) = value;        
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
			}				break;			case OPCODE_POINTERTOINT32:			{
				void* pointer;
				int32_t result;
				POP_POINTER_TO(pointer);
            result = (int32_t)((uintptr_t)pointer);        
				PUSH_INT32(result);
			}				break;			case OPCODE_POINTERTOINT64:			{
				void* pointer;
				int64_t result;
				POP_POINTER_TO(pointer);
            result = (int64_t)((uintptr_t)pointer);        
				PUSH_INT64(result);
			}				break;			case OPCODE_INT32TOPOINTER:			{
				int32_t value;
				void* result;
				POP_INT32_TO(value);
            result = (void*)(uintptr_t)value;        
				PUSH_POINTER(result);
			}				break;			case OPCODE_INT64TOPOINTER:			{
				int64_t value;
				void* result;
				POP_INT64_TO(value);
            result = (void*)(uintptr_t)value;        
				PUSH_POINTER(result);
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
			}				break;			case OPCODE_NEG32:			{
				int32_t value;
				int32_t result;
				POP_INT32_TO(value);
            result = -value;        
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
			}				break;			case OPCODE_NEG64:			{
				int64_t value;
				int64_t result;
				POP_INT64_TO(value);
            result = -value;        
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
            pointer = *((void**)interpreterProxy->firstIndexableField(object));        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_OOPTOPOINTERREINTERPRET:			{
				sqInt object;
				void* pointer;
				POP_OOP_TO(object);
            pointer = (void*)object;        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_POINTERTOOOP:			{
				sqInt pointerClassLiteral;
				void* pointer;
				sqInt object;
				LITERAL_AT_TO(extA, pointerClassLiteral);				extA = 0;
				POP_POINTER_TO(pointer);
            object = interpreterProxy->instantiateClassindexableSize(pointerClassLiteral, sizeof(void*));            CHECK_FAILED();            *((void**)interpreterProxy->firstIndexableField(object)) = pointer;        
				PUSH_OOP(object);
			}				break;			case OPCODE_POINTERTOOOPREINTERPRER:			{
				void* pointer;
				sqInt object;
				POP_POINTER_TO(pointer);
            object = (sqInt)pointer;        
				PUSH_OOP(object);
			}				break;			case OPCODE_INSTANTIATEOOP:			{
				sqInt classOop;
				sqInt object;
				POP_OOP_TO(classOop);
            object = instantiateClassindexableSize(classOop, 0);        
				PUSH_OOP(object);
			}				break;			case OPCODE_INSTANTIATEINDEXABLEOOP:			{
				uint32_t indexableSize;
				sqInt classOop;
				sqInt object;
				indexableSize = extA;
				extA = 0;
				POP_OOP_TO(classOop);
            object = instantiateClassindexableSize(classOop, indexableSize);        
				PUSH_OOP(object);
			}				break;			case OPCODE_INSTANTIATEINDEXABLE32OOP:			{
				sqInt classOop;
				int32_t indexableSize;
				sqInt object;
				POP_INT32_TO(indexableSize);
				POP_OOP_TO(classOop);
            object = instantiateClassindexableSize(classOop, indexableSize);        
				PUSH_OOP(object);
			}				break;			case OPCODE_OOPTOBOOLEAN32:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->booleanValueOf(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPTOBOOLEAN64:			{
				sqInt object;
				int64_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->booleanValueOf(object);        
				PUSH_INT64(value);
			}				break;			case OPCODE_OOPSMALLINTEGERTOINT32:			{
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
			}				break;			case OPCODE_BOOLEAN32TOOOP:			{
				int32_t value;
				sqInt object;
				POP_INT32_TO(value);
            object = value ? interpreterProxy->trueObject() : interpreterProxy->falseObject();        
				PUSH_OOP(object);
			}				break;			case OPCODE_BOOLEAN64TOOOP:			{
				int64_t value;
				sqInt object;
				POP_INT64_TO(value);
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
				float value;
				sqInt object;
				POP_FLOAT32_TO(value);
            object = interpreterProxy->floatObjectOf(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_FLOAT64TOOOP:			{
				double value;
				sqInt object;
				POP_FLOAT64_TO(value);
            object = interpreterProxy->floatObjectOf(value);        
				PUSH_OOP(object);
			}				break;			case OPCODE_LOADOBJECTFIELD:			{
				uint32_t fieldIndex;
				sqInt object;
				sqInt field;
				fieldIndex = extA;
				extA = 0;
				POP_OOP_TO(object);
            field = interpreterProxy->fetchPointerofObject(fieldIndex, object);        
				PUSH_OOP(field);
			}				break;			case OPCODE_STOREOBJECTFIELD:			{
				uint32_t fieldIndex;
				sqInt object;
				sqInt value;
				fieldIndex = extA;
				extA = 0;
				POP_OOP_TO(value);
				POP_OOP_TO(object);
            interpreterProxy->storePointerofObjectwithValue(fieldIndex, object, value);        
			}				break;			case OPCODE_LOADOBJECTAT:			{
				sqInt object;
				int32_t fieldIndex;
				sqInt field;
				POP_INT32_TO(fieldIndex);
				POP_OOP_TO(object);
            field = interpreterProxy->fetchPointerofObject(fieldIndex, object);        
				PUSH_OOP(field);
			}				break;			case OPCODE_STOREOBJECTFIELDAT:			{
				sqInt object;
				int32_t fieldIndex;
				sqInt value;
				POP_OOP_TO(value);
				POP_INT32_TO(fieldIndex);
				POP_OOP_TO(object);
            interpreterProxy->storePointerofObjectwithValue(fieldIndex, object, value);        
			}				break;			case OPCODE_FIRSTFIELDPOINTER:			{
				sqInt object;
				void* pointer;
				POP_OOP_TO(object);
            pointer = interpreterProxy->firstFixedField(object);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_FIRSTINDEXABLEFIELDPOINTER:			{
				sqInt object;
				void* pointer;
				POP_OOP_TO(object);
            pointer = interpreterProxy->firstIndexableField(object);        
				PUSH_POINTER(pointer);
			}				break;			case OPCODE_BYTESIZEOF:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->byteSizeOf(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISBYTES:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isBytes(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISFLOATOBJECT:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isFloatObject(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISINDEXABLE:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isIndexable(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISINTEGEROBJECT:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isIntegerObject(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISWORDS:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isWords(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISWORDSORBYTES:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isWordsOrBytes(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_ISPOINTERS:			{
				sqInt object;
				int32_t value;
				POP_OOP_TO(object);
            value = interpreterProxy->isPointers(object);        
				PUSH_INT32(value);
			}				break;			case OPCODE_POINTEREQUAL:			{
				void* first;
				void* second;
				int32_t value;
				POP_POINTER_TO(second);
				POP_POINTER_TO(first);
            value = first == second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_POINTERNOTEQUAL:			{
				void* first;
				void* second;
				int32_t value;
				POP_POINTER_TO(second);
				POP_POINTER_TO(first);
            value = first != second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPEQUAL:			{
				sqInt first;
				sqInt second;
				int32_t value;
				POP_OOP_TO(second);
				POP_OOP_TO(first);
            value = first == second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_OOPNOTEQUAL:			{
				sqInt first;
				sqInt second;
				int32_t value;
				POP_OOP_TO(second);
				POP_OOP_TO(first);
            value = first != second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT32EQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first == second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT32NOTEQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first != second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT32LESS:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first < second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT32LESSEQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first <= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT32GREAT:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first > second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT32GREATEQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first >= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT32LESS:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = ((uint32_t)first) < ((uint32_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT32LESSEQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = ((uint32_t)first) <= ((uint32_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT32GREAT:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = ((uint32_t)first) > ((uint32_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT32GREATEQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = ((uint32_t)first) >= ((uint32_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_INT64EQUAL:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = first == second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT64NOTEQUAL:			{
				int32_t first;
				int32_t second;
				int32_t value;
				POP_INT32_TO(second);
				POP_INT32_TO(first);
            value = first != second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT64LESS:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = first < second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT64LESSEQUAL:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = first <= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT64GREAT:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = first > second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_INT64GREATEQUAL:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = first >= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT64LESS:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = ((uint64_t)first) < ((uint64_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT64LESSEQUAL:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = ((uint64_t)first) <= ((uint64_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT64GREAT:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = ((uint64_t)first) > ((uint64_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_UINT64GREATEQUAL:			{
				int64_t first;
				int64_t second;
				int32_t value;
				POP_INT64_TO(second);
				POP_INT64_TO(first);
            value = ((uint64_t)first) >= ((uint64_t)second);        
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT32EQUAL:			{
				float first;
				float second;
				int32_t value;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            value = first == second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT32NOTEQUAL:			{
				float first;
				float second;
				int32_t value;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            value = first != second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT32LESS:			{
				float first;
				float second;
				int32_t value;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            value = first < second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT32LESSEQUAL:			{
				float first;
				float second;
				int32_t value;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            value = first <= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT32GREAT:			{
				float first;
				float second;
				int32_t value;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            value = first > second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT32GREATEQUAL:			{
				float first;
				float second;
				int32_t value;
				POP_FLOAT32_TO(second);
				POP_FLOAT32_TO(first);
            value = first >= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT64EQUAL:			{
				double first;
				double second;
				int32_t value;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            value = first == second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT64NOTEQUAL:			{
				double first;
				double second;
				int32_t value;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            value = first != second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT64LESS:			{
				double first;
				double second;
				int32_t value;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            value = first < second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT64LESSEQUAL:			{
				double first;
				double second;
				int32_t value;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            value = first <= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT64GREAT:			{
				double first;
				double second;
				int32_t value;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            value = first > second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_FLOAT64GREATEQUAL:			{
				double first;
				double second;
				int32_t value;
				POP_FLOAT64_TO(second);
				POP_FLOAT64_TO(first);
            value = first >= second;         
				PUSH_INT32(value);
			}				break;			case OPCODE_JUMP:			{
				uint8_t* dest;
				LABEL_AT_TO(extA, dest);				extA = 0;
            pc = dest;        
			}				break;			case OPCODE_BRANCHTRUE32:			{
				uint8_t* dest;
				int32_t cond;
				LABEL_AT_TO(extA, dest);				extA = 0;
				POP_INT32_TO(cond);
            if(cond)                pc = dest;        
			}				break;			case OPCODE_BRANCHFALSE32:			{
				uint8_t* dest;
				int32_t cond;
				LABEL_AT_TO(extA, dest);				extA = 0;
				POP_INT32_TO(cond);
            if(!cond)                pc = dest;        
			}				break;			case OPCODE_BRANCHTRUE64:			{
				uint8_t* dest;
				int64_t cond;
				LABEL_AT_TO(extA, dest);				extA = 0;
				POP_INT64_TO(cond);
            if(cond)                pc = dest;        
			}				break;			case OPCODE_BRANCHFALSE64:			{
				uint8_t* dest;
				int32_t cond;
				LABEL_AT_TO(extA, dest);				extA = 0;
				POP_INT32_TO(cond);
            if(!cond)                pc = dest;        
			}				break;			case OPCODE_RETURNSMALLINTEGER:			{
				int32_t value;
				POP_INT32_TO(value);
            RETURN_OOP(interpreterProxy->integerObjectOf(value));        
			}				break;			case OPCODE_RETURNBOOLEAN32ASOOP:			{
				int32_t value;
				POP_INT32_TO(value);
            RETURN_OOP(value ? interpreterProxy->trueObject() : interpreterProxy->falseObject());        
			}				break;			case OPCODE_RETURNBOOLEAN64ASOOP:			{
				int64_t value;
				POP_INT64_TO(value);
            RETURN_OOP(value ? interpreterProxy->trueObject() : interpreterProxy->falseObject());        
			}				break;			case OPCODE_RETURNINT32ASOOP:			{
				int32_t value;
				POP_INT32_TO(value);
            RETURN_OOP(interpreterProxy->signed32BitIntegerFor(value));        
			}				break;			case OPCODE_RETURNINT64ASOOP:			{
				int64_t value;
				POP_INT64_TO(value);
            RETURN_OOP(interpreterProxy->signed64BitIntegerFor(value));        
			}				break;			case OPCODE_RETURNUINT32ASOOP:			{
				int32_t value;
				POP_INT32_TO(value);
            RETURN_OOP(interpreterProxy->positive32BitIntegerFor(value));        
			}				break;			case OPCODE_RETURNUINT64ASOOP:			{
				int64_t value;
				POP_INT64_TO(value);
            RETURN_OOP(interpreterProxy->positive64BitIntegerFor(value));        
			}				break;			case OPCODE_RETURNPOINTERASOOP:			{
				sqInt pointerClassLiteral;
				void* pointer;
				LITERAL_AT_TO(extA, pointerClassLiteral);				extA = 0;
				POP_POINTER_TO(pointer);
            {                sqInt object = interpreterProxy->instantiateClassindexableSize(pointerClassLiteral, sizeof(void*));                CHECK_FAILED();                *((void**)interpreterProxy->firstIndexableField(object)) = pointer;                RETURN_OOP(object);            }        
			}				break;			case OPCODE_RETURNFLOAT32ASOOP:			{
				float value;
				POP_FLOAT32_TO(value);
            RETURN_OOP(interpreterProxy->floatObjectOf(value));        
			}				break;			case OPCODE_RETURNFLOAT64ASOOP:			{
				double value;
				POP_FLOAT64_TO(value);
            RETURN_OOP(interpreterProxy->floatObjectOf(value));        
			}				break;			case OPCODE_FAIL:			{
            return interpreterProxy->primitiveFail();        
			}				break;			case OPCODE_FAILWITHCODE:			{
				uint32_t errorCode;
				errorCode = extA;
				extA = 0;
            return interpreterProxy->primitiveFailFor(errorCode);        
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
            UNIMPLEMENTED();        
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
			}				break;			case OPCODE_MEMCPYFIXED:			{
				uint32_t size;
				void* dest;
				void* source;
				size = extA;
				extA = 0;
				POP_POINTER_TO(source);
				POP_POINTER_TO(dest);
            memcpy(dest, source, size);        
			}				break;			case OPCODE_MEMCPY32:			{
				void* dest;
				void* source;
				int32_t size;
				POP_INT32_TO(size);
				POP_POINTER_TO(source);
				POP_POINTER_TO(dest);
            memcpy(dest, source, size);        
			}				break;			case OPCODE_MEMCPY64:			{
				void* dest;
				void* source;
				int64_t size;
				POP_INT64_TO(size);
				POP_POINTER_TO(source);
				POP_POINTER_TO(dest);
            memcpy(dest, source, size);        
			}				break;			case OPCODE_BEGINCALL:			{
				uint32_t alignment;
				alignment = extA;
				extA = 0;
            BEGIN_CALL(alignment);        
			}				break;			case OPCODE_CALLARGUMENTINT32:			{
				int32_t value;
				POP_INT32_TO(value);
            CALL_ARGUMENT_INT32(value);        
			}				break;			case OPCODE_CALLARGUMENTINT64:			{
				int32_t value;
				POP_INT32_TO(value);
            CALL_ARGUMENT_INT64(value);        
			}				break;			case OPCODE_CALLARGUMENTPOINTER:			{
				void* value;
				POP_POINTER_TO(value);
            CALL_ARGUMENT_POINTER(value);        
			}				break;			case OPCODE_CALLARGUMENTSTRUCTURE:			{
				uint32_t structureSize;
				void* structurePointer;
				structureSize = extA;
				extA = 0;
				POP_POINTER_TO(structurePointer);
            CALL_ARGUMENT_STRUCTURE(structurePointer, structureSize);        
			}				break;			case OPCODE_CALLARGUMENTFLOAT32:			{
				float value;
				POP_FLOAT32_TO(value);
            CALL_ARGUMENT_FLOAT32(value);        
			}				break;			case OPCODE_CALLARGUMENTFLOAT64:			{
				double value;
				POP_FLOAT64_TO(value);
            CALL_ARGUMENT_FLOAT64(value);        
			}				break;			case OPCODE_PERFORMCALLINT32:			{
				uint32_t function;
				int32_t result;
				function = extA;
				extA = 0;
            DO_CALL_INT32((void**)(size_t)function, result);        
				PUSH_INT32(result);
			}				break;			case OPCODE_PERFORMCALLINT64:			{
				uint32_t function;
				int64_t result;
				function = extA;
				extA = 0;
            DO_CALL_INT64((void**)(size_t)function, result);        
				PUSH_INT64(result);
			}				break;			case OPCODE_PERFORMCALLPOINTER:			{
				uint32_t function;
				void* result;
				function = extA;
				extA = 0;
            DO_CALL_POINTER((void**)(size_t)function, result);        
				PUSH_POINTER(result);
			}				break;			case OPCODE_PERFORMCALLFLOAT32:			{
				uint32_t function;
				float result;
				function = extA;
				extA = 0;
            DO_CALL_FLOAT32((void**)(size_t)function, result);        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_PERFORMCALLFLOAT64:			{
				uint32_t function;
				double result;
				function = extA;
				extA = 0;
            DO_CALL_FLOAT64((void**)(size_t)function, result);        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_PERFORMCALLINDIRECTINT32:			{
				void* function;
				int32_t result;
				POP_POINTER_TO(function);
            DO_CALL_INT32(function, result);        
				PUSH_INT32(result);
			}				break;			case OPCODE_PERFORMCALLINDIRECTINT64:			{
				void* function;
				int64_t result;
				POP_POINTER_TO(function);
            DO_CALL_INT64(function, result);        
				PUSH_INT64(result);
			}				break;			case OPCODE_PERFORMCALLINDIRECTPOINTER:			{
				void* function;
				void* result;
				POP_POINTER_TO(function);
            DO_CALL_POINTER(function, result);        
				PUSH_POINTER(result);
			}				break;			case OPCODE_PERFORMCALLINDIRECTFLOAT32:			{
				void* function;
				float result;
				POP_POINTER_TO(function);
            DO_CALL_FLOAT32(function, result);        
				PUSH_FLOAT32(result);
			}				break;			case OPCODE_PERFORMCALLINDIRECTFLOAT64:			{
				void* function;
				double result;
				POP_POINTER_TO(function);
            DO_CALL_FLOAT64(function, result);        
				PUSH_FLOAT64(result);
			}				break;			case OPCODE_ENDCALL:			{
            END_CALL();        
			}				break;			case OPCODE_ENDCALLNOCLEANUP:			{
            END_CALL_NO_CLEANUP();        
			}				break;			case OPCODE_PLAFTORMCODE:			{
				int32_t code;
            UNIMPLEMENTED();        
				PUSH_INT32(code);
			}				break;			case OPCODE_LOCKREGISTERS:			{
            UNSUPPORTED();        
			}				break;			case OPCODE_UNLOCKREGISTERS:			{
            UNSUPPORTED();        
			}				break;			case OPCODE_MOVEINT32TOPHYSICAL:			{
				uint32_t registerID;
				int32_t value;
				registerID = extA;
				extA = 0;
				POP_INT32_TO(value);
            UNSUPPORTED();        
			}				break;			case OPCODE_MOVEINT64TOPHYSICAL:			{
				uint32_t registerID;
				int64_t value;
				registerID = extA;
				extA = 0;
				POP_INT64_TO(value);
            UNSUPPORTED();        
			}				break;			case OPCODE_MOVEPOINTERTOPHYSICAL:			{
				uint32_t registerID;
				void* value;
				registerID = extA;
				extA = 0;
				POP_POINTER_TO(value);
            UNSUPPORTED();        
			}				break;			case OPCODE_MOVEFLOAT32TOPHYSICAL:			{
				uint32_t registerID;
				float value;
				registerID = extA;
				extA = 0;
				POP_FLOAT32_TO(value);
            UNSUPPORTED();        
			}				break;			case OPCODE_MOVEFLOAT64TOPHYSICAL:			{
				uint32_t registerID;
				double value;
				registerID = extA;
				extA = 0;
				POP_FLOAT64_TO(value);
            UNSUPPORTED();        
			}				break;			case OPCODE_PUSHPHYSICALINT32:			{
				uint32_t registerID;
				int32_t value;
				registerID = extA;
				extA = 0;
            UNSUPPORTED();        
				PUSH_INT32(value);
			}				break;			case OPCODE_PUSHPHYSICALINT64:			{
				uint32_t registerID;
				int64_t value;
				registerID = extA;
				extA = 0;
            UNSUPPORTED();        
				PUSH_INT64(value);
			}				break;			case OPCODE_PUSHPHYSICALPOINTER:			{
				uint32_t registerID;
				void* value;
				registerID = extA;
				extA = 0;
            UNSUPPORTED();        
				PUSH_POINTER(value);
			}				break;			case OPCODE_PUSHPHYSICALFLOAT32:			{
				uint32_t registerID;
				float value;
				registerID = extA;
				extA = 0;
            UNSUPPORTED();        
				PUSH_FLOAT32(value);
			}				break;			case OPCODE_PUSHPHYSICALFLOAT64:			{
				uint32_t registerID;
				double value;
				registerID = extA;
				extA = 0;
            UNSUPPORTED();        
				PUSH_FLOAT64(value);
			}				break;			case OPCODE_CALLPHYSICAL:			{
				uint32_t registerID;
				registerID = extA;
				extA = 0;
            UNSUPPORTED();        
			}				break;			case OPCODE_CALLINSTRUCTION:			{
				uint32_t function;
				function = extA;
				extA = 0;
            UNSUPPORTED();        
			}				break;			default:				/* Unsupported inline primitive. */				return interpreterProxy->primitiveFail();			}		}	}	/* Should never reach here. */	abort();	return 0;}

/***************************************************************************
 * WARNING: This file was automatically generated from the Lowcode
 *			Specification. DO NOT MODIFY.
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LowcodeInterpreterPlugin.h"


/***************************************************************************
 * Instruction Opcode Constants
 */

#define OPCODE_LDSPCL 256
#define OPCODE_LDSELF 257
#define OPCODE_PEEKVM 258
#define OPCODE_POPVM 259
#define OPCODE_PUSHVM 260
#define OPCODE_LDLIT 261
#define OPCODE_LDCS8 262
#define OPCODE_LDCU8 263
#define OPCODE_LDCS16 264
#define OPCODE_LDCU16 265
#define OPCODE_LDCS32 266
#define OPCODE_LDCU32 267
#define OPCODE_LDCS64 268
#define OPCODE_LDCU64 269
#define OPCODE_LDCF32 270
#define OPCODE_LDCF64 271
#define OPCODE_LEA 272
#define OPCODE_LDS8 273
#define OPCODE_LDU8 274
#define OPCODE_LDS16 275
#define OPCODE_LDU16 276
#define OPCODE_LDS32 277
#define OPCODE_LDU32 278
#define OPCODE_LDS64 279
#define OPCODE_LDU64 280
#define OPCODE_LDF32 281
#define OPCODE_LDF64 282
#define OPCODE_STI8 283
#define OPCODE_STI16 284
#define OPCODE_STI32 285
#define OPCODE_STI64 286
#define OPCODE_STF32 287
#define OPCODE_STF64 288
#define OPCODE_MOVI 289
#define OPCODE_MOVF 290
#define OPCODE_MOVOOP 291
#define OPCODE_SEXT8 292
#define OPCODE_SEXT16 293
#define OPCODE_SEXT32 294
#define OPCODE_ZEXT8 295
#define OPCODE_ZEXT16 296
#define OPCODE_ZEXT32 297
#define OPCODE_TRUNC8 298
#define OPCODE_TRUNC16 299
#define OPCODE_TRUNC32 300
#define OPCODE_UINT2FP 301
#define OPCODE_SINT2FP 302
#define OPCODE_FP2UINT 303
#define OPCODE_FP2INT 304
#define OPCODE_ADD 305
#define OPCODE_ADDCS8 306
#define OPCODE_SUB 307
#define OPCODE_MUL 308
#define OPCODE_UMUL 309
#define OPCODE_DIV 310
#define OPCODE_UDIV 311
#define OPCODE_REM 312
#define OPCODE_UREM 313
#define OPCODE_NOT 314
#define OPCODE_AND 315
#define OPCODE_OR 316
#define OPCODE_XOR 317
#define OPCODE_SHLT 318
#define OPCODE_SHRT 319
#define OPCODE_FADD 320
#define OPCODE_FSUB 321
#define OPCODE_FMUL 322
#define OPCODE_FDIV 323
#define OPCODE_FREM 324
#define OPCODE_PIN 325
#define OPCODE_UNPIN 326
#define OPCODE_OOP2PTR 327
#define OPCODE_PTR2OOP 328
#define OPCODE_OOP2BOOL 329
#define OPCODE_OOP2INT 330
#define OPCODE_OOP2I32 331
#define OPCODE_OOP2U32 332
#define OPCODE_OOP2I64 333
#define OPCODE_OOP2U64 334
#define OPCODE_OOP2FP 335
#define OPCODE_BOOL2OOP 336
#define OPCODE_INT2OOP 337
#define OPCODE_I32C2OOP 338
#define OPCODE_U32C2OOP 339
#define OPCODE_FP2OOP 340
#define OPCODE_FSTFLD 341
#define OPCODE_FSTIDX 342
#define OPCODE_NEW 343
#define OPCODE_NEWIDX 344
#define OPCODE_CMP 345
#define OPCODE_FCMP 346
#define OPCODE_TEST 347
#define OPCODE_JMP 348
#define OPCODE_BR 349
#define OPCODE_SWITCH8 350
#define OPCODE_SWITCH16 351
#define OPCODE_SWITCH32 352
#define OPCODE_SWITCH64 353
#define OPCODE_CALLC 354
#define OPCODE_CALLCI 355
#define OPCODE_RET 356
#define OPCODE_RETVMS 357
#define OPCODE_RETVM 358
#define OPCODE_RETF 359
#define OPCODE_RETIF 360
#define OPCODE_LOCKVM 361
#define OPCODE_UNLOCKVM 362
#define OPCODE_CMPSWP32 363
#define OPCODE_CALL 364
#define OPCODE_CALLI 365
#define OPCODE_ENTER 366
#define OPCODE_LEAVE 367
#define OPCODE_ALLOCAF 368
#define OPCODE_ALLOCA 369
#define OPCODE_ALIGN 370
#define OPCODE_MALLOCF 371
#define OPCODE_MALLOC 372
#define OPCODE_FREE 373
#define OPCODE_PUSHI32 374
#define OPCODE_PUSHU32 375
#define OPCODE_PUSHI64 376
#define OPCODE_PUSHU64 377
#define OPCODE_PUSHF32 378
#define OPCODE_PUSHF64 379
#define OPCODE_POPI32 380
#define OPCODE_POPU32 381
#define OPCODE_POPI64 382
#define OPCODE_POPU64 383
#define OPCODE_POPF32 384
#define OPCODE_POPF64 385
#define OPCODE_DECSP 386
#define OPCODE_SAVESP 387
#define OPCODE_RESTORESP 388
#define OPCODE_CHKPLTFM 389
#define OPCODE_LOCKREGS 390
#define OPCODE_UNLOCKREGS 391
#define OPCODE_MOVI2PHY 392
#define OPCODE_MOVF2PHY 393
#define OPCODE_MOVPHY2I 394
#define OPCODE_MOVPHY2F 395
/********************************************************
 * Lowcode Interpreter
 ********************************************************

    The Lowcode instruction set defines a register based virtual machine for
    C like low-level operations and Smalltalk object oriented pointer
    manipulations.
    Lowcode has different set of registers, one for integer, another for
    object-oriented pointers and another for floating point numbers.
    Lowcode is encoded using the Sista inline primitives and they starting with
    opcode inline primitive.

*/

static int Lowcode_initialized = 0;
static LowcodeIntegerRegister alwaysZeroInteger;
static LowcodeFloatRegister alwaysZeroFloat = 0;
static LowcodeOopRegister availableOopRegisters[MAX_REGISTERS]; /* Should use TLS */

void LowcodePlugin_InitializeInterpreter(VirtualMachine *interpreterProxy)
{
    int i;
    sqInt nilObject;

    if(Lowcode_initialized)
        return;

    /* The zero-th registers value must be zero. */
    alwaysZeroInteger.intValue = 0;
    alwaysZeroFloat = 0;
    /* Initialize the oop registers*/
    nilObject = interpreterProxy->nilObject();

    for(i = 0; i < MAX_REGISTERS; ++i)
    {
        availableOopRegisters[i] = nilObject;
        interpreterProxy->addGCRoot(&availableOopRegisters[i]);
    }

    Lowcode_initialized = 1;
}

sqInt LowcodePlugin_InterpretCodeIn(VirtualMachine *interpreterProxy, uint8_t *instructionStream, sqInt currentMethod)
{
    /* The register bank. */
    LowcodeIntegerRegister *allIntegerRegisters = &alwaysZeroInteger;
    LowcodeFloatRegister *allFloatRegisters = &alwaysZeroFloat;
    LowcodeOopRegister *allOopRegisters = availableOopRegisters;
    /* The condition flags */
    LowcodeConditionFlags currentConditionFlags;
    memset(&currentConditionFlags, 0, sizeof(currentConditionFlags));

    if(!Lowcode_initialized)
        LowcodePlugin_InitializeInterpreter(interpreterProxy);

    /* The current program counter. */
    uint8_t *pc = instructionStream;

    /* Execute all the instructions without verification */
    for(;;)
    {
        /* Fetch the first Sista bytecode. */
        uint8_t sistaBytecode = *(pc++);

        /* The sista byte code must be 248 for call primitives*/
        if(sistaBytecode != 248)
            return interpreterProxy->primitiveFail(); /* Unsupported here. */

        /* Decode the inline primitive opcode. */
        uint16_t opcode = (*pc++);
        opcode |=(*pc++)<<8;

        /* Ensure it is a inline primitive. */
        if((opcode & (1<<15)) == 0)
            return interpreterProxy->primitiveFail(); /* Unsupported here. */

        opcode &= ~(1<<15);

        /* Fetch the instruction OpCode */
        switch(opcode)
        {
            /* Load Special Object*/
        case OPCODE_LDSPCL:
        {
            /* Loads a special object from the special objects table. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* TODO: Load from the special objects table*/
        }
        break;

        /* Load Self Object*/
        case OPCODE_LDSELF:
        {
            /* Loads the self object. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            *dest = interpreterProxy->stackValue(interpreterProxy->methodArgumentCount()); /* TODO: Load from the special objects table*/
        }
        break;

        /* Peek VM Stack*/
        case OPCODE_PEEKVM:
        {
            /* Loads an Oop from the VM stack */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* arg -  */
            uint8_t arg = *(pc++);
            *dest = interpreterProxy->stackValue(arg);
        }
        break;

        /* Pop VM Stack*/
        case OPCODE_POPVM:
        {
            /* Pop items from VM stack */
            /* nitems -  */
            uint8_t nitems = *(pc++);
            interpreterProxy->pop(nitems);
        }
        break;

        /* Push Oop to VM Stack*/
        case OPCODE_PUSHVM:
        {
            /* Push oop to VM stack */
            /* item -  */
            LowcodeOopRegister *item = &allOopRegisters[*(pc++)];
            interpreterProxy->push(*item);
        }
        break;

        /* Load Literal Oop*/
        case OPCODE_LDLIT:
        {
            /* Loads Oop value of a literal of the method. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* index -  */
            int16_t index = *((int16_t*)pc);
            pc += 2;
            *dest = interpreterProxy->literalofMethod(index, currentMethod);
        }
        break;

        /* Load SInt8 Constant*/
        case OPCODE_LDCS8:
        {
            /* Loads a 8 bits signed integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            int8_t value = *((int8_t*)pc++);
            dest->intValue = value;
        }
        break;

        /* Load UInt8 Constant*/
        case OPCODE_LDCU8:
        {
            /* Loads a 8 bits unsigned integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            uint8_t value = *(pc++);
            dest->uintValue = value;
        }
        break;

        /* Load SInt16 Constant*/
        case OPCODE_LDCS16:
        {
            /* Loads a 16 bits signed integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            int16_t value = *((int16_t*)pc);
            pc += 2;
            dest->intValue = value;
        }
        break;

        /* Load UInt16 Constant*/
        case OPCODE_LDCU16:
        {
            /* Loads a 16 bits unsigned integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            uint16_t value = *((uint16_t*)pc);
            pc += 2;
            dest->uintValue = value;
        }
        break;

        /* Load SInt32 Constant*/
        case OPCODE_LDCS32:
        {
            /* Loads a 32 bits signed integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            int32_t value = *((int32_t*)pc);
            pc += 4;
            dest->intValue = value;
        }
        break;

        /* Load UInt32 Constant*/
        case OPCODE_LDCU32:
        {
            /* Loads a 32 bits unsigned integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            uint32_t value = *((uint32_t*)pc);
            pc += 4;
            dest->uintValue = value;
        }
        break;

        /* Load SInt32 Constant*/
        case OPCODE_LDCS64:
        {
            /* Loads a 64 bits signed integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            int64_t value = *((int64_t*)pc);
            pc += 8;
            dest->intValue = value;
        }
        break;

        /* Load UInt64 Constant*/
        case OPCODE_LDCU64:
        {
            /* Loads a 64 bits unsigned integer constant into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* value -  */
            uint64_t value = *((uint64_t*)pc);
            pc += 8;
            dest->uintValue = value;
        }
        break;

        /* Load Float32 Constant*/
        case OPCODE_LDCF32:
        {
            /* Loads a 32 bits IEEE floating point value into a register. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* value -  */
            float value = *((float*)pc);
            pc += 4;
            *dest = value;
        }
        break;

        /* Load Float64 Constant*/
        case OPCODE_LDCF64:
        {
            /* Loads a 64 bits IEEE floating point value into a register. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* value -  */
            double value = *((double*)pc);
            pc += 8;
            *dest = value;
        }
        break;

        /* Load Effective Address*/
        case OPCODE_LEA:
        {
            /* Computes a pointer effective address and stores it into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* base -  */
            LowcodeIntegerRegister *base = &allIntegerRegisters[*(pc++)];
            /* index -  */
            LowcodeIntegerRegister *index = &allIntegerRegisters[*(pc++)];
            /* scale -  */
            uint8_t scale = *(pc++);
            /* offset -  */
            uint64_t offset = *((uint64_t*)pc);
            pc += 8;
            dest->pointerValue = base->pointerValue + index->intValue*scale + offset;
        }
        break;

        /* Load SInt8 From Memory*/
        case OPCODE_LDS8:
        {
            /* Loads an 8 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = *((int8_t*)source->pointerValue);
        }
        break;

        /* Load UInt8 From Memory*/
        case OPCODE_LDU8:
        {
            /* Loads an 8 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = *((uint8_t*)source->pointerValue);
        }
        break;

        /* Load SInt16 From Memory*/
        case OPCODE_LDS16:
        {
            /* Loads a 16 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = *((int16_t*)source->pointerValue);
        }
        break;

        /* Load UInt16 From Memory*/
        case OPCODE_LDU16:
        {
            /* Loads a 16 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = *((uint16_t*)source->pointerValue);
        }
        break;

        /* Load SInt32 From Memory*/
        case OPCODE_LDS32:
        {
            /* Loads a 32 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = *((int32_t*)source->pointerValue);
        }
        break;

        /* Load UInt32 From Memory*/
        case OPCODE_LDU32:
        {
            /* Loads a 32 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = *((uint32_t*)source->pointerValue);
        }
        break;

        /* Load SInt64 From Memory*/
        case OPCODE_LDS64:
        {
            /* Loads a 64 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = *((int64_t*)source->pointerValue);
        }
        break;

        /* Load UInt64 From Memory*/
        case OPCODE_LDU64:
        {
            /* Loads a 64 bits signed integer by referencing a pointer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = *((uint64_t*)source->pointerValue);
        }
        break;

        /* Load Float32 From Memory*/
        case OPCODE_LDF32:
        {
            /* Loads an IEEE 754 single precision floating point number
                     into a register by reading the memory. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = *((float*)source->pointerValue);
        }
        break;

        /* Load Float64 From Memory*/
        case OPCODE_LDF64:
        {
            /* Loads an IEEE 754 double precision floating point number
                     into a register by reading the memory. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = *((double*)source->pointerValue);
        }
        break;

        /* Store Int8 Into Memory*/
        case OPCODE_STI8:
        {
            /* Stores an 8 bits integer to the memory. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *((uint8_t*)dest->pointerValue) = source->intValue;
        }
        break;

        /* Store Int16 Into Memory*/
        case OPCODE_STI16:
        {
            /* Stores an 16 bits integer to the memory. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *((uint16_t*)dest->pointerValue) = source->intValue;
        }
        break;

        /* Store Int32 Into Memory*/
        case OPCODE_STI32:
        {
            /* Stores an 32 bits integer to the memory. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *((uint32_t*)dest->pointerValue) = source->intValue;
        }
        break;

        /* Store Int64 Into Memory*/
        case OPCODE_STI64:
        {
            /* Stores an 64 bits integer to the memory. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *((uint64_t*)dest->pointerValue) = source->intValue;
        }
        break;

        /* Store Float32 Into Memory*/
        case OPCODE_STF32:
        {
            /* Stores an IEEE 754 single precision floating point number into the memory. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            *((float*)dest->pointerValue) = *source;
        }
        break;

        /* Store Float64 Into Memory*/
        case OPCODE_STF64:
        {
            /* Stores an IEEE 754 double precision floating point number into the memory. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            *((double*)dest->pointerValue) = *source;
        }
        break;

        /* Move Integer*/
        case OPCODE_MOVI:
        {
            /* Copies an integer value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = *source;
        }
        break;

        /* Move Float*/
        case OPCODE_MOVF:
        {
            /* Copies a float value. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            *dest = *source;
        }
        break;

        /* Move Oop*/
        case OPCODE_MOVOOP:
        {
            /* Copies an Oop. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            *dest = *source;
        }
        break;

        /* Sign Extend 8-bit*/
        case OPCODE_SEXT8:
        {
            /* Sign extends a 8 bit register value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = source->int8Value;
        }
        break;

        /* Sign Extend 16-bit*/
        case OPCODE_SEXT16:
        {
            /* Sign extends a 16 bit register value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = source->int16Value;
        }
        break;

        /* Sign Extend 32-bit*/
        case OPCODE_SEXT32:
        {
            /* Sign extends a 32 bit register value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->intValue = source->int32Value;
        }
        break;

        /* Zero Extend 8-bit*/
        case OPCODE_ZEXT8:
        {
            /* Sign extends a 8 bit register value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = source->uint8Value;
        }
        break;

        /* Zero Extend 16-bit*/
        case OPCODE_ZEXT16:
        {
            /* Zero extends a 16 bit register value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = source->uint16Value;
        }
        break;

        /* Zero Extends 32-bit*/
        case OPCODE_ZEXT32:
        {
            /* Zero extends a 32 bit register value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = source->uint32Value;
        }
        break;

        /* Truncate To 8-Bits*/
        case OPCODE_TRUNC8:
        {
            /* Discards upper bits by keeping only the lower 8-bits */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = source->intValue & 0xFF;
        }
        break;

        /* Truncate To 16-Bits*/
        case OPCODE_TRUNC16:
        {
            /* Discards upper bits by keeping only the lower 16-bits */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = source->uintValue & 0xFFFF;
        }
        break;

        /* Truncate To 32-Bits*/
        case OPCODE_TRUNC32:
        {
            /* Discards upper bits by keeping only the lower 32-bits */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = source->uintValue & 0xFFFFFFFF;
        }
        break;

        /* UInt to Float*/
        case OPCODE_UINT2FP:
        {
            /* Converts an unsigned integer into a floating point number. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = source->uintValue;
        }
        break;

        /* SInt to Float*/
        case OPCODE_SINT2FP:
        {
            /* Converts an signed integer into a floating point number. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = source->intValue;
        }
        break;

        /* Float to UInt*/
        case OPCODE_FP2UINT:
        {
            /* Converts floating point number into an unsigned integer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            dest->uintValue = *source;
        }
        break;

        /* Float to UInt*/
        case OPCODE_FP2INT:
        {
            /* Converts floating point number into a signed integer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            dest->intValue = *source;
        }
        break;

        /* Integer Addition*/
        case OPCODE_ADD:
        {
            /* Integer addition without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->intValue = first->intValue + second->intValue;
        }
        break;

        /* Integer Add Constants*/
        case OPCODE_ADDCS8:
        {
            /* Signed integer adition of a small constant. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* constant -  */
            int8_t constant = *((int8_t*)pc++);
            dest->intValue += constant;
        }
        break;

        /* Integer Subtraction*/
        case OPCODE_SUB:
        {
            /* Integer subtraction without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->intValue = first->intValue - second->intValue;
        }
        break;

        /* Integer multiplication*/
        case OPCODE_MUL:
        {
            /* Signed integer multiplication without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->intValue = first->intValue * second->intValue;
        }
        break;

        /* Unsigned Integer multiplication*/
        case OPCODE_UMUL:
        {
            /* Unsigned integer multiplication without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue * second->uintValue;
        }
        break;

        /* Signed Integer Division*/
        case OPCODE_DIV:
        {
            /* Signed integer division without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->intValue = first->intValue / second->intValue;
        }
        break;

        /* Unsigned Integer Division*/
        case OPCODE_UDIV:
        {
            /* Unsigned integer division without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue / second->uintValue;
        }
        break;

        /* Signed Integer Remainder*/
        case OPCODE_REM:
        {
            /* Signed integer division without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->intValue = first->intValue % second->intValue;
        }
        break;

        /* Unsigned Integer Remainder*/
        case OPCODE_UREM:
        {
            /* Unsigned integer division without overflow check. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue % second->uintValue;
        }
        break;

        /* Bitwise Not*/
        case OPCODE_NOT:
        {
            /* Performs a bitwise not. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            dest->uintValue = ~dest->uintValue;
        }
        break;

        /* Bitwise And*/
        case OPCODE_AND:
        {
            /* Performs a bitwise and. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue & second->uintValue;
        }
        break;

        /* Bitwise Or*/
        case OPCODE_OR:
        {
            /* Performs a bitwise or. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue | second->uintValue;
        }
        break;

        /* Bitwise Xor*/
        case OPCODE_XOR:
        {
            /* Performs a bitwise xor. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue ^ second->uintValue;
        }
        break;

        /* Shift Left*/
        case OPCODE_SHLT:
        {
            /* Performs a shifting to the left. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue << second->uintValue;
        }
        break;

        /* Shift Right*/
        case OPCODE_SHRT:
        {
            /* Performs a shifting to the right. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            dest->uintValue = first->uintValue >> second->uintValue;
        }
        break;

        /* Float Addition*/
        case OPCODE_FADD:
        {
            /* Floating point addition. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* first -  */
            LowcodeFloatRegister *first = &allFloatRegisters[*(pc++)];
            /* second -  */
            LowcodeFloatRegister *second = &allFloatRegisters[*(pc++)];
            *dest = *first + *second;
        }
        break;

        /* Float Subtraction*/
        case OPCODE_FSUB:
        {
            /* Floating point subtraction. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* first -  */
            LowcodeFloatRegister *first = &allFloatRegisters[*(pc++)];
            /* second -  */
            LowcodeFloatRegister *second = &allFloatRegisters[*(pc++)];
            *dest = *first - *second;
        }
        break;

        /* Float Multiplication*/
        case OPCODE_FMUL:
        {
            /* Floating point multiplication. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* first -  */
            LowcodeFloatRegister *first = &allFloatRegisters[*(pc++)];
            /* second -  */
            LowcodeFloatRegister *second = &allFloatRegisters[*(pc++)];
            *dest = (*first) * (*second);
        }
        break;

        /* Float Division*/
        case OPCODE_FDIV:
        {
            /* Floating point division. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* first -  */
            LowcodeFloatRegister *first = &allFloatRegisters[*(pc++)];
            /* second -  */
            LowcodeFloatRegister *second = &allFloatRegisters[*(pc++)];
            *dest = *first / *second;
        }
        break;

        /* Float Remainder*/
        case OPCODE_FREM:
        {
            /* Floating point remainder. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* first -  */
            LowcodeFloatRegister *first = &allFloatRegisters[*(pc++)];
            /* second -  */
            LowcodeFloatRegister *second = &allFloatRegisters[*(pc++)];
            {
                double a = *first;
                double b = *second;
                *dest = a - ((int)(a/b))*b;
            }
        }
        break;

        /* Pin Object*/
        case OPCODE_PIN:
        {
            /* Pins an Oop pointed object */
            /* object -  */
            LowcodeOopRegister *object = &allOopRegisters[*(pc++)];
            /* TODO: Requires Spur */
        }
        break;

        /* Unpin Object*/
        case OPCODE_UNPIN:
        {
            /* Unpins an Oop pointed object */
            /* object -  */
            LowcodeOopRegister *object = &allOopRegisters[*(pc++)];
            /* TODO: Requires Spur */
        }
        break;

        /* Cast Oop to Pointer*/
        case OPCODE_OOP2PTR:
        {
            /* Casts an Oop into a pointer by copying it into an integer
                     register.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->intValue = *source;
        }
        break;

        /* Casts Pointer to Oop*/
        case OPCODE_PTR2OOP:
        {
            /* Casts an pointer into an Oop by copying it from an integer
                     register.
            */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = source->intValue;
        }
        break;

        /* Oop to Boolean*/
        case OPCODE_OOP2BOOL:
        {
            /* Decodes an Oop representing a boolean into an integer. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->intValue = interpreterProxy->booleanValueOf(*source);
        }
        break;

        /* Oop to Integer*/
        case OPCODE_OOP2INT:
        {
            /* Decodes an Oop into an integer value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->intValue = interpreterProxy->integerValueOf(*source);
        }
        break;

        /* Oop to Int32*/
        case OPCODE_OOP2I32:
        {
            /* Decodes an Oop into an signed 32 bits integer value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->intValue = interpreterProxy->signed32BitValueOf(*source);
        }
        break;

        /* Oop to UInt32*/
        case OPCODE_OOP2U32:
        {
            /* Decodes an Oop into an unsigned 32 bits integer value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->uintValue = interpreterProxy->positive32BitValueOf(*source);
        }
        break;

        /* Oop to Int32*/
        case OPCODE_OOP2I64:
        {
            /* Decodes an Oop into an signed 64 bits integer value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->intValue = interpreterProxy->signed64BitValueOf(*source);
        }
        break;

        /* Oop to UInt32*/
        case OPCODE_OOP2U64:
        {
            /* Decodes an Oop into an unsigned 64 bits integer value. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->uintValue = interpreterProxy->positive64BitValueOf(*source);
        }
        break;

        /* Oop to Float*/
        case OPCODE_OOP2FP:
        {
            /* Decodes an Oop into floating point value. */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            *dest = interpreterProxy->floatValueOf(*source);
        }
        break;

        /* Boolean to Oop*/
        case OPCODE_BOOL2OOP:
        {
            /* Converts an integer representing a boolean into an oop. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = source->intValue ? interpreterProxy->trueObject() : interpreterProxy->falseObject();
        }
        break;

        /* Integer to Object*/
        case OPCODE_INT2OOP:
        {
            /* Makes an object for an integer. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = interpreterProxy->integerObjectOf(source->intValue);
        }
        break;

        /* Int32 to Object*/
        case OPCODE_I32C2OOP:
        {
            /* Makes an object for 32 bits signed integer. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = interpreterProxy->signed32BitIntegerFor(source->intValue);
        }
        break;

        /* Int32 to Object*/
        case OPCODE_U32C2OOP:
        {
            /* Makes an object for 32 bits unsigned integer. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            *dest = interpreterProxy->positive32BitIntegerFor(source->intValue);
        }
        break;

        /* Float to Object*/
        case OPCODE_FP2OOP:
        {
            /* Makes an object for a floating point value. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            *dest = interpreterProxy->floatObjectOf(*source);
        }
        break;

        /* First Fixed Field*/
        case OPCODE_FSTFLD:
        {
            /* Loads the first fixed field address of an object into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->pointerValue = (uint8_t*)interpreterProxy->firstFixedField(*source);
        }
        break;

        /* First Indexable Field*/
        case OPCODE_FSTIDX:
        {
            /* Loads the first indexable field address of an object into a register. */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source -  */
            LowcodeOopRegister *source = &allOopRegisters[*(pc++)];
            dest->pointerValue = (uint8_t*)interpreterProxy->firstIndexableField(*source);
        }
        break;

        /* New Object*/
        case OPCODE_NEW:
        {
            /* Instantiate a class */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* classOop -  */
            LowcodeOopRegister *classOop = &allOopRegisters[*(pc++)];
            *dest = interpreterProxy->instantiateClassindexableSize(*classOop, 0);
        }
        break;

        /* New Indexable Object*/
        case OPCODE_NEWIDX:
        {
            /* Instantiate an indexable object with a specified size. */
            /* dest -  */
            LowcodeOopRegister *dest = &allOopRegisters[*(pc++)];
            /* classOop -  */
            LowcodeOopRegister *classOop = &allOopRegisters[*(pc++)];
            /* size -  */
            LowcodeIntegerRegister *size = &allIntegerRegisters[*(pc++)];
            *dest = interpreterProxy->instantiateClassindexableSize(*classOop, size->intValue);
        }
        break;

        /* Compare Two Integers*/
        case OPCODE_CMP:
        {
            /* Compares two integers by subtracting them and sets the
                     condition codes.
            */
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            Lowcode_setConditionFlagsBySubtractingIntegerWith(&currentConditionFlags, first->uintValue, second->uintValue);
        }
        break;

        /* Compare Two Floats*/
        case OPCODE_FCMP:
        {
            /* Compares two floats by subtracting them and sets the
                     condition codes.
            */
            /* first -  */
            LowcodeFloatRegister *first = &allFloatRegisters[*(pc++)];
            /* second -  */
            LowcodeFloatRegister *second = &allFloatRegisters[*(pc++)];
            Lowcode_setConditionFlagsBySubtractingFloatWith(&currentConditionFlags, *first, *second);
        }
        break;

        /* Compare With And*/
        case OPCODE_TEST:
        {
            /* Compares two integers by performing the logical AND between
                     them and setting the condition codes.
            */
            /* first -  */
            LowcodeIntegerRegister *first = &allIntegerRegisters[*(pc++)];
            /* second -  */
            LowcodeIntegerRegister *second = &allIntegerRegisters[*(pc++)];
            Lowcode_setConditionFlagsByAndingIntegerWith(&currentConditionFlags, first->uintValue, second->uintValue);
        }
        break;

        /* Jump*/
        case OPCODE_JMP:
        {
            /* Performs an Unconditional Jump */
            /* dest -  */
            uint8_t *dest = instructionStream + *((uint16_t*)pc);
            pc += 2;
            pc = dest;
        }
        break;

        /* Branch*/
        case OPCODE_BR:
        {
            /* Performs an Conditional Jump */
            /* condition -  */
            uint8_t condition = *(pc++);
            /* dest -  */
            uint8_t *dest = instructionStream + *((uint16_t*)pc);
            pc += 2;

            if(Lowcode_isConditionSatisfiedByIn(condition, &currentConditionFlags, interpreterProxy))
                pc = dest;
        }
        break;

        /* Jump Table 8-bits Values*/
        case OPCODE_SWITCH8:
        {
            /* Makes a jump table for 8-bits integers. */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* defaultDest -  */
            uint8_t *defaultDest = instructionStream + *((uint16_t*)pc);
            pc += 2;
            /* jumpTable -  */
            uint32_t jumpTableSize = *((uint32_t*)pc);
            pc+= 4;
            uint16_t *jumpTableOffsets = (uint16_t*)pc;
            pc += jumpTableSize*2;
            uint16_t *jumpTableValues = (uint16_t*)pc;

            if(jumpTableSize < (1 <<16))
                pc += jumpTableSize*2;

            /* TODO */
        }
        break;

        /* Jump Table 16-bits Values*/
        case OPCODE_SWITCH16:
        {
            /* Makes a jump table for 16-bits integers. */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* defaultDest -  */
            uint8_t *defaultDest = instructionStream + *((uint16_t*)pc);
            pc += 2;
            /* jumpTable -  */
            uint32_t jumpTableSize = *((uint32_t*)pc);
            pc+= 4;
            uint16_t *jumpTableOffsets = (uint16_t*)pc;
            pc += jumpTableSize*2;
            uint16_t *jumpTableValues = (uint16_t*)pc;

            if(jumpTableSize < (1 <<16))
                pc += jumpTableSize*2;

            /* TODO */
        }
        break;

        /* Jump Table 16-bits Values*/
        case OPCODE_SWITCH32:
        {
            /* Makes a jump table for 32-bits integers. */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* defaultDest -  */
            uint8_t *defaultDest = instructionStream + *((uint16_t*)pc);
            pc += 2;
            /* jumpTable -  */
            uint32_t jumpTableSize = *((uint32_t*)pc);
            pc+= 4;
            uint16_t *jumpTableOffsets = (uint16_t*)pc;
            pc += jumpTableSize*2;
            uint32_t *jumpTableValues = (uint32_t*)pc;
            pc += jumpTableSize*4;
            /* TODO */
        }
        break;

        /* Jump Table 64-bits Values*/
        case OPCODE_SWITCH64:
        {
            /* Makes a jump table for 64-bits integers. */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* defaultDest -  */
            uint8_t *defaultDest = instructionStream + *((uint16_t*)pc);
            pc += 2;
            /* jumpTable -  */
            uint32_t jumpTableSize = *((uint32_t*)pc);
            pc+= 4;
            uint16_t *jumpTableOffsets = (uint16_t*)pc;
            pc += jumpTableSize*2;
            uint64_t *jumpTableValues = (uint64_t*)pc;
            pc += jumpTableSize*8;
            /* TODO */
        }
        break;

        /* Call C Function*/
        case OPCODE_CALLC:
        {
            /* Calls a standard C function. */
            /* function - Function entry point address. */
            uint64_t function = *((uint64_t*)pc);
            pc += 8;
            /* args -  */
            uint8_t argsCount = *(pc++);
            uint8_t *args = pc;
            pc += argsCount;
            /* Cannot be implemented easily and portably in C*/
        }
        break;

        /* Call C Function Indirectly*/
        case OPCODE_CALLCI:
        {
            /* Calls a standard C function indirectly. */
            /* function - Function entry point address. */
            LowcodeIntegerRegister *function = &allIntegerRegisters[*(pc++)];
            /* args -  */
            uint8_t argsCount = *(pc++);
            uint8_t *args = pc;
            pc += argsCount;
            /* Cannot be implemented easily and portably in C*/
        }
        break;

        /* Return*/
        case OPCODE_RET:
        {
            /* Performs a standard return */
            /* Cannot be implemented in C*/
        }
        break;

        /* Return self to the VM*/
        case OPCODE_RETVMS:
        {
            /* Pops all the arguments from the stack and pushes a return value. */
            return interpreterProxy->pop(interpreterProxy->methodArgumentCount());
        }
        break;

        /* Return to the VM*/
        case OPCODE_RETVM:
        {
            /* Pops all the arguments from the stack and pushes a return value. */
            /* result -  */
            LowcodeOopRegister *result = &allOopRegisters[*(pc++)];
            return interpreterProxy->popthenPush(1 + interpreterProxy->methodArgumentCount(), *result);
        }
        break;

        /* Return With Failure*/
        case OPCODE_RETF:
        {
            /* Return to the VM with a failure code. */
            /* code -  */
            LowcodeIntegerRegister *code = &allIntegerRegisters[*(pc++)];
            return interpreterProxy->primitiveFailFor(code->intValue);
        }
        break;

        /* Return If Failure*/
        case OPCODE_RETIF:
        {
            /* Return to the VM if a failure has happened. */
            if(interpreterProxy->failed())
                return interpreterProxy->primitiveFail();
        }
        break;

        /* Lock VM*/
        case OPCODE_LOCKVM:
        {
            /* Locks the VM to the current thread. */
            /* TODO */
        }
        break;

        /* Unlock VM*/
        case OPCODE_UNLOCKVM:
        {
            /* Unlocks the VM from the current thread. */
            /* TODO */
        }
        break;

        /* Compare and Swap 32 Bits*/
        case OPCODE_CMPSWP32:
        {
            /*
            Compares a 32 bit value in memory with a reference value,
            if they are equal it swaps the memory location with a new value.
            It returns the old value in the memory location.
            This operation is guaranteed to be atomic.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* check -  */
            LowcodeIntegerRegister *check = &allIntegerRegisters[*(pc++)];
            /* newValue -  */
            LowcodeIntegerRegister *newValue = &allIntegerRegisters[*(pc++)];
            /* oldValue -  */
            LowcodeIntegerRegister *oldValue = &allIntegerRegisters[*(pc++)];
            /* TODO */
        }
        break;

        /* Call Function*/
        case OPCODE_CALL:
        {
            /* Calls a function using a custom calling convention.
            This intruction pushes the return address into the stack and jumps
            to the called function entry point. */
            /* function - Function entry point address. */
            uint64_t function = *((uint64_t*)pc);
            pc += 8;
            /* Cannot be implemented in C*/
        }
        break;

        /* Call Function Indirectly*/
        case OPCODE_CALLI:
        {
            /* Calls indirectly a function using a custom calling convention.
            This intruction pushes the return address into the stack and jumps
            to the called function entry point. */
            /* reg - CPU Register ID */
            uint8_t reg = *(pc++);
            /* Cannot be implemented in C*/
        }
        break;

        /* Enter Frame*/
        case OPCODE_ENTER:
        {
            /*
            Saves previously used registers and ensure there is enough space for
            the requested registers.
            */
            /* intRegisters -  */
            uint8_t intRegisters = *(pc++);
            /* oopRegisters -  */
            uint8_t oopRegisters = *(pc++);
            /* floatRegisters -  */
            uint8_t floatRegisters = *(pc++);
            /* Reserve space for the new registers*/
            allIntegerRegisters = (LowcodeIntegerRegister*)alloca((intRegisters+1)*sizeof(LowcodeIntegerRegister));
            /*allOopRegisters = (LowcodeOopRegister*)alloca((oopRegisters+1)*sizeof(LowcodeOopRegister));*/
            allFloatRegisters = (LowcodeFloatRegister*)alloca((floatRegisters+1)*sizeof(LowcodeFloatRegister));
            /* Set IR0, FR0 and OR0 */
            allIntegerRegisters[0].intValue = 0;
            allFloatRegisters[0] = 0;
            /* allOopRegisters[0] = interpreterProxy->nilObject(); */
            /* Current implementation shares Oop to avoid registering/unregistering too much GC roots.*/
        }
        break;

        /* Leave Frame*/
        case OPCODE_LEAVE:
        {
            /*
            Restores previously save registers. Return instructions perform this
            implicitly.
            */
            /* Do nothing here. */
        }
        break;

        /* Alloca Fixed*/
        case OPCODE_ALLOCAF:
        {
            /*
            Allocates fixed memory amount in the stack.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* size -  */
            uint32_t size = *((uint32_t*)pc);
            pc += 4;
            dest->pointerValue = (uint8_t*)alloca(size);
        }
        break;

        /* Alloca*/
        case OPCODE_ALLOCA:
        {
            /*
            Allocates variable sized memory in the stack.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* size -  */
            LowcodeIntegerRegister *size = &allIntegerRegisters[*(pc++)];
            dest->pointerValue = (uint8_t*)alloca(size->intValue);
        }
        break;

        /* Align*/
        case OPCODE_ALIGN:
        {
            /* Aligns the stack. */
            /* alignment -  */
            uint8_t alignment = *(pc++);
            /* Cannot be implemented here. */
        }
        break;

        /* Memory Allocate Fixed*/
        case OPCODE_MALLOCF:
        {
            /*
            Allocates fixed memory in the heap.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* size -  */
            uint32_t size = *((uint32_t*)pc);
            pc += 4;
            dest->pointerValue = (uint8_t*)malloc(size);
        }
        break;

        /* Memory Allocate*/
        case OPCODE_MALLOC:
        {
            /*
            Allocates memory in the heap.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* size -  */
            LowcodeIntegerRegister *size = &allIntegerRegisters[*(pc++)];
            dest->pointerValue = (uint8_t*)malloc(size->intValue);
        }
        break;

        /* Frees Memory*/
        case OPCODE_FREE:
        {
            /*
            Frees previously allocated memory in the heap.
            */
            /* pointer -  */
            LowcodeIntegerRegister *pointer = &allIntegerRegisters[*(pc++)];
            free(pointer->pointerValue);
        }
        break;

        /* Push Signed 32 Bit Integer*/
        case OPCODE_PUSHI32:
        {
            /*
            Pushes a 32 bit signed integer to the stack. If the arquitecture word
            is bigger than 32 bit, it is automatically sign extended.
            */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Push Unsigned 32 Bit Integer*/
        case OPCODE_PUSHU32:
        {
            /*
            Pushes a 32 bit unsigned integer to the stack. If the arquitecture word
            is bigger than 32 bit, it is automatically zero extended.
            */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Push Signed 64 Bit Integer*/
        case OPCODE_PUSHI64:
        {
            /*
            Pushes a 64 bit signed integer to the stack. If the arquitecture word
            is bigger than 64 bit, it is automatically sign extended.
            */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Push Unsigned 64 Bit Integer*/
        case OPCODE_PUSHU64:
        {
            /*
            Pushes a 64 bit unsigned integer to the stack. If the arquitecture word
            is bigger than 64 bit, it is automatically zero extended.
            */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Push Float32*/
        case OPCODE_PUSHF32:
        {
            /*
            Pushes an IEEE 754 single precision floating point number to the stack.
            If in the underlying arquitecture they are passed with more precision,
            then it is placed with more precision.
            */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Push Float64*/
        case OPCODE_PUSHF64:
        {
            /*
            Pushes an IEEE 754 double precision floating point number to the stack.
            If in the underlying arquitecture they are passed with more precision,
            then it is placed with more precision.
            */
            /* value -  */
            LowcodeIntegerRegister *value = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Pop Signed 32 Bit Integer*/
        case OPCODE_POPI32:
        {
            /*
            Pops a 32 bit signed integer from the stack. If the arquitecture word
            is bigger than 32 bit, it is automatically truncated.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Pop Unsigned 32 Bit Integer*/
        case OPCODE_POPU32:
        {
            /*
            Pops a 32 bit unsigned integer from the stack. If the arquitecture word
            is bigger than 32 bit, it is automatically truncated.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Pop Signed 64 Bit Integer*/
        case OPCODE_POPI64:
        {
            /*
            Pops a 64 bit signed integer from the stack. If the arquitecture word
            is bigger than 64 bit, it is automatically truncated.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Pop Unsigned 64 Bit Integer*/
        case OPCODE_POPU64:
        {
            /*
            Pops a 64 bit unsigned integer from the stack. If the arquitecture word
            is bigger than 64 bit, it is automatically truncated.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Pop Float32*/
        case OPCODE_POPF32:
        {
            /*
            Pop an IEEE 754 single precision floating point number from the stack.
            If in the underlying arquitecture they are passed with more precision,
            then it is truncated when placing in the destination register.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Pop Float64*/
        case OPCODE_POPF64:
        {
            /*
            Pops an IEEE 754 double precision floating point number from the stack.
            If in the underlying arquitecture they are passed with more precision,
            then it is placed in the destination register..
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Decrement SP*/
        case OPCODE_DECSP:
        {
            /*
            Decrements the stack pointer by a fixed amount, making the effect of
            reducing the stack
            */
            /* amount - Bytes to decrement the stack pointer. */
            uint8_t amount = *(pc++);
            /* Cannot be done here */
        }
        break;

        /* Save Stack Pointer*/
        case OPCODE_SAVESP:
        {
            /*
            Saves the stack to restore it in a future point.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Restore Stack Pointer*/
        case OPCODE_RESTORESP:
        {
            /* Restores a previously saved stack pointer. */
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Check Platform*/
        case OPCODE_CHKPLTFM:
        {
            /*
            Checks if the current platforms conforms to the specified platform code.
            */
            /* platformCode -  */
            uint32_t platformCode = *((uint32_t*)pc);
            pc += 4;
            /* TODO */
        }
        break;

        /* Lock Registers*/
        case OPCODE_LOCKREGS:
        {
            /*
            Locks the CPU register. This tells the register allocator that the
            following instructions are going to modify some explicit CPU registers.
            */
            /* Cannot be done here */
        }
        break;

        /* Unlock Registers*/
        case OPCODE_UNLOCKREGS:
        {
            /*
            Unlocks the CPU register. This tells the register allocator that the
            following instructions don't require specific CPU registers.
            */
            /* Cannot be done here */
        }
        break;

        /* Move Integer Register To Physical Register*/
        case OPCODE_MOVI2PHY:
        {
            /*
            Moves the content of a logical register into a physical CPU register.
            */
            /* dest - CPU Register Identifier */
            uint8_t dest = *(pc++);
            /* source -  */
            LowcodeIntegerRegister *source = &allIntegerRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Move Float Register To Physical Register*/
        case OPCODE_MOVF2PHY:
        {
            /*
            Moves the content of a logical register into a physical CPU register.
            */
            /* dest - CPU Register Identifier */
            uint8_t dest = *(pc++);
            /* source -  */
            LowcodeFloatRegister *source = &allFloatRegisters[*(pc++)];
            /* Cannot be done here */
        }
        break;

        /* Move Physical Register To Integer Register*/
        case OPCODE_MOVPHY2I:
        {
            /*
            Moves the content of a physical CPU register into a logical register.
            */
            /* dest -  */
            LowcodeIntegerRegister *dest = &allIntegerRegisters[*(pc++)];
            /* source - CPU Register Identifier */
            uint8_t source = *(pc++);
            /* Cannot be done here */
        }
        break;

        /* Move Physical Register To Float Register*/
        case OPCODE_MOVPHY2F:
        {
            /*
            Moves the content of physical CPU register into a logical register into.
            */
            /* dest -  */
            LowcodeFloatRegister *dest = &allFloatRegisters[*(pc++)];
            /* source - CPU Register Identifier */
            uint8_t source = *(pc++);
            /* Cannot be done here */
        }
        break;

        default:
            /* Unsupported inline primitive. */
            return interpreterProxy->primitiveFail();
        }
    }

    /* Should never reach here. */
    abort();
    return 0;
}

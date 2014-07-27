// LowcodeLLVMGenerated.cpp - WARNING THIS FILE WAS AUTOMATICALLY GENERATED. DO NOT MODIFY	#include "LowcodeLLVM.hpp"namespace Lowcode{// Sista extended byte instruction kinds.InstructionKind::Type SistaExtendedInstruction::getKind() const{ 	switch(getOpcode())	{	/* pushReceiverVariableSmallIndex */
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
		return InstructionKind::Operation;
	/* pushLiteralVariableSmallIndex */
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
		return InstructionKind::Operation;
	/* pushLiteralSmallIndex */
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
		return InstructionKind::Operation;
	/* pushTempSmallIndex */
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 69:
	case 70:
	case 71:
		return InstructionKind::Operation;
	/* pushTempSmallIndex2 */
	case 72:
	case 73:
	case 74:
	case 75:
		return InstructionKind::Operation;
	/* pushReceiver */
	case 76:
		return InstructionKind::Operation;
	/* pushTrue */
	case 77:
		return InstructionKind::Operation;
	/* pushFalse */
	case 78:
		return InstructionKind::Operation;
	/* pushNil */
	case 79:
		return InstructionKind::Operation;
	/* pushZero */
	case 80:
		return InstructionKind::Operation;
	/* pushOne */
	case 81:
		return InstructionKind::Operation;
	/* pushThisContext */
	case 82:
		return InstructionKind::Operation;
	/* dupTop */
	case 83:
		return InstructionKind::Operation;
	/* returnReceiver */
	case 88:
		return InstructionKind::Terminator;
	/* returnTrue */
	case 89:
		return InstructionKind::Terminator;
	/* returnFalse */
	case 90:
		return InstructionKind::Terminator;
	/* returnNil */
	case 91:
		return InstructionKind::Terminator;
	/* returnTop */
	case 92:
		return InstructionKind::Terminator;
	/* nop */
	case 95:
		return InstructionKind::Operation;
	/* sendSpecialMessageClass */
	case 119:
		return InstructionKind::Operation;
	/* popAndStoreTemp */
	case 208:
	case 209:
	case 210:
	case 211:
	case 212:
	case 213:
	case 214:
	case 215:
		return InstructionKind::Operation;
	/* popStackTop */
	case 216:
		return InstructionKind::Operation;
	default:		return InstructionKind::Operation;	}}// Lowcode instruction kinds.InstructionKind::Type LowcodeInstruction::getKind() const{ 	switch(getOpcode())	{		case 256: /* duplicateInt32 */
			return InstructionKind::Operation;
		case 257: /* duplicateInt64 */
			return InstructionKind::Operation;
		case 258: /* duplicatePointer */
			return InstructionKind::Operation;
		case 259: /* duplicateFloat32 */
			return InstructionKind::Operation;
		case 260: /* duplicateFloat64 */
			return InstructionKind::Operation;
		case 261: /* popInt32 */
			return InstructionKind::Operation;
		case 262: /* popInt64 */
			return InstructionKind::Operation;
		case 263: /* popPointer */
			return InstructionKind::Operation;
		case 264: /* popFloat32 */
			return InstructionKind::Operation;
		case 265: /* popFloat64 */
			return InstructionKind::Operation;
		case 266: /* pushZero32 */
			return InstructionKind::Operation;
		case 267: /* pushOne32 */
			return InstructionKind::Operation;
		case 268: /* pushZero64 */
			return InstructionKind::Operation;
		case 269: /* pushOne64 */
			return InstructionKind::Operation;
		case 270: /* pushConstantUInt32 */
			return InstructionKind::Operation;
		case 271: /* pushConstantUInt64 */
			return InstructionKind::Operation;
		case 272: /* pushZeroFloat32 */
			return InstructionKind::Operation;
		case 273: /* pushOneFloat32 */
			return InstructionKind::Operation;
		case 274: /* pushZeroFloat64 */
			return InstructionKind::Operation;
		case 275: /* pushOneFloat64 */
			return InstructionKind::Operation;
		case 276: /* pushNullPointer */
			return InstructionKind::Operation;
		case 277: /* pushSessionIdentifier */
			return InstructionKind::Operation;
		case 278: /* checkSessionIdentifier */
			return InstructionKind::Operation;
		case 279: /* pointerOffset32 */
			return InstructionKind::Operation;
		case 280: /* pointerOffset64 */
			return InstructionKind::Operation;
		case 281: /* effectiveAddress32 */
			return InstructionKind::Operation;
		case 282: /* effectiveAddress64 */
			return InstructionKind::Operation;
		case 283: /* loadUInt8FromMemory */
			return InstructionKind::Operation;
		case 284: /* loadUInt16FromMemory */
			return InstructionKind::Operation;
		case 285: /* loadUInt32FromMemory */
			return InstructionKind::Operation;
		case 286: /* loadUInt64FromMemory */
			return InstructionKind::Operation;
		case 287: /* loadInt8FromMemory */
			return InstructionKind::Operation;
		case 288: /* loadInt16FromMemory */
			return InstructionKind::Operation;
		case 289: /* loadInt32FromMemory */
			return InstructionKind::Operation;
		case 290: /* loadInt64FromMemory */
			return InstructionKind::Operation;
		case 291: /* loadPointerFromMemory */
			return InstructionKind::Operation;
		case 292: /* loadFloat32FromMemory */
			return InstructionKind::Operation;
		case 293: /* loadFloat64FromMemory */
			return InstructionKind::Operation;
		case 294: /* storeInt8ToMemory */
			return InstructionKind::Operation;
		case 295: /* storeInt16ToMemory */
			return InstructionKind::Operation;
		case 296: /* storeInt32ToMemory */
			return InstructionKind::Operation;
		case 297: /* storeInt64ToMemory */
			return InstructionKind::Operation;
		case 298: /* storePointerToMemory */
			return InstructionKind::Operation;
		case 299: /* storeFloat32ToMemory */
			return InstructionKind::Operation;
		case 300: /* storeFloat64ToMemory */
			return InstructionKind::Operation;
		case 301: /* loadLocalAddress */
			return InstructionKind::Operation;
		case 302: /* loadLocalUInt8 */
			return InstructionKind::Operation;
		case 303: /* loadLocalUInt16 */
			return InstructionKind::Operation;
		case 304: /* loadLocalUInt32 */
			return InstructionKind::Operation;
		case 305: /* loadLocalUInt64 */
			return InstructionKind::Operation;
		case 306: /* loadLocalInt8 */
			return InstructionKind::Operation;
		case 307: /* loadLocalInt16 */
			return InstructionKind::Operation;
		case 308: /* loadLocalInt32 */
			return InstructionKind::Operation;
		case 309: /* loadLocalInt64 */
			return InstructionKind::Operation;
		case 310: /* loadLocalPointer */
			return InstructionKind::Operation;
		case 311: /* loadLocalFloat32 */
			return InstructionKind::Operation;
		case 312: /* loadLocalFloat64 */
			return InstructionKind::Operation;
		case 313: /* storeLocalInt8 */
			return InstructionKind::Operation;
		case 314: /* storeLocalInt16 */
			return InstructionKind::Operation;
		case 315: /* storeLocalInt32 */
			return InstructionKind::Operation;
		case 316: /* storeLocalInt64 */
			return InstructionKind::Operation;
		case 317: /* storeLocalPointer */
			return InstructionKind::Operation;
		case 318: /* storeLocalFloat32 */
			return InstructionKind::Operation;
		case 319: /* storeLocalFloat64 */
			return InstructionKind::Operation;
		case 320: /* signExtend32From8 */
			return InstructionKind::Operation;
		case 321: /* signExtend32From16 */
			return InstructionKind::Operation;
		case 322: /* signExtend64From8 */
			return InstructionKind::Operation;
		case 323: /* signExtend64From16 */
			return InstructionKind::Operation;
		case 324: /* signExtend64From32 */
			return InstructionKind::Operation;
		case 325: /* zeroExtend32From8 */
			return InstructionKind::Operation;
		case 326: /* zeroExtend32From16 */
			return InstructionKind::Operation;
		case 327: /* zeroExtend64From8 */
			return InstructionKind::Operation;
		case 328: /* zeroExtend64From16 */
			return InstructionKind::Operation;
		case 329: /* zeroExtend64From32 */
			return InstructionKind::Operation;
		case 330: /* truncate32To8 */
			return InstructionKind::Operation;
		case 331: /* truncate32To16 */
			return InstructionKind::Operation;
		case 332: /* truncate64To8 */
			return InstructionKind::Operation;
		case 333: /* truncate64To16 */
			return InstructionKind::Operation;
		case 334: /* truncate64To32 */
			return InstructionKind::Operation;
		case 335: /* uint32ToFloat32 */
			return InstructionKind::Operation;
		case 336: /* uint32ToFloat64 */
			return InstructionKind::Operation;
		case 337: /* int32ToFloat32 */
			return InstructionKind::Operation;
		case 338: /* int32ToFloat64 */
			return InstructionKind::Operation;
		case 339: /* uint64ToFloat32 */
			return InstructionKind::Operation;
		case 340: /* uint64ToFloat64 */
			return InstructionKind::Operation;
		case 341: /* int64ToFloat32 */
			return InstructionKind::Operation;
		case 342: /* int64ToFloat64 */
			return InstructionKind::Operation;
		case 343: /* float32ToInt32 */
			return InstructionKind::Operation;
		case 344: /* float64ToInt32 */
			return InstructionKind::Operation;
		case 345: /* float32ToInt64 */
			return InstructionKind::Operation;
		case 346: /* float64ToInt64 */
			return InstructionKind::Operation;
		case 347: /* pointerToInt32 */
			return InstructionKind::Operation;
		case 348: /* pointerToInt64 */
			return InstructionKind::Operation;
		case 349: /* int32ToPointer */
			return InstructionKind::Operation;
		case 350: /* int64ToPointer */
			return InstructionKind::Operation;
		case 351: /* add32 */
			return InstructionKind::Operation;
		case 352: /* sub32 */
			return InstructionKind::Operation;
		case 353: /* neg32 */
			return InstructionKind::Operation;
		case 354: /* mul32 */
			return InstructionKind::Operation;
		case 355: /* umul32 */
			return InstructionKind::Operation;
		case 356: /* div32 */
			return InstructionKind::Operation;
		case 357: /* udiv32 */
			return InstructionKind::Operation;
		case 358: /* rem32 */
			return InstructionKind::Operation;
		case 359: /* urem32 */
			return InstructionKind::Operation;
		case 360: /* add64 */
			return InstructionKind::Operation;
		case 361: /* sub64 */
			return InstructionKind::Operation;
		case 362: /* neg64 */
			return InstructionKind::Operation;
		case 363: /* mul64 */
			return InstructionKind::Operation;
		case 364: /* umul64 */
			return InstructionKind::Operation;
		case 365: /* div64 */
			return InstructionKind::Operation;
		case 366: /* udiv64 */
			return InstructionKind::Operation;
		case 367: /* rem64 */
			return InstructionKind::Operation;
		case 368: /* urem64 */
			return InstructionKind::Operation;
		case 369: /* not32 */
			return InstructionKind::Operation;
		case 370: /* and32 */
			return InstructionKind::Operation;
		case 371: /* or32 */
			return InstructionKind::Operation;
		case 372: /* xor32 */
			return InstructionKind::Operation;
		case 373: /* leftShift32 */
			return InstructionKind::Operation;
		case 374: /* rightShift32 */
			return InstructionKind::Operation;
		case 375: /* arithmeticRightShift32 */
			return InstructionKind::Operation;
		case 376: /* not64 */
			return InstructionKind::Operation;
		case 377: /* and64 */
			return InstructionKind::Operation;
		case 378: /* or64 */
			return InstructionKind::Operation;
		case 379: /* xor64 */
			return InstructionKind::Operation;
		case 380: /* leftShift64 */
			return InstructionKind::Operation;
		case 381: /* rightShift64 */
			return InstructionKind::Operation;
		case 382: /* arithmeticRightShift64 */
			return InstructionKind::Operation;
		case 383: /* float32Add */
			return InstructionKind::Operation;
		case 384: /* float32Sub */
			return InstructionKind::Operation;
		case 385: /* float32Mul */
			return InstructionKind::Operation;
		case 386: /* float32Div */
			return InstructionKind::Operation;
		case 387: /* float64Add */
			return InstructionKind::Operation;
		case 388: /* float64Sub */
			return InstructionKind::Operation;
		case 389: /* float64Mul */
			return InstructionKind::Operation;
		case 390: /* float64Div */
			return InstructionKind::Operation;
		case 391: /* pin */
			return InstructionKind::Operation;
		case 392: /* unpin */
			return InstructionKind::Operation;
		case 393: /* oopToPointer */
			return InstructionKind::Operation;
		case 394: /* oopToPointerReinterpret */
			return InstructionKind::Operation;
		case 395: /* pointerToOop */
			return InstructionKind::Operation;
		case 396: /* pointerToOopReinterprer */
			return InstructionKind::Operation;
		case 397: /* instantiateOop */
			return InstructionKind::Operation;
		case 398: /* instantiateIndexableOop */
			return InstructionKind::Operation;
		case 399: /* instantiateIndexable32Oop */
			return InstructionKind::Operation;
		case 400: /* oopToBoolean32 */
			return InstructionKind::Operation;
		case 401: /* oopToBoolean64 */
			return InstructionKind::Operation;
		case 402: /* oopSmallIntegerToInt32 */
			return InstructionKind::Operation;
		case 403: /* oopToInt32 */
			return InstructionKind::Operation;
		case 404: /* oopToUInt32 */
			return InstructionKind::Operation;
		case 405: /* oopSmallIntegerToInt64 */
			return InstructionKind::Operation;
		case 406: /* oopToInt64 */
			return InstructionKind::Operation;
		case 407: /* oopToUInt64 */
			return InstructionKind::Operation;
		case 408: /* oopToFloat32 */
			return InstructionKind::Operation;
		case 409: /* oopToFloat64 */
			return InstructionKind::Operation;
		case 410: /* boolean32ToOop */
			return InstructionKind::Operation;
		case 411: /* boolean64ToOop */
			return InstructionKind::Operation;
		case 412: /* smallInt32ToOop */
			return InstructionKind::Operation;
		case 413: /* int32ToOop */
			return InstructionKind::Operation;
		case 414: /* uint32ToOop */
			return InstructionKind::Operation;
		case 415: /* int64ToOop */
			return InstructionKind::Operation;
		case 416: /* uint64ToOop */
			return InstructionKind::Operation;
		case 417: /* float32ToOop */
			return InstructionKind::Operation;
		case 418: /* float64ToOop */
			return InstructionKind::Operation;
		case 419: /* loadObjectField */
			return InstructionKind::Operation;
		case 420: /* storeObjectField */
			return InstructionKind::Operation;
		case 421: /* loadObjectAt */
			return InstructionKind::Operation;
		case 422: /* storeObjectFieldAt */
			return InstructionKind::Operation;
		case 423: /* firstFieldPointer */
			return InstructionKind::Operation;
		case 424: /* firstIndexableFieldPointer */
			return InstructionKind::Operation;
		case 425: /* byteSizeOf */
			return InstructionKind::Operation;
		case 426: /* isBytes */
			return InstructionKind::Operation;
		case 427: /* isFloatObject */
			return InstructionKind::Operation;
		case 428: /* isIndexable */
			return InstructionKind::Operation;
		case 429: /* isIntegerObject */
			return InstructionKind::Operation;
		case 430: /* isWords */
			return InstructionKind::Operation;
		case 431: /* isWordsOrBytes */
			return InstructionKind::Operation;
		case 432: /* isPointers */
			return InstructionKind::Operation;
		case 433: /* pointerEqual */
			return InstructionKind::Operation;
		case 434: /* pointerNotEqual */
			return InstructionKind::Operation;
		case 435: /* oopEqual */
			return InstructionKind::Operation;
		case 436: /* oopNotEqual */
			return InstructionKind::Operation;
		case 437: /* int32Equal */
			return InstructionKind::Operation;
		case 438: /* int32NotEqual */
			return InstructionKind::Operation;
		case 439: /* int32Less */
			return InstructionKind::Operation;
		case 440: /* int32LessEqual */
			return InstructionKind::Operation;
		case 441: /* int32Great */
			return InstructionKind::Operation;
		case 442: /* int32GreatEqual */
			return InstructionKind::Operation;
		case 443: /* uint32Less */
			return InstructionKind::Operation;
		case 444: /* uint32LessEqual */
			return InstructionKind::Operation;
		case 445: /* uint32Great */
			return InstructionKind::Operation;
		case 446: /* uint32GreatEqual */
			return InstructionKind::Operation;
		case 447: /* int64Equal */
			return InstructionKind::Operation;
		case 448: /* int64NotEqual */
			return InstructionKind::Operation;
		case 449: /* int64Less */
			return InstructionKind::Operation;
		case 450: /* int64LessEqual */
			return InstructionKind::Operation;
		case 451: /* int64Great */
			return InstructionKind::Operation;
		case 452: /* int64GreatEqual */
			return InstructionKind::Operation;
		case 453: /* uint64Less */
			return InstructionKind::Operation;
		case 454: /* uint64LessEqual */
			return InstructionKind::Operation;
		case 455: /* uint64Great */
			return InstructionKind::Operation;
		case 456: /* uint64GreatEqual */
			return InstructionKind::Operation;
		case 457: /* float32Equal */
			return InstructionKind::Operation;
		case 458: /* float32NotEqual */
			return InstructionKind::Operation;
		case 459: /* float32Less */
			return InstructionKind::Operation;
		case 460: /* float32LessEqual */
			return InstructionKind::Operation;
		case 461: /* float32Great */
			return InstructionKind::Operation;
		case 462: /* float32GreatEqual */
			return InstructionKind::Operation;
		case 463: /* float64Equal */
			return InstructionKind::Operation;
		case 464: /* float64NotEqual */
			return InstructionKind::Operation;
		case 465: /* float64Less */
			return InstructionKind::Operation;
		case 466: /* float64LessEqual */
			return InstructionKind::Operation;
		case 467: /* float64Great */
			return InstructionKind::Operation;
		case 468: /* float64GreatEqual */
			return InstructionKind::Operation;
		case 469: /* jump */
			return InstructionKind::Jump;
		case 470: /* branchTrue32 */
			return InstructionKind::Branch;
		case 471: /* branchFalse32 */
			return InstructionKind::Branch;
		case 472: /* branchTrue64 */
			return InstructionKind::Branch;
		case 473: /* branchFalse64 */
			return InstructionKind::Branch;
		case 478: /* returnSmallInteger */
			return InstructionKind::Terminator;
		case 479: /* returnBoolean32AsOop */
			return InstructionKind::Terminator;
		case 480: /* returnBoolean64AsOop */
			return InstructionKind::Terminator;
		case 481: /* returnInt32AsOop */
			return InstructionKind::Terminator;
		case 482: /* returnInt64AsOop */
			return InstructionKind::Terminator;
		case 483: /* returnUInt32AsOop */
			return InstructionKind::Terminator;
		case 484: /* returnUInt64AsOop */
			return InstructionKind::Terminator;
		case 485: /* returnPointerAsOop */
			return InstructionKind::Terminator;
		case 486: /* returnFloat32AsOop */
			return InstructionKind::Terminator;
		case 487: /* returnFloat64AsOop */
			return InstructionKind::Terminator;
		case 488: /* fail */
			return InstructionKind::Terminator;
		case 489: /* failWithCode */
			return InstructionKind::Terminator;
		case 490: /* lockVM */
			return InstructionKind::Operation;
		case 491: /* unlockVM */
			return InstructionKind::Operation;
		case 492: /* compareAndSwap32 */
			return InstructionKind::Operation;
		case 493: /* alloca32 */
			return InstructionKind::Operation;
		case 494: /* alloca64 */
			return InstructionKind::Operation;
		case 495: /* malloc32 */
			return InstructionKind::Operation;
		case 496: /* malloc64 */
			return InstructionKind::Operation;
		case 497: /* free */
			return InstructionKind::Operation;
		case 498: /* memcpyFixed */
			return InstructionKind::Operation;
		case 499: /* memcpy32 */
			return InstructionKind::Operation;
		case 500: /* memcpy64 */
			return InstructionKind::Operation;
		case 501: /* beginCall */
			return InstructionKind::Operation;
		case 502: /* callArgumentInt32 */
			return InstructionKind::Operation;
		case 503: /* callArgumentInt64 */
			return InstructionKind::Operation;
		case 504: /* callArgumentPointer */
			return InstructionKind::Operation;
		case 505: /* callArgumentStructure */
			return InstructionKind::Operation;
		case 506: /* callArgumentFloat32 */
			return InstructionKind::Operation;
		case 507: /* callArgumentFloat64 */
			return InstructionKind::Operation;
		case 508: /* performCallInt32 */
			return InstructionKind::Operation;
		case 509: /* performCallInt64 */
			return InstructionKind::Operation;
		case 510: /* performCallPointer */
			return InstructionKind::Operation;
		case 511: /* performCallFloat32 */
			return InstructionKind::Operation;
		case 512: /* performCallFloat64 */
			return InstructionKind::Operation;
		case 513: /* performCallIndirectInt32 */
			return InstructionKind::Operation;
		case 514: /* performCallIndirectInt64 */
			return InstructionKind::Operation;
		case 515: /* performCallIndirectPointer */
			return InstructionKind::Operation;
		case 516: /* performCallIndirectFloat32 */
			return InstructionKind::Operation;
		case 517: /* performCallIndirectFloat64 */
			return InstructionKind::Operation;
		case 518: /* endCall */
			return InstructionKind::Operation;
		case 519: /* endCallNoCleanup */
			return InstructionKind::Operation;
		case 520: /* plaftormCode */
			return InstructionKind::Operation;
		case 521: /* lockRegisters */
			return InstructionKind::Operation;
		case 522: /* unlockRegisters */
			return InstructionKind::Operation;
		case 523: /* moveInt32ToPhysical */
			return InstructionKind::Operation;
		case 524: /* moveInt64ToPhysical */
			return InstructionKind::Operation;
		case 525: /* movePointerToPhysical */
			return InstructionKind::Operation;
		case 526: /* moveFloat32ToPhysical */
			return InstructionKind::Operation;
		case 527: /* moveFloat64ToPhysical */
			return InstructionKind::Operation;
		case 528: /* pushPhysicalInt32 */
			return InstructionKind::Operation;
		case 529: /* pushPhysicalInt64 */
			return InstructionKind::Operation;
		case 530: /* pushPhysicalPointer */
			return InstructionKind::Operation;
		case 531: /* pushPhysicalFloat32 */
			return InstructionKind::Operation;
		case 532: /* pushPhysicalFloat64 */
			return InstructionKind::Operation;
		case 533: /* callPhysical */
			return InstructionKind::Operation;
		case 534: /* callInstruction */
			return InstructionKind::Operation;
	default:		return InstructionKind::Operation;	}}// Sista extended byte code validationbool SistaExtendedInstruction::validate(LowcodeValidationStack &stack){	switch(getOpcode())	{	/* pushReceiverVariableSmallIndex */
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
		stack.pushOop();
		return true;
	/* pushLiteralVariableSmallIndex */
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
		stack.pushOop();
		return true;
	/* pushLiteralSmallIndex */
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
		stack.pushOop();
		return true;
	/* pushTempSmallIndex */
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 69:
	case 70:
	case 71:
		stack.pushOop();
		return true;
	/* pushTempSmallIndex2 */
	case 72:
	case 73:
	case 74:
	case 75:
		stack.pushOop();
		return true;
	/* pushReceiver */
	case 76:
		stack.pushOop();
		return true;
	/* pushTrue */
	case 77:
		stack.pushOop();
		return true;
	/* pushFalse */
	case 78:
		stack.pushOop();
		return true;
	/* pushNil */
	case 79:
		stack.pushOop();
		return true;
	/* pushZero */
	case 80:
		stack.pushOop();
		return true;
	/* pushOne */
	case 81:
		stack.pushOop();
		return true;
	/* pushThisContext */
	case 82:
		stack.pushOop();
		return true;
	/* dupTop */
	case 83:
		if(!stack.popOop()) return false;
		stack.pushOop();
		stack.pushOop();
		return true;
	/* returnReceiver */
	case 88:
		return true;
	/* returnTrue */
	case 89:
		return true;
	/* returnFalse */
	case 90:
		return true;
	/* returnNil */
	case 91:
		return true;
	/* returnTop */
	case 92:
		if(!stack.popOop()) return false;
		return true;
	/* nop */
	case 95:
		return true;
	/* sendSpecialMessageClass */
	case 119:
		if(!stack.popOop()) return false;
		stack.pushOop();
		return true;
	/* popAndStoreTemp */
	case 208:
	case 209:
	case 210:
	case 211:
	case 212:
	case 213:
	case 214:
	case 215:
		if(!stack.popOop()) return false;
		return true;
	/* popStackTop */
	case 216:
		if(!stack.popOop()) return false;
		return true;
	}}// Lowcode instruction validationbool LowcodeInstruction::validate(LowcodeValidationStack &stack){	switch(getOpcode())	{	case 256: /* duplicateInt32 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		stack.pushInt32();
		return true;
	case 257: /* duplicateInt64 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		stack.pushInt64();
		return true;
	case 258: /* duplicatePointer */
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		stack.pushPointer();
		return true;
	case 259: /* duplicateFloat32 */
		if(!stack.popFloat32()) return false;
		stack.pushFloat32();
		stack.pushFloat32();
		return true;
	case 260: /* duplicateFloat64 */
		if(!stack.popFloat64()) return false;
		stack.pushFloat64();
		stack.pushFloat64();
		return true;
	case 261: /* popInt32 */
		if(!stack.popInt32()) return false;
		return true;
	case 262: /* popInt64 */
		if(!stack.popInt64()) return false;
		return true;
	case 263: /* popPointer */
		if(!stack.popPointer()) return false;
		return true;
	case 264: /* popFloat32 */
		if(!stack.popFloat32()) return false;
		return true;
	case 265: /* popFloat64 */
		if(!stack.popFloat64()) return false;
		return true;
	case 266: /* pushZero32 */
		stack.pushInt32();
		return true;
	case 267: /* pushOne32 */
		stack.pushInt32();
		return true;
	case 268: /* pushZero64 */
		stack.pushInt64();
		return true;
	case 269: /* pushOne64 */
		stack.pushInt64();
		return true;
	case 270: /* pushConstantUInt32 */
		stack.pushInt32();
		return true;
	case 271: /* pushConstantUInt64 */
		stack.pushInt64();
		return true;
	case 272: /* pushZeroFloat32 */
		stack.pushFloat32();
		return true;
	case 273: /* pushOneFloat32 */
		stack.pushFloat32();
		return true;
	case 274: /* pushZeroFloat64 */
		stack.pushFloat64();
		return true;
	case 275: /* pushOneFloat64 */
		stack.pushFloat64();
		return true;
	case 276: /* pushNullPointer */
		stack.pushPointer();
		return true;
	case 277: /* pushSessionIdentifier */
		stack.pushInt32();
		return true;
	case 278: /* checkSessionIdentifier */
		stack.pushInt32();
		return true;
	case 279: /* pointerOffset32 */
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		return true;
	case 280: /* pointerOffset64 */
		if(!stack.popInt64()) return false;
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		return true;
	case 281: /* effectiveAddress32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		return true;
	case 282: /* effectiveAddress64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		return true;
	case 283: /* loadUInt8FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 284: /* loadUInt16FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 285: /* loadUInt32FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 286: /* loadUInt64FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt64();
		return true;
	case 287: /* loadInt8FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 288: /* loadInt16FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 289: /* loadInt32FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 290: /* loadInt64FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushInt64();
		return true;
	case 291: /* loadPointerFromMemory */
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		return true;
	case 292: /* loadFloat32FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushFloat32();
		return true;
	case 293: /* loadFloat64FromMemory */
		if(!stack.popPointer()) return false;
		stack.pushFloat64();
		return true;
	case 294: /* storeInt8ToMemory */
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 295: /* storeInt16ToMemory */
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 296: /* storeInt32ToMemory */
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 297: /* storeInt64ToMemory */
		if(!stack.popInt64()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 298: /* storePointerToMemory */
		if(!stack.popPointer()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 299: /* storeFloat32ToMemory */
		if(!stack.popFloat32()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 300: /* storeFloat64ToMemory */
		if(!stack.popFloat64()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 301: /* loadLocalAddress */
		stack.pushPointer();
		return true;
	case 302: /* loadLocalUInt8 */
		stack.pushInt32();
		return true;
	case 303: /* loadLocalUInt16 */
		stack.pushInt32();
		return true;
	case 304: /* loadLocalUInt32 */
		stack.pushInt32();
		return true;
	case 305: /* loadLocalUInt64 */
		stack.pushInt64();
		return true;
	case 306: /* loadLocalInt8 */
		stack.pushInt32();
		return true;
	case 307: /* loadLocalInt16 */
		stack.pushInt32();
		return true;
	case 308: /* loadLocalInt32 */
		stack.pushInt32();
		return true;
	case 309: /* loadLocalInt64 */
		stack.pushInt64();
		return true;
	case 310: /* loadLocalPointer */
		stack.pushPointer();
		return true;
	case 311: /* loadLocalFloat32 */
		stack.pushFloat32();
		return true;
	case 312: /* loadLocalFloat64 */
		stack.pushFloat64();
		return true;
	case 313: /* storeLocalInt8 */
		if(!stack.popInt32()) return false;
		return true;
	case 314: /* storeLocalInt16 */
		if(!stack.popInt32()) return false;
		return true;
	case 315: /* storeLocalInt32 */
		if(!stack.popInt32()) return false;
		return true;
	case 316: /* storeLocalInt64 */
		if(!stack.popInt64()) return false;
		return true;
	case 317: /* storeLocalPointer */
		if(!stack.popPointer()) return false;
		return true;
	case 318: /* storeLocalFloat32 */
		if(!stack.popFloat32()) return false;
		return true;
	case 319: /* storeLocalFloat64 */
		if(!stack.popFloat64()) return false;
		return true;
	case 320: /* signExtend32From8 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 321: /* signExtend32From16 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 322: /* signExtend64From8 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 323: /* signExtend64From16 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 324: /* signExtend64From32 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 325: /* zeroExtend32From8 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 326: /* zeroExtend32From16 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 327: /* zeroExtend64From8 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 328: /* zeroExtend64From16 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 329: /* zeroExtend64From32 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 330: /* truncate32To8 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 331: /* truncate32To16 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 332: /* truncate64To8 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 333: /* truncate64To16 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 334: /* truncate64To32 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 335: /* uint32ToFloat32 */
		if(!stack.popInt32()) return false;
		stack.pushFloat32();
		return true;
	case 336: /* uint32ToFloat64 */
		if(!stack.popInt32()) return false;
		stack.pushFloat64();
		return true;
	case 337: /* int32ToFloat32 */
		if(!stack.popInt32()) return false;
		stack.pushFloat32();
		return true;
	case 338: /* int32ToFloat64 */
		if(!stack.popInt32()) return false;
		stack.pushFloat64();
		return true;
	case 339: /* uint64ToFloat32 */
		if(!stack.popInt64()) return false;
		stack.pushFloat32();
		return true;
	case 340: /* uint64ToFloat64 */
		if(!stack.popInt64()) return false;
		stack.pushFloat64();
		return true;
	case 341: /* int64ToFloat32 */
		if(!stack.popInt64()) return false;
		stack.pushFloat64();
		return true;
	case 342: /* int64ToFloat64 */
		if(!stack.popInt64()) return false;
		stack.pushFloat64();
		return true;
	case 343: /* float32ToInt32 */
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 344: /* float64ToInt32 */
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 345: /* float32ToInt64 */
		if(!stack.popFloat32()) return false;
		stack.pushInt64();
		return true;
	case 346: /* float64ToInt64 */
		if(!stack.popFloat64()) return false;
		stack.pushInt64();
		return true;
	case 347: /* pointerToInt32 */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 348: /* pointerToInt64 */
		if(!stack.popPointer()) return false;
		stack.pushInt64();
		return true;
	case 349: /* int32ToPointer */
		if(!stack.popInt32()) return false;
		stack.pushPointer();
		return true;
	case 350: /* int64ToPointer */
		if(!stack.popInt64()) return false;
		stack.pushPointer();
		return true;
	case 351: /* add32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 352: /* sub32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 353: /* neg32 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 354: /* mul32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 355: /* umul32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 356: /* div32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 357: /* udiv32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 358: /* rem32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 359: /* urem32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 360: /* add64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 361: /* sub64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 362: /* neg64 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 363: /* mul64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 364: /* umul64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 365: /* div64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 366: /* udiv64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 367: /* rem64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 368: /* urem64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 369: /* not32 */
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 370: /* and32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 371: /* or32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 372: /* xor32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 373: /* leftShift32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 374: /* rightShift32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 375: /* arithmeticRightShift32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 376: /* not64 */
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 377: /* and64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 378: /* or64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 379: /* xor64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 380: /* leftShift64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 381: /* rightShift64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 382: /* arithmeticRightShift64 */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt64();
		return true;
	case 383: /* float32Add */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushFloat32();
		return true;
	case 384: /* float32Sub */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushFloat32();
		return true;
	case 385: /* float32Mul */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushFloat32();
		return true;
	case 386: /* float32Div */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushFloat32();
		return true;
	case 387: /* float64Add */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushFloat64();
		return true;
	case 388: /* float64Sub */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushFloat64();
		return true;
	case 389: /* float64Mul */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushFloat64();
		return true;
	case 390: /* float64Div */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushFloat64();
		return true;
	case 391: /* pin */
		if(!stack.popOop()) return false;
		return true;
	case 392: /* unpin */
		if(!stack.popOop()) return false;
		return true;
	case 393: /* oopToPointer */
		if(!stack.popOop()) return false;
		stack.pushPointer();
		return true;
	case 394: /* oopToPointerReinterpret */
		if(!stack.popOop()) return false;
		stack.pushPointer();
		return true;
	case 395: /* pointerToOop */
		if(!stack.popPointer()) return false;
		stack.pushOop();
		return true;
	case 396: /* pointerToOopReinterprer */
		if(!stack.popPointer()) return false;
		stack.pushOop();
		return true;
	case 397: /* instantiateOop */
		if(!stack.popOop()) return false;
		stack.pushOop();
		return true;
	case 398: /* instantiateIndexableOop */
		if(!stack.popOop()) return false;
		stack.pushOop();
		return true;
	case 399: /* instantiateIndexable32Oop */
		if(!stack.popInt32()) return false;
		if(!stack.popOop()) return false;
		stack.pushOop();
		return true;
	case 400: /* oopToBoolean32 */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 401: /* oopToBoolean64 */
		if(!stack.popOop()) return false;
		stack.pushInt64();
		return true;
	case 402: /* oopSmallIntegerToInt32 */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 403: /* oopToInt32 */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 404: /* oopToUInt32 */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 405: /* oopSmallIntegerToInt64 */
		if(!stack.popOop()) return false;
		stack.pushInt64();
		return true;
	case 406: /* oopToInt64 */
		if(!stack.popOop()) return false;
		stack.pushInt64();
		return true;
	case 407: /* oopToUInt64 */
		if(!stack.popOop()) return false;
		stack.pushInt64();
		return true;
	case 408: /* oopToFloat32 */
		if(!stack.popOop()) return false;
		stack.pushFloat32();
		return true;
	case 409: /* oopToFloat64 */
		if(!stack.popOop()) return false;
		stack.pushFloat64();
		return true;
	case 410: /* boolean32ToOop */
		if(!stack.popInt32()) return false;
		stack.pushOop();
		return true;
	case 411: /* boolean64ToOop */
		if(!stack.popInt64()) return false;
		stack.pushOop();
		return true;
	case 412: /* smallInt32ToOop */
		if(!stack.popInt32()) return false;
		stack.pushOop();
		return true;
	case 413: /* int32ToOop */
		if(!stack.popInt32()) return false;
		stack.pushOop();
		return true;
	case 414: /* uint32ToOop */
		if(!stack.popInt32()) return false;
		stack.pushOop();
		return true;
	case 415: /* int64ToOop */
		if(!stack.popInt64()) return false;
		stack.pushOop();
		return true;
	case 416: /* uint64ToOop */
		if(!stack.popInt64()) return false;
		stack.pushOop();
		return true;
	case 417: /* float32ToOop */
		if(!stack.popFloat32()) return false;
		stack.pushOop();
		return true;
	case 418: /* float64ToOop */
		if(!stack.popFloat64()) return false;
		stack.pushOop();
		return true;
	case 419: /* loadObjectField */
		if(!stack.popOop()) return false;
		stack.pushOop();
		return true;
	case 420: /* storeObjectField */
		if(!stack.popOop()) return false;
		if(!stack.popOop()) return false;
		return true;
	case 421: /* loadObjectAt */
		if(!stack.popInt32()) return false;
		if(!stack.popOop()) return false;
		stack.pushOop();
		return true;
	case 422: /* storeObjectFieldAt */
		if(!stack.popOop()) return false;
		if(!stack.popInt32()) return false;
		if(!stack.popOop()) return false;
		return true;
	case 423: /* firstFieldPointer */
		if(!stack.popOop()) return false;
		stack.pushPointer();
		return true;
	case 424: /* firstIndexableFieldPointer */
		if(!stack.popOop()) return false;
		stack.pushPointer();
		return true;
	case 425: /* byteSizeOf */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 426: /* isBytes */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 427: /* isFloatObject */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 428: /* isIndexable */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 429: /* isIntegerObject */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 430: /* isWords */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 431: /* isWordsOrBytes */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 432: /* isPointers */
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 433: /* pointerEqual */
		if(!stack.popPointer()) return false;
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 434: /* pointerNotEqual */
		if(!stack.popPointer()) return false;
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 435: /* oopEqual */
		if(!stack.popOop()) return false;
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 436: /* oopNotEqual */
		if(!stack.popOop()) return false;
		if(!stack.popOop()) return false;
		stack.pushInt32();
		return true;
	case 437: /* int32Equal */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 438: /* int32NotEqual */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 439: /* int32Less */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 440: /* int32LessEqual */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 441: /* int32Great */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 442: /* int32GreatEqual */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 443: /* uint32Less */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 444: /* uint32LessEqual */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 445: /* uint32Great */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 446: /* uint32GreatEqual */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 447: /* int64Equal */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 448: /* int64NotEqual */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		stack.pushInt32();
		return true;
	case 449: /* int64Less */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 450: /* int64LessEqual */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 451: /* int64Great */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 452: /* int64GreatEqual */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 453: /* uint64Less */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 454: /* uint64LessEqual */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 455: /* uint64Great */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 456: /* uint64GreatEqual */
		if(!stack.popInt64()) return false;
		if(!stack.popInt64()) return false;
		stack.pushInt32();
		return true;
	case 457: /* float32Equal */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 458: /* float32NotEqual */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 459: /* float32Less */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 460: /* float32LessEqual */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 461: /* float32Great */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 462: /* float32GreatEqual */
		if(!stack.popFloat32()) return false;
		if(!stack.popFloat32()) return false;
		stack.pushInt32();
		return true;
	case 463: /* float64Equal */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 464: /* float64NotEqual */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 465: /* float64Less */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 466: /* float64LessEqual */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 467: /* float64Great */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 468: /* float64GreatEqual */
		if(!stack.popFloat64()) return false;
		if(!stack.popFloat64()) return false;
		stack.pushInt32();
		return true;
	case 469: /* jump */
		return true;
	case 470: /* branchTrue32 */
		if(!stack.popInt32()) return false;
		return true;
	case 471: /* branchFalse32 */
		if(!stack.popInt32()) return false;
		return true;
	case 472: /* branchTrue64 */
		if(!stack.popInt64()) return false;
		return true;
	case 473: /* branchFalse64 */
		if(!stack.popInt32()) return false;
		return true;
	case 478: /* returnSmallInteger */
		if(!stack.popInt32()) return false;
		return true;
	case 479: /* returnBoolean32AsOop */
		if(!stack.popInt32()) return false;
		return true;
	case 480: /* returnBoolean64AsOop */
		if(!stack.popInt64()) return false;
		return true;
	case 481: /* returnInt32AsOop */
		if(!stack.popInt32()) return false;
		return true;
	case 482: /* returnInt64AsOop */
		if(!stack.popInt64()) return false;
		return true;
	case 483: /* returnUInt32AsOop */
		if(!stack.popInt32()) return false;
		return true;
	case 484: /* returnUInt64AsOop */
		if(!stack.popInt64()) return false;
		return true;
	case 485: /* returnPointerAsOop */
		if(!stack.popPointer()) return false;
		return true;
	case 486: /* returnFloat32AsOop */
		if(!stack.popFloat32()) return false;
		return true;
	case 487: /* returnFloat64AsOop */
		if(!stack.popFloat64()) return false;
		return true;
	case 488: /* fail */
		return true;
	case 489: /* failWithCode */
		return true;
	case 490: /* lockVM */
		return true;
	case 491: /* unlockVM */
		return true;
	case 492: /* compareAndSwap32 */
		if(!stack.popInt32()) return false;
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 493: /* alloca32 */
		if(!stack.popInt32()) return false;
		stack.pushPointer();
		return true;
	case 494: /* alloca64 */
		if(!stack.popInt64()) return false;
		stack.pushPointer();
		return true;
	case 495: /* malloc32 */
		if(!stack.popInt32()) return false;
		stack.pushPointer();
		return true;
	case 496: /* malloc64 */
		if(!stack.popInt64()) return false;
		stack.pushPointer();
		return true;
	case 497: /* free */
		if(!stack.popPointer()) return false;
		return true;
	case 498: /* memcpyFixed */
		if(!stack.popPointer()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 499: /* memcpy32 */
		if(!stack.popInt32()) return false;
		if(!stack.popPointer()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 500: /* memcpy64 */
		if(!stack.popInt64()) return false;
		if(!stack.popPointer()) return false;
		if(!stack.popPointer()) return false;
		return true;
	case 501: /* beginCall */
		return true;
	case 502: /* callArgumentInt32 */
		if(!stack.popInt32()) return false;
		return true;
	case 503: /* callArgumentInt64 */
		if(!stack.popInt32()) return false;
		return true;
	case 504: /* callArgumentPointer */
		if(!stack.popPointer()) return false;
		return true;
	case 505: /* callArgumentStructure */
		if(!stack.popPointer()) return false;
		return true;
	case 506: /* callArgumentFloat32 */
		if(!stack.popFloat32()) return false;
		return true;
	case 507: /* callArgumentFloat64 */
		if(!stack.popFloat64()) return false;
		return true;
	case 508: /* performCallInt32 */
		stack.pushInt32();
		return true;
	case 509: /* performCallInt64 */
		stack.pushInt64();
		return true;
	case 510: /* performCallPointer */
		stack.pushPointer();
		return true;
	case 511: /* performCallFloat32 */
		stack.pushFloat32();
		return true;
	case 512: /* performCallFloat64 */
		stack.pushFloat64();
		return true;
	case 513: /* performCallIndirectInt32 */
		if(!stack.popPointer()) return false;
		stack.pushInt32();
		return true;
	case 514: /* performCallIndirectInt64 */
		if(!stack.popPointer()) return false;
		stack.pushInt64();
		return true;
	case 515: /* performCallIndirectPointer */
		if(!stack.popPointer()) return false;
		stack.pushPointer();
		return true;
	case 516: /* performCallIndirectFloat32 */
		if(!stack.popPointer()) return false;
		stack.pushFloat32();
		return true;
	case 517: /* performCallIndirectFloat64 */
		if(!stack.popPointer()) return false;
		stack.pushFloat64();
		return true;
	case 518: /* endCall */
		return true;
	case 519: /* endCallNoCleanup */
		return true;
	case 520: /* plaftormCode */
		stack.pushInt32();
		return true;
	case 521: /* lockRegisters */
		return true;
	case 522: /* unlockRegisters */
		return true;
	case 523: /* moveInt32ToPhysical */
		if(!stack.popInt32()) return false;
		return true;
	case 524: /* moveInt64ToPhysical */
		if(!stack.popInt64()) return false;
		return true;
	case 525: /* movePointerToPhysical */
		if(!stack.popPointer()) return false;
		return true;
	case 526: /* moveFloat32ToPhysical */
		if(!stack.popFloat32()) return false;
		return true;
	case 527: /* moveFloat64ToPhysical */
		if(!stack.popFloat64()) return false;
		return true;
	case 528: /* pushPhysicalInt32 */
		stack.pushInt32();
		return true;
	case 529: /* pushPhysicalInt64 */
		stack.pushInt64();
		return true;
	case 530: /* pushPhysicalPointer */
		stack.pushPointer();
		return true;
	case 531: /* pushPhysicalFloat32 */
		stack.pushFloat32();
		return true;
	case 532: /* pushPhysicalFloat64 */
		stack.pushFloat64();
		return true;
	case 533: /* callPhysical */
		return true;
	case 534: /* callInstruction */
		return true;
	}}// Sista extended bytecode set compilation.void SistaExtendedInstruction::compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder){ 	switch(getOpcode())	{	/* pushReceiverVariableSmallIndex */
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
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->fetchPointerofObject(getOpcode() & 15, getReceiverOopValue());        
			stack.pushOop(object);
		}
		break;
	/* pushLiteralVariableSmallIndex */
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
			llvm::Value *object;
            abort(); /* Should be implemented */        
			stack.pushOop(object);
		}
		break;
	/* pushLiteralSmallIndex */
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
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->fetchPointerofObject(getOpcode() & 31, getLiteralsOopValue());        
			stack.pushOop(object);
		}
		break;
	/* pushTempSmallIndex */
	case 64:
	case 65:
	case 66:
	case 67:
	case 68:
	case 69:
	case 70:
	case 71:
		{
			llvm::Value *object;
            object = builder.CreateLoad(getTemporalAt(getOpcode() & 7));        
			stack.pushOop(object);
		}
		break;
	/* pushTempSmallIndex2 */
	case 72:
	case 73:
	case 74:
	case 75:
		{
			llvm::Value *object;
            object = builder.CreateLoad(getTemporalAt((getOpcode() & 7) + 8));        
			stack.pushOop(object);
		}
		break;
	/* pushReceiver */
	case 76:
		{
			llvm::Value *object;
            object = getReceiverOopValue();        
			stack.pushOop(object);
		}
		break;
	/* pushTrue */
	case 77:
		{
			llvm::Value *object;
            object = getTrueOopValue();        
			stack.pushOop(object);
		}
		break;
	/* pushFalse */
	case 78:
		{
			llvm::Value *object;
            object = getFalseOopValue();        
			stack.pushOop(object);
		}
		break;
	/* pushNil */
	case 79:
		{
			llvm::Value *object;
            object = getNilOopValue();        
			stack.pushOop(object);
		}
		break;
	/* pushZero */
	case 80:
		{
			llvm::Value *object;
            object = getZeroOopValue();        
			stack.pushOop(object);
		}
		break;
	/* pushOne */
	case 81:
		{
			llvm::Value *object;
            object = getOneOopValue();        
			stack.pushOop(object);
		}
		break;
	/* pushThisContext */
	case 82:
		{
			llvm::Value *object;
abort();
			stack.pushOop(object);
		}
		break;
	/* dupTop */
	case 83:
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *dup1;
			llvm::Value *dup2;
            dup1 = object;            dup2 = object;        
			stack.pushOop(dup1);
			stack.pushOop(dup2);
		}
		break;
	/* returnReceiver */
	case 88:
		{
            returnOop(getReceiverOopValue());        
		}
		break;
	/* returnTrue */
	case 89:
		{
            returnOop(getTrueOopValue());        
		}
		break;
	/* returnFalse */
	case 90:
		{
            returnOop(getFalseOopValue());        
		}
		break;
	/* returnNil */
	case 91:
		{
            returnOop(getNilOopValue());        
		}
		break;
	/* returnTop */
	case 92:
		{
			llvm::Value *object = stack.popOop();
            returnOop(object);        
		}
		break;
	/* nop */
	case 95:
		{
            // Do nothing.        
		}
		break;
	/* sendSpecialMessageClass */
	case 119:
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *objectClass;
            objectClass = getLlvmInterpreterProxy()->fetchClassOf(object);            checkFailed();        
			stack.pushOop(objectClass);
		}
		break;
	/* popAndStoreTemp */
	case 208:
	case 209:
	case 210:
	case 211:
	case 212:
	case 213:
	case 214:
	case 215:
		{
			llvm::Value *object = stack.popOop();
            builder.CreateStore(object, getTemporalAt(getOpcode() & 7));        
		}
		break;
	/* popStackTop */
	case 216:
		{
			llvm::Value *object = stack.popOop();
            // Do Nothing        
		}
		break;
	default:		abort();	}}// Lowcode instruction compilation.void LowcodeInstruction::compile(LowcodeValueStack &stack, llvm::IRBuilder<> &builder){ 	switch(getOpcode())	{	case 256: /* duplicateInt32 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *dup1;
			llvm::Value *dup2;
            dup1 = value;            dup2 = value;        
			stack.pushInt32(dup1);
			stack.pushInt32(dup2);
		}
		break;
	case 257: /* duplicateInt64 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *dup1;
			llvm::Value *dup2;
            dup1 = value;            dup2 = value;        
			stack.pushInt64(dup1);
			stack.pushInt64(dup2);
		}
		break;
	case 258: /* duplicatePointer */
		{
			llvm::Value *value = stack.popPointer();
			llvm::Value *dup1;
			llvm::Value *dup2;
            dup1 = value;            dup2 = value;        
			stack.pushPointer(dup1);
			stack.pushPointer(dup2);
		}
		break;
	case 259: /* duplicateFloat32 */
		{
			llvm::Value *value = stack.popFloat32();
			llvm::Value *dup1;
			llvm::Value *dup2;
            dup1 = value;            dup2 = value;        
			stack.pushFloat32(dup1);
			stack.pushFloat32(dup2);
		}
		break;
	case 260: /* duplicateFloat64 */
		{
			llvm::Value *value = stack.popFloat64();
			llvm::Value *dup1;
			llvm::Value *dup2;
            dup1 = value;            dup2 = value;        
			stack.pushFloat64(dup1);
			stack.pushFloat64(dup2);
		}
		break;
	case 261: /* popInt32 */
		{
			llvm::Value *value = stack.popInt32();

		}
		break;
	case 262: /* popInt64 */
		{
			llvm::Value *value = stack.popInt64();

		}
		break;
	case 263: /* popPointer */
		{
			llvm::Value *value = stack.popPointer();

		}
		break;
	case 264: /* popFloat32 */
		{
			llvm::Value *value = stack.popFloat32();

		}
		break;
	case 265: /* popFloat64 */
		{
			llvm::Value *value = stack.popFloat64();

		}
		break;
	case 266: /* pushZero32 */
		{
			llvm::Value *result;
            result = builder.getInt32(0);        
			stack.pushInt32(result);
		}
		break;
	case 267: /* pushOne32 */
		{
			llvm::Value *result;
            result = builder.getInt32(1);        
			stack.pushInt32(result);
		}
		break;
	case 268: /* pushZero64 */
		{
			llvm::Value *result;
            result = builder.getInt64(0);        
			stack.pushInt64(result);
		}
		break;
	case 269: /* pushOne64 */
		{
			llvm::Value *result;
            result = builder.getInt64(1);        
			stack.pushInt64(result);
		}
		break;
	case 270: /* pushConstantUInt32 */
		{
			uint64_t constant = getExtendA();
			llvm::Value *result;
            result = builder.getInt32(constant);        
			stack.pushInt32(result);
		}
		break;
	case 271: /* pushConstantUInt64 */
		{
			uint64_t constant = getExtendA();
			llvm::Value *result;
            result = builder.getInt64(0);        
			stack.pushInt64(result);
		}
		break;
	case 272: /* pushZeroFloat32 */
		{
			llvm::Value *result;
            result = llvm::ConstantFP::get(builder.getFloatTy(), 0);        
			stack.pushFloat32(result);
		}
		break;
	case 273: /* pushOneFloat32 */
		{
			llvm::Value *result;
            result = llvm::ConstantFP::get(builder.getFloatTy(), 1);        
			stack.pushFloat32(result);
		}
		break;
	case 274: /* pushZeroFloat64 */
		{
			llvm::Value *result;
            result = llvm::ConstantFP::get(builder.getDoubleTy(), 0);        
			stack.pushFloat64(result);
		}
		break;
	case 275: /* pushOneFloat64 */
		{
			llvm::Value *result;
            result = llvm::ConstantFP::get(builder.getDoubleTy(), 1);        
			stack.pushFloat64(result);
		}
		break;
	case 276: /* pushNullPointer */
		{
			llvm::Value *result;
            result = llvm::ConstantPointerNull::get(builder.getInt8PtrTy());        
			stack.pushPointer(result);
		}
		break;
	case 277: /* pushSessionIdentifier */
		{
			llvm::Value *value;
            value = builder.getInt32(LowcodeLLVMContext::get().getSessionIdentifier());        
			stack.pushInt32(value);
		}
		break;
	case 278: /* checkSessionIdentifier */
		{
			uint64_t expectedSession = getExtendA();
			llvm::Value *value;
            value = builder.getInt32(expectedSession == LowcodeLLVMContext::get().getSessionIdentifier());        
			stack.pushInt32(value);
		}
		break;
	case 279: /* pointerOffset32 */
		{
			llvm::Value *offset = stack.popInt32();
			llvm::Value *base = stack.popPointer();
			llvm::Value *result;
            result = builder.CreateGEP(base, offset);        
			stack.pushPointer(result);
		}
		break;
	case 280: /* pointerOffset64 */
		{
			llvm::Value *offset = stack.popInt64();
			llvm::Value *base = stack.popPointer();
			llvm::Value *result;
            result = builder.CreateGEP(base, offset);        
			stack.pushPointer(result);
		}
		break;
	case 281: /* effectiveAddress32 */
		{
			llvm::Value *offset = stack.popInt32();
			llvm::Value *scale = stack.popInt32();
			llvm::Value *index = stack.popInt32();
			llvm::Value *base = stack.popPointer();
			llvm::Value *result;
            llvm::Value *newOffset = builder.CreateAdd(offset, builder.CreateMul(scale, index));            result = builder.CreateGEP(base, newOffset);        
			stack.pushPointer(result);
		}
		break;
	case 282: /* effectiveAddress64 */
		{
			llvm::Value *offset = stack.popInt64();
			llvm::Value *scale = stack.popInt64();
			llvm::Value *index = stack.popInt64();
			llvm::Value *base = stack.popPointer();
			llvm::Value *result;
            llvm::Value *newOffset = builder.CreateAdd(offset, builder.CreateMul(scale, index));            result = builder.CreateGEP(base, newOffset);        
			stack.pushPointer(result);
		}
		break;
	case 283: /* loadUInt8FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            value = builder.CreateZExt(builder.CreateLoad(pointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 284: /* loadUInt16FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt16PtrTy(builder.getContext()));            value = builder.CreateZExt(builder.CreateLoad(castedPointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 285: /* loadUInt32FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt32PtrTy(builder.getContext()));            value = builder.CreateLoad(castedPointer);        
			stack.pushInt32(value);
		}
		break;
	case 286: /* loadUInt64FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt64PtrTy(builder.getContext()));            value = builder.CreateLoad(castedPointer);        
			stack.pushInt64(value);
		}
		break;
	case 287: /* loadInt8FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            value = builder.CreateSExt(builder.CreateLoad(pointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 288: /* loadInt16FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt16PtrTy(builder.getContext()));            value = builder.CreateSExt(builder.CreateLoad(castedPointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 289: /* loadInt32FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt32PtrTy(builder.getContext()));            value = builder.CreateLoad(castedPointer);        
			stack.pushInt32(value);
		}
		break;
	case 290: /* loadInt64FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt64PtrTy(builder.getContext()));            value = builder.CreateLoad(castedPointer);        
			stack.pushInt64(value);
		}
		break;
	case 291: /* loadPointerFromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Type *pointerType = llvm::PointerType::getUnqual(llvm::Type::getInt8PtrTy(builder.getContext()));            llvm::Value *castedPointer = builder.CreatePointerCast(value, pointerType);            value = builder.CreateLoad(castedPointer);        
			stack.pushPointer(value);
		}
		break;
	case 292: /* loadFloat32FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getFloatPtrTy(builder.getContext()));            value = builder.CreateLoad(castedPointer);        
			stack.pushFloat32(value);
		}
		break;
	case 293: /* loadFloat64FromMemory */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *value;
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getDoublePtrTy(builder.getContext()));            value = builder.CreateLoad(castedPointer);        
			stack.pushFloat64(value);
		}
		break;
	case 294: /* storeInt8ToMemory */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *pointer = stack.popPointer();
            llvm::Value *castedValue = builder.CreateTrunc(value, builder.getInt8Ty());            builder.CreateStore(castedValue, pointer);        
		}
		break;
	case 295: /* storeInt16ToMemory */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *pointer = stack.popPointer();
            llvm::Value *castedValue = builder.CreateTrunc(value, builder.getInt16Ty());            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt16PtrTy(builder.getContext()));            builder.CreateStore(castedValue, castedPointer);        
		}
		break;
	case 296: /* storeInt32ToMemory */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *pointer = stack.popPointer();
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt32PtrTy(builder.getContext()));            builder.CreateStore(value, castedPointer);        
		}
		break;
	case 297: /* storeInt64ToMemory */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *pointer = stack.popPointer();
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getInt64PtrTy(builder.getContext()));            builder.CreateStore(value, castedPointer);        
		}
		break;
	case 298: /* storePointerToMemory */
		{
			llvm::Value *value = stack.popPointer();
			llvm::Value *memoryPointer = stack.popPointer();
            llvm::Type *pointerType = llvm::PointerType::getUnqual(llvm::Type::getInt8PtrTy(builder.getContext()));            llvm::Value *castedPointer = builder.CreatePointerCast(value, pointerType);            builder.CreateStore(value, castedPointer);        
		}
		break;
	case 299: /* storeFloat32ToMemory */
		{
			llvm::Value *value = stack.popFloat32();
			llvm::Value *pointer = stack.popPointer();
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getFloatPtrTy(builder.getContext()));            builder.CreateStore(value, castedPointer);        
		}
		break;
	case 300: /* storeFloat64ToMemory */
		{
			llvm::Value *value = stack.popFloat64();
			llvm::Value *pointer = stack.popPointer();
            llvm::Value *castedPointer = builder.CreatePointerCast(value, llvm::Type::getDoublePtrTy(builder.getContext()));            builder.CreateStore(value, castedPointer);        
		}
		break;
	case 301: /* loadLocalAddress */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *pointer;
            pointer = getLocalPointer(baseOffset);        
			stack.pushPointer(pointer);
		}
		break;
	case 302: /* loadLocalUInt8 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt8Ty());            value = builder.CreateZExt(builder.CreateLoad(pointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 303: /* loadLocalUInt16 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt16Ty());            value = builder.CreateZExt(builder.CreateLoad(pointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 304: /* loadLocalUInt32 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt32Ty());            value = builder.CreateLoad(pointer);        
			stack.pushInt32(value);
		}
		break;
	case 305: /* loadLocalUInt64 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt64Ty());            value = builder.CreateLoad(pointer);        
			stack.pushInt64(value);
		}
		break;
	case 306: /* loadLocalInt8 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt8Ty());            value = builder.CreateSExt(builder.CreateLoad(pointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 307: /* loadLocalInt16 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt16Ty());            value = builder.CreateSExt(builder.CreateLoad(pointer), builder.getInt32Ty());        
			stack.pushInt32(value);
		}
		break;
	case 308: /* loadLocalInt32 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt32Ty());            value = builder.CreateLoad(pointer);        
			stack.pushInt32(value);
		}
		break;
	case 309: /* loadLocalInt64 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt64Ty());            value = builder.CreateLoad(pointer);        
			stack.pushInt64(value);
		}
		break;
	case 310: /* loadLocalPointer */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt8PtrTy());            value = builder.CreateLoad(pointer);        
			stack.pushPointer(value);
		}
		break;
	case 311: /* loadLocalFloat32 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getFloatTy());            value = builder.CreateLoad(pointer);        
			stack.pushFloat32(value);
		}
		break;
	case 312: /* loadLocalFloat64 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value;
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getDoubleTy());            value = builder.CreateLoad(pointer);        
			stack.pushFloat64(value);
		}
		break;
	case 313: /* storeLocalInt8 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popInt32();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt8Ty());            builder.CreateStore(builder.CreateTrunc(value, builder.getInt8Ty()), pointer);        
		}
		break;
	case 314: /* storeLocalInt16 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popInt32();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt16Ty());            builder.CreateStore(builder.CreateTrunc(value, builder.getInt16Ty()), pointer);        
		}
		break;
	case 315: /* storeLocalInt32 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popInt32();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt32Ty());            builder.CreateStore(value, pointer);        
		}
		break;
	case 316: /* storeLocalInt64 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popInt64();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt64Ty());            builder.CreateStore(value, pointer);        
		}
		break;
	case 317: /* storeLocalPointer */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popPointer();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getInt8PtrTy());            builder.CreateStore(value, pointer);        
		}
		break;
	case 318: /* storeLocalFloat32 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popFloat32();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getFloatTy());            builder.CreateStore(value, pointer);        
		}
		break;
	case 319: /* storeLocalFloat64 */
		{
			uint64_t baseOffset = getExtendA();
			llvm::Value *value = stack.popFloat64();
            llvm::Value *pointer = getLocalPointerCasted(baseOffset, builder.getDoubleTy());            builder.CreateStore(value, pointer);        
		}
		break;
	case 320: /* signExtend32From8 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt8Ty());            result = builder.CreateSExt(small, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 321: /* signExtend32From16 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt16Ty());            result = builder.CreateSExt(small, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 322: /* signExtend64From8 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt8Ty());            result = builder.CreateSExt(small, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 323: /* signExtend64From16 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt16Ty());            result = builder.CreateSExt(small, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 324: /* signExtend64From32 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt32Ty());            result = builder.CreateSExt(small, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 325: /* zeroExtend32From8 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt8Ty());            result = builder.CreateZExt(small, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 326: /* zeroExtend32From16 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt16Ty());            result = builder.CreateZExt(small, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 327: /* zeroExtend64From8 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt8Ty());            result = builder.CreateZExt(small, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 328: /* zeroExtend64From16 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt16Ty());            result = builder.CreateZExt(small, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 329: /* zeroExtend64From32 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            llvm::Value *small = builder.CreateTrunc(value, builder.getInt32Ty());            result = builder.CreateZExt(small, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 330: /* truncate32To8 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateAnd(value, 0xFF);        
			stack.pushInt32(result);
		}
		break;
	case 331: /* truncate32To16 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateAnd(value, 0xFFFF);        
			stack.pushInt32(result);
		}
		break;
	case 332: /* truncate64To8 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateAnd(value, 0xFF);        
			stack.pushInt64(result);
		}
		break;
	case 333: /* truncate64To16 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateAnd(value, 0xFFFF);        
			stack.pushInt64(result);
		}
		break;
	case 334: /* truncate64To32 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateAnd(value, 0xFFFFFFFF);        
			stack.pushInt64(result);
		}
		break;
	case 335: /* uint32ToFloat32 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateUIToFP(value, builder.getFloatTy());        
			stack.pushFloat32(result);
		}
		break;
	case 336: /* uint32ToFloat64 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateUIToFP(value, builder.getDoubleTy());        
			stack.pushFloat64(result);
		}
		break;
	case 337: /* int32ToFloat32 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateSIToFP(value, builder.getFloatTy());        
			stack.pushFloat32(result);
		}
		break;
	case 338: /* int32ToFloat64 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateSIToFP(value, builder.getDoubleTy());        
			stack.pushFloat64(result);
		}
		break;
	case 339: /* uint64ToFloat32 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateUIToFP(value, builder.getFloatTy());        
			stack.pushFloat32(result);
		}
		break;
	case 340: /* uint64ToFloat64 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateUIToFP(value, builder.getDoubleTy());        
			stack.pushFloat64(result);
		}
		break;
	case 341: /* int64ToFloat32 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateSIToFP(value, builder.getFloatTy());        
			stack.pushFloat64(result);
		}
		break;
	case 342: /* int64ToFloat64 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateSIToFP(value, builder.getDoubleTy());        
			stack.pushFloat64(result);
		}
		break;
	case 343: /* float32ToInt32 */
		{
			llvm::Value *value = stack.popFloat32();
			llvm::Value *result;
            result = builder.CreateFPToSI(value, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 344: /* float64ToInt32 */
		{
			llvm::Value *value = stack.popFloat64();
			llvm::Value *result;
            result = builder.CreateFPToSI(value, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 345: /* float32ToInt64 */
		{
			llvm::Value *value = stack.popFloat32();
			llvm::Value *result;
            result = builder.CreateFPToSI(value, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 346: /* float64ToInt64 */
		{
			llvm::Value *value = stack.popFloat64();
			llvm::Value *result;
            result = builder.CreateFPToSI(value, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 347: /* pointerToInt32 */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *result;
            result = builder.CreatePtrToInt(pointer, builder.getInt32Ty());        
			stack.pushInt32(result);
		}
		break;
	case 348: /* pointerToInt64 */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *result;
            result = builder.CreatePtrToInt(pointer, builder.getInt64Ty());        
			stack.pushInt64(result);
		}
		break;
	case 349: /* int32ToPointer */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateIntToPtr(value, builder.getInt8PtrTy());        
			stack.pushPointer(result);
		}
		break;
	case 350: /* int64ToPointer */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreatePtrToInt(value, builder.getInt8PtrTy());        
			stack.pushPointer(result);
		}
		break;
	case 351: /* add32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateAdd(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 352: /* sub32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateSub(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 353: /* neg32 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateNeg(value);        
			stack.pushInt32(result);
		}
		break;
	case 354: /* mul32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateMul(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 355: /* umul32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateMul(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 356: /* div32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateSDiv(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 357: /* udiv32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateUDiv(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 358: /* rem32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateSRem(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 359: /* urem32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateURem(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 360: /* add64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateAdd(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 361: /* sub64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateSub(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 362: /* neg64 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateNeg(value);        
			stack.pushInt64(result);
		}
		break;
	case 363: /* mul64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateMul(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 364: /* umul64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateMul(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 365: /* div64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateSDiv(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 366: /* udiv64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateUDiv(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 367: /* rem64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateSRem(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 368: /* urem64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateURem(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 369: /* not32 */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateNot(value);        
			stack.pushInt32(result);
		}
		break;
	case 370: /* and32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateAnd(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 371: /* or32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateOr(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 372: /* xor32 */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateXor(first, second);        
			stack.pushInt32(result);
		}
		break;
	case 373: /* leftShift32 */
		{
			llvm::Value *shiftAmount = stack.popInt32();
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateShl(value, shiftAmount);        
			stack.pushInt32(result);
		}
		break;
	case 374: /* rightShift32 */
		{
			llvm::Value *shiftAmount = stack.popInt32();
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateLShr(value, shiftAmount);        
			stack.pushInt32(result);
		}
		break;
	case 375: /* arithmeticRightShift32 */
		{
			llvm::Value *shiftAmount = stack.popInt32();
			llvm::Value *value = stack.popInt32();
			llvm::Value *result;
            result = builder.CreateAShr(value, shiftAmount);        
			stack.pushInt32(result);
		}
		break;
	case 376: /* not64 */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateNot(value);        
			stack.pushInt64(result);
		}
		break;
	case 377: /* and64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateAnd(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 378: /* or64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateOr(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 379: /* xor64 */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateXor(first, second);        
			stack.pushInt64(result);
		}
		break;
	case 380: /* leftShift64 */
		{
			llvm::Value *shiftAmount = stack.popInt64();
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateShl(value, shiftAmount);        
			stack.pushInt64(result);
		}
		break;
	case 381: /* rightShift64 */
		{
			llvm::Value *shiftAmount = stack.popInt64();
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateLShr(value, shiftAmount);        
			stack.pushInt64(result);
		}
		break;
	case 382: /* arithmeticRightShift64 */
		{
			llvm::Value *shiftAmount = stack.popInt64();
			llvm::Value *value = stack.popInt64();
			llvm::Value *result;
            result = builder.CreateAShr(value, shiftAmount);        
			stack.pushInt64(result);
		}
		break;
	case 383: /* float32Add */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *result;
            result = builder.CreateFAdd(first, second);        
			stack.pushFloat32(result);
		}
		break;
	case 384: /* float32Sub */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *result;
            result = builder.CreateFSub(first, second);        
			stack.pushFloat32(result);
		}
		break;
	case 385: /* float32Mul */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *result;
            result = builder.CreateFMul(first, second);        
			stack.pushFloat32(result);
		}
		break;
	case 386: /* float32Div */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *result;
            result = builder.CreateFDiv(first, second);        
			stack.pushFloat32(result);
		}
		break;
	case 387: /* float64Add */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *result;
            result = builder.CreateFAdd(first, second);        
			stack.pushFloat64(result);
		}
		break;
	case 388: /* float64Sub */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *result;
            result = builder.CreateFSub(first, second);        
			stack.pushFloat64(result);
		}
		break;
	case 389: /* float64Mul */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *result;
            result = builder.CreateFMul(first, second);        
			stack.pushFloat64(result);
		}
		break;
	case 390: /* float64Div */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *result;
            result = builder.CreateFDiv(first, second);        
			stack.pushFloat64(result);
		}
		break;
	case 391: /* pin */
		{
			llvm::Value *object = stack.popOop();
abort();
		}
		break;
	case 392: /* unpin */
		{
			llvm::Value *object = stack.popOop();
abort();
		}
		break;
	case 393: /* oopToPointer */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *pointer;
            llvm::Value *indexablePtr = getLlvmInterpreterProxy()->firstIndexableField(object);            llvm::Type *ptrType = llvm::PointerType::getUnqual(builder.getInt8PtrTy());            pointer = builder.CreateLoad(builder.CreatePointerCast(indexablePtr, ptrType));        
			stack.pushPointer(pointer);
		}
		break;
	case 394: /* oopToPointerReinterpret */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *pointer;
            pointer = builder.CreateIntToPtr(object, builder.getInt8PtrTy());        
			stack.pushPointer(pointer);
		}
		break;
	case 395: /* pointerToOop */
		{
			llvm::Value *pointerClassLiteral = getLiteralAt(getExtendA());
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->instantiateClassindexableSize(pointerClassLiteral, sizeof(void*));            checkFailed();            llvm::Value *content = getLlvmInterpreterProxy()->firstIndexableField(object);            llvm::Type *pointerType = llvm::PointerType::getUnqual(builder.getInt8PtrTy());            builder.CreateStore(pointer, builder.CreatePointerCast(content, pointerType));        
			stack.pushOop(object);
		}
		break;
	case 396: /* pointerToOopReinterprer */
		{
			llvm::Value *pointer = stack.popPointer();
			llvm::Value *object;
            object = builder.CreatePtrToInt(pointer, LowcodeLLVMContext::get().getSqIntType());        
			stack.pushOop(object);
		}
		break;
	case 397: /* instantiateOop */
		{
			llvm::Value *classOop = stack.popOop();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->instantiateClassindexableSize(classOop, 0);        
			stack.pushOop(object);
		}
		break;
	case 398: /* instantiateIndexableOop */
		{
			uint64_t indexableSize = getExtendA();
			llvm::Value *classOop = stack.popOop();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->instantiateClassindexableSize(classOop, indexableSize);        
			stack.pushOop(object);
		}
		break;
	case 399: /* instantiateIndexable32Oop */
		{
			llvm::Value *indexableSize = stack.popInt32();
			llvm::Value *classOop = stack.popOop();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->instantiateClassindexableSize(classOop, indexableSize);        
			stack.pushOop(object);
		}
		break;
	case 400: /* oopToBoolean32 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->booleanValueOf(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 401: /* oopToBoolean64 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->booleanValueOf(object), builder.getInt64Ty(), false);        
			stack.pushInt64(value);
		}
		break;
	case 402: /* oopSmallIntegerToInt32 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->integerValueOf(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 403: /* oopToInt32 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->signed32BitValueOf(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 404: /* oopToUInt32 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->positive32BitValueOf(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 405: /* oopSmallIntegerToInt64 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->integerValueOf(object), builder.getInt64Ty(), false);        
			stack.pushInt64(value);
		}
		break;
	case 406: /* oopToInt64 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->signed64BitValueOf(object), builder.getInt64Ty(), false);        
			stack.pushInt64(value);
		}
		break;
	case 407: /* oopToUInt64 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateIntCast(getLlvmInterpreterProxy()->positive64BitValueOf(object), builder.getInt64Ty(), false);        
			stack.pushInt64(value);
		}
		break;
	case 408: /* oopToFloat32 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = builder.CreateFPCast(getLlvmInterpreterProxy()->floatValueOf(object), builder.getFloatTy());        
			stack.pushFloat32(value);
		}
		break;
	case 409: /* oopToFloat64 */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            object = getLlvmInterpreterProxy()->floatValueOf(object);        
			stack.pushFloat64(value);
		}
		break;
	case 410: /* boolean32ToOop */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *object;
            llvm::Value *cond = builder.CreateICmpNE(value, builder.getInt32(0));            object = builder.CreateSelect(cond, getTrueOopValue(), getFalseOopValue());        
			stack.pushOop(object);
		}
		break;
	case 411: /* boolean64ToOop */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *object;
            llvm::Value *cond = builder.CreateICmpNE(value, builder.getInt64(0));            object = builder.CreateSelect(cond, getTrueOopValue(), getFalseOopValue());        
			stack.pushOop(object);
		}
		break;
	case 412: /* smallInt32ToOop */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->integerObjectOf(value);        
			stack.pushOop(object);
		}
		break;
	case 413: /* int32ToOop */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->signed32BitIntegerFor(value);        
			stack.pushOop(object);
		}
		break;
	case 414: /* uint32ToOop */
		{
			llvm::Value *value = stack.popInt32();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->positive32BitIntegerFor(value);        
			stack.pushOop(object);
		}
		break;
	case 415: /* int64ToOop */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->signed64BitIntegerFor(value);        
			stack.pushOop(object);
		}
		break;
	case 416: /* uint64ToOop */
		{
			llvm::Value *value = stack.popInt64();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->positive64BitIntegerFor(value);        
			stack.pushOop(object);
		}
		break;
	case 417: /* float32ToOop */
		{
			llvm::Value *value = stack.popFloat32();
			llvm::Value *object;
            object = builder.CreateFPCast(getLlvmInterpreterProxy()->floatObjectOf(value), builder.getFloatTy());        
			stack.pushOop(object);
		}
		break;
	case 418: /* float64ToOop */
		{
			llvm::Value *value = stack.popFloat64();
			llvm::Value *object;
            object = getLlvmInterpreterProxy()->signed32BitIntegerFor(value);        
			stack.pushOop(object);
		}
		break;
	case 419: /* loadObjectField */
		{
			uint64_t fieldIndex = getExtendA();
			llvm::Value *object = stack.popOop();
			llvm::Value *field;
            field = getLlvmInterpreterProxy()->fetchPointerofObject(fieldIndex, object);        
			stack.pushOop(field);
		}
		break;
	case 420: /* storeObjectField */
		{
			uint64_t fieldIndex = getExtendA();
			llvm::Value *value = stack.popOop();
			llvm::Value *object = stack.popOop();
            getLlvmInterpreterProxy()->storePointerofObjectwithValue(fieldIndex, object, value);        
		}
		break;
	case 421: /* loadObjectAt */
		{
			llvm::Value *fieldIndex = stack.popInt32();
			llvm::Value *object = stack.popOop();
			llvm::Value *field;
            field = getLlvmInterpreterProxy()->fetchPointerofObject(fieldIndex, object);        
			stack.pushOop(field);
		}
		break;
	case 422: /* storeObjectFieldAt */
		{
			llvm::Value *value = stack.popOop();
			llvm::Value *fieldIndex = stack.popInt32();
			llvm::Value *object = stack.popOop();
            getLlvmInterpreterProxy()->storePointerofObjectwithValue(fieldIndex, object, value);        
		}
		break;
	case 423: /* firstFieldPointer */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *pointer;
            pointer = getLlvmInterpreterProxy()->firstFixedField(object);        
			stack.pushPointer(pointer);
		}
		break;
	case 424: /* firstIndexableFieldPointer */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *pointer;
            pointer = getLlvmInterpreterProxy()->firstIndexableField(object);        
			stack.pushPointer(pointer);
		}
		break;
	case 425: /* byteSizeOf */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = getLlvmInterpreterProxy()->byteSizeOf(object);        
			stack.pushInt32(value);
		}
		break;
	case 426: /* isBytes */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isBytes(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 427: /* isFloatObject */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isFloatObject(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 428: /* isIndexable */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isIndexable(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 429: /* isIntegerObject */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isIntegerObject(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 430: /* isWords */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isWords(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 431: /* isWordsOrBytes */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isWordsOrBytes(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 432: /* isPointers */
		{
			llvm::Value *object = stack.popOop();
			llvm::Value *value;
            value = builder.CreateIntCast(getLlvmInterpreterProxy()->isPointers(object), builder.getInt32Ty(), false);        
			stack.pushInt32(value);
		}
		break;
	case 433: /* pointerEqual */
		{
			llvm::Value *second = stack.popPointer();
			llvm::Value *first = stack.popPointer();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpEQ(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 434: /* pointerNotEqual */
		{
			llvm::Value *second = stack.popPointer();
			llvm::Value *first = stack.popPointer();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpNE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 435: /* oopEqual */
		{
			llvm::Value *second = stack.popOop();
			llvm::Value *first = stack.popOop();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpEQ(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 436: /* oopNotEqual */
		{
			llvm::Value *second = stack.popOop();
			llvm::Value *first = stack.popOop();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpNE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 437: /* int32Equal */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpEQ(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 438: /* int32NotEqual */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpNE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 439: /* int32Less */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSLT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 440: /* int32LessEqual */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSLE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 441: /* int32Great */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSGT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 442: /* int32GreatEqual */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSGE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 443: /* uint32Less */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpULT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 444: /* uint32LessEqual */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpULE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 445: /* uint32Great */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpUGT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 446: /* uint32GreatEqual */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpUGE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 447: /* int64Equal */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpEQ(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 448: /* int64NotEqual */
		{
			llvm::Value *second = stack.popInt32();
			llvm::Value *first = stack.popInt32();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpNE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 449: /* int64Less */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSLT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 450: /* int64LessEqual */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSLE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 451: /* int64Great */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSGT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 452: /* int64GreatEqual */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpSGE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 453: /* uint64Less */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpULT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 454: /* uint64LessEqual */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpULE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 455: /* uint64Great */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpUGT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 456: /* uint64GreatEqual */
		{
			llvm::Value *second = stack.popInt64();
			llvm::Value *first = stack.popInt64();
			llvm::Value *value;
            value = condToInt32(builder.CreateICmpUGE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 457: /* float32Equal */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOEQ(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 458: /* float32NotEqual */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpONE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 459: /* float32Less */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOLT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 460: /* float32LessEqual */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOLE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 461: /* float32Great */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOGT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 462: /* float32GreatEqual */
		{
			llvm::Value *second = stack.popFloat32();
			llvm::Value *first = stack.popFloat32();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOGE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 463: /* float64Equal */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOEQ(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 464: /* float64NotEqual */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpONE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 465: /* float64Less */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOLT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 466: /* float64LessEqual */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOLE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 467: /* float64Great */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOGT(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 468: /* float64GreatEqual */
		{
			llvm::Value *second = stack.popFloat64();
			llvm::Value *first = stack.popFloat64();
			llvm::Value *value;
            value = condToInt32(builder.CreateFCmpOGE(first, second));        
			stack.pushInt32(value);
		}
		break;
	case 469: /* jump */
		{
            builder.CreateBr(getJumpBlock()->getLlvmBasicBlock());        
		}
		break;
	case 470: /* branchTrue32 */
		{
			llvm::Value *cond = stack.popInt32();
            llvm::Value *boolCond = builder.CreateICmpNE(cond, builder.getInt32(0));            builder.CreateCondBr(boolCond, getBranchBlock()->getLlvmBasicBlock(),                                    getNextBlock()->getLlvmBasicBlock());        
		}
		break;
	case 471: /* branchFalse32 */
		{
			llvm::Value *cond = stack.popInt32();
            llvm::Value *boolCond = builder.CreateICmpEQ(cond, builder.getInt32(0));            builder.CreateCondBr(boolCond, getBranchBlock()->getLlvmBasicBlock(),                                    getNextBlock()->getLlvmBasicBlock());        
		}
		break;
	case 472: /* branchTrue64 */
		{
			llvm::Value *cond = stack.popInt64();
            llvm::Value *boolCond = builder.CreateICmpNE(cond, builder.getInt64(0));            builder.CreateCondBr(boolCond, getBranchBlock()->getLlvmBasicBlock(),                                    getNextBlock()->getLlvmBasicBlock());        
		}
		break;
	case 473: /* branchFalse64 */
		{
			llvm::Value *cond = stack.popInt32();
            llvm::Value *boolCond = builder.CreateICmpEQ(cond, builder.getInt64(0));            builder.CreateCondBr(boolCond, getBranchBlock()->getLlvmBasicBlock(),                                    getNextBlock()->getLlvmBasicBlock());        
		}
		break;
	case 478: /* returnSmallInteger */
		{
			llvm::Value *value = stack.popInt32();
            llvm::Value *smallInteger = builder.CreateOr(builder.CreateShl(value, 1), builder.getInt32(1));            returnOop(smallInteger);        
		}
		break;
	case 479: /* returnBoolean32AsOop */
		{
			llvm::Value *value = stack.popInt32();
            llvm::Value *cond = builder.CreateICmpNE(value, builder.getInt32(0));            llvm::Value *oop = builder.CreateSelect(cond, getTrueOopValue(), getFalseOopValue());            returnOop(oop);        
		}
		break;
	case 480: /* returnBoolean64AsOop */
		{
			llvm::Value *value = stack.popInt64();
            llvm::Value *cond = builder.CreateICmpNE(value, builder.getInt64(0));            llvm::Value *oop = builder.CreateSelect(cond, getTrueOopValue(), getFalseOopValue());            returnOop(oop);        
		}
		break;
	case 481: /* returnInt32AsOop */
		{
			llvm::Value *value = stack.popInt32();
            returnOop(getLlvmInterpreterProxy()->signed32BitIntegerFor(value));        
		}
		break;
	case 482: /* returnInt64AsOop */
		{
			llvm::Value *value = stack.popInt64();
            returnOop(getLlvmInterpreterProxy()->signed64BitIntegerFor(value));        
		}
		break;
	case 483: /* returnUInt32AsOop */
		{
			llvm::Value *value = stack.popInt32();
            returnOop(getLlvmInterpreterProxy()->positive32BitIntegerFor(value));        
		}
		break;
	case 484: /* returnUInt64AsOop */
		{
			llvm::Value *value = stack.popInt64();
            returnOop(getLlvmInterpreterProxy()->positive64BitIntegerFor(value));        
		}
		break;
	case 485: /* returnPointerAsOop */
		{
			llvm::Value *pointerClassLiteral = getLiteralAt(getExtendA());
			llvm::Value *pointer = stack.popPointer();
abort();
		}
		break;
	case 486: /* returnFloat32AsOop */
		{
			llvm::Value *value = stack.popFloat32();
            llvm::Value *float64Value = builder.CreateFPCast(value, builder.getDoubleTy());            returnOop(getLlvmInterpreterProxy()->floatObjectOf(float64Value));        
		}
		break;
	case 487: /* returnFloat64AsOop */
		{
			llvm::Value *value = stack.popFloat64();
            returnOop(getLlvmInterpreterProxy()->floatObjectOf(value));        
		}
		break;
	case 488: /* fail */
		{
            builder.CreateRet(getLlvmInterpreterProxy()->primitiveFail());        
		}
		break;
	case 489: /* failWithCode */
		{
			uint64_t errorCode = getExtendA();
            builder.CreateRet(getLlvmInterpreterProxy()->primitiveFailFor(errorCode));        
		}
		break;
	case 490: /* lockVM */
		{
abort();
		}
		break;
	case 491: /* unlockVM */
		{
abort();
		}
		break;
	case 492: /* compareAndSwap32 */
		{
			llvm::Value *newValue = stack.popInt32();
			llvm::Value *oldValue = stack.popInt32();
			llvm::Value *check = stack.popPointer();
			llvm::Value *value;
            value = builder.CreateAtomicCmpXchg(check, oldValue, newValue, llvm::Monotonic);        
			stack.pushInt32(value);
		}
		break;
	case 493: /* alloca32 */
		{
			llvm::Value *size = stack.popInt32();
			llvm::Value *pointer;
            pointer = builder.CreateAlloca(builder.getInt8Ty(), size);        
			stack.pushPointer(pointer);
		}
		break;
	case 494: /* alloca64 */
		{
			llvm::Value *size = stack.popInt64();
			llvm::Value *pointer;
            pointer = builder.CreateAlloca(builder.getInt8Ty(), size);        
			stack.pushPointer(pointer);
		}
		break;
	case 495: /* malloc32 */
		{
			llvm::Value *size = stack.popInt32();
			llvm::Value *pointer;
            pointer = builder.CreateCall(getMallocFunction(), size);        
			stack.pushPointer(pointer);
		}
		break;
	case 496: /* malloc64 */
		{
			llvm::Value *size = stack.popInt64();
			llvm::Value *pointer;
            pointer = builder.CreateCall(getMallocFunction(), size);        
			stack.pushPointer(pointer);
		}
		break;
	case 497: /* free */
		{
			llvm::Value *pointer = stack.popPointer();
            builder.CreateCall(getFreeFunction(), pointer);        
		}
		break;
	case 498: /* memcpyFixed */
		{
			uint64_t size = getExtendA();
			llvm::Value *source = stack.popPointer();
			llvm::Value *dest = stack.popPointer();
            builder.CreateMemCpy(dest, source, size, 1);        
		}
		break;
	case 499: /* memcpy32 */
		{
			llvm::Value *size = stack.popInt32();
			llvm::Value *source = stack.popPointer();
			llvm::Value *dest = stack.popPointer();
            builder.CreateMemCpy(dest, source, size, 1);        
		}
		break;
	case 500: /* memcpy64 */
		{
			llvm::Value *size = stack.popInt64();
			llvm::Value *source = stack.popPointer();
			llvm::Value *dest = stack.popPointer();
            builder.CreateMemCpy(dest, source, size, 1);        
		}
		break;
	case 501: /* beginCall */
		{
			uint64_t alignment = getExtendA();
            beginCall(alignment);        
		}
		break;
	case 502: /* callArgumentInt32 */
		{
			llvm::Value *value = stack.popInt32();
            callArgumentInt32(value);        
		}
		break;
	case 503: /* callArgumentInt64 */
		{
			llvm::Value *value = stack.popInt32();
            callArgumentInt64(value);        
		}
		break;
	case 504: /* callArgumentPointer */
		{
			llvm::Value *value = stack.popPointer();
            callArgumentPointer(value);        
		}
		break;
	case 505: /* callArgumentStructure */
		{
			uint64_t structureSize = getExtendA();
			llvm::Value *structurePointer = stack.popPointer();
            callArgumentStructure(structureSize, structurePointer);        
		}
		break;
	case 506: /* callArgumentFloat32 */
		{
			llvm::Value *value = stack.popFloat32();
            callArgumentFloat32(value);        
		}
		break;
	case 507: /* callArgumentFloat64 */
		{
			llvm::Value *value = stack.popFloat64();
            callArgumentFloat64(value);        
		}
		break;
	case 508: /* performCallInt32 */
		{
			uint64_t function = getExtendA();
			llvm::Value *result;
            performCall(builder.getInt32Ty(), function);        
			stack.pushInt32(result);
		}
		break;
	case 509: /* performCallInt64 */
		{
			uint64_t function = getExtendA();
			llvm::Value *result;
            performCall(builder.getInt64Ty(), function);        
			stack.pushInt64(result);
		}
		break;
	case 510: /* performCallPointer */
		{
			uint64_t function = getExtendA();
			llvm::Value *result;
            performCall(builder.getInt8PtrTy(), function);        
			stack.pushPointer(result);
		}
		break;
	case 511: /* performCallFloat32 */
		{
			uint64_t function = getExtendA();
			llvm::Value *result;
            performCall(builder.getFloatTy(), function);        
			stack.pushFloat32(result);
		}
		break;
	case 512: /* performCallFloat64 */
		{
			uint64_t function = getExtendA();
			llvm::Value *result;
            performCall(builder.getDoubleTy(), function);        
			stack.pushFloat64(result);
		}
		break;
	case 513: /* performCallIndirectInt32 */
		{
			llvm::Value *function = stack.popPointer();
			llvm::Value *result;
            performCallIndirect(builder.getInt32Ty(), function);        
			stack.pushInt32(result);
		}
		break;
	case 514: /* performCallIndirectInt64 */
		{
			llvm::Value *function = stack.popPointer();
			llvm::Value *result;
            performCallIndirect(builder.getInt64Ty(), function);        
			stack.pushInt64(result);
		}
		break;
	case 515: /* performCallIndirectPointer */
		{
			llvm::Value *function = stack.popPointer();
			llvm::Value *result;
            performCallIndirect(builder.getInt8PtrTy(), function);        
			stack.pushPointer(result);
		}
		break;
	case 516: /* performCallIndirectFloat32 */
		{
			llvm::Value *function = stack.popPointer();
			llvm::Value *result;
            performCallIndirect(builder.getFloatTy(), function);        
			stack.pushFloat32(result);
		}
		break;
	case 517: /* performCallIndirectFloat64 */
		{
			llvm::Value *function = stack.popPointer();
			llvm::Value *result;
            performCallIndirect(builder.getDoubleTy(), function);        
			stack.pushFloat64(result);
		}
		break;
	case 518: /* endCall */
		{
            endCall();        
		}
		break;
	case 519: /* endCallNoCleanup */
		{
            endCallNoCleanup();        
		}
		break;
	case 520: /* plaftormCode */
		{
			llvm::Value *code;
abort();
			stack.pushInt32(code);
		}
		break;
	case 521: /* lockRegisters */
		{
abort();
		}
		break;
	case 522: /* unlockRegisters */
		{
abort();
		}
		break;
	case 523: /* moveInt32ToPhysical */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value = stack.popInt32();
abort();
		}
		break;
	case 524: /* moveInt64ToPhysical */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value = stack.popInt64();
abort();
		}
		break;
	case 525: /* movePointerToPhysical */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value = stack.popPointer();
abort();
		}
		break;
	case 526: /* moveFloat32ToPhysical */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value = stack.popFloat32();
abort();
		}
		break;
	case 527: /* moveFloat64ToPhysical */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value = stack.popFloat64();
abort();
		}
		break;
	case 528: /* pushPhysicalInt32 */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value;
abort();
			stack.pushInt32(value);
		}
		break;
	case 529: /* pushPhysicalInt64 */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value;
abort();
			stack.pushInt64(value);
		}
		break;
	case 530: /* pushPhysicalPointer */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value;
abort();
			stack.pushPointer(value);
		}
		break;
	case 531: /* pushPhysicalFloat32 */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value;
abort();
			stack.pushFloat32(value);
		}
		break;
	case 532: /* pushPhysicalFloat64 */
		{
			uint64_t registerID = getExtendA();
			llvm::Value *value;
abort();
			stack.pushFloat64(value);
		}
		break;
	case 533: /* callPhysical */
		{
			uint64_t registerID = getExtendA();
abort();
		}
		break;
	case 534: /* callInstruction */
		{
			uint64_t function = getExtendA();
abort();
		}
		break;
	default:		abort();	}}} // namespace Lowcode
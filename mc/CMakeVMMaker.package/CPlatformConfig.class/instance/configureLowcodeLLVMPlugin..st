plugin extra rules
configureLowcodeLLVMPlugin: maker 
	"extra rules for Lowcode LLVM plugin"
	maker puts: '
set(LLVM_LIBRARY "LLVM-3.2")
execute_process(COMMAND llvm-config-3.2 --includedir OUTPUT_VARIABLE LLVM_INCLUDE_DIR)
execute_process(COMMAND llvm-config-3.2 --ldflags OUTPUT_VARIABLE LLVM_LDFLAGS)
#message(STATUS "incdir ${LLVM_INCLUDE_DIR}")
#message(STATUS "ldflags ${LLVM_LDFLAGS}")

include_directories(${LLVM_INCLUDE_DIR})
add_definitions(-D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS)
#set(linkFlags "${LLVM_LDFLAGS} ${linkFlags}")
'.

	maker addExternalLibrary: '${LLVM_LIBRARY}'.
	maker addCrossSources:
		#( 'LowcodeLLVMGenerated.cpp'
		'LowcodeLLVMCommon.cpp'
		'LowcodeLLVMInterpreterProxy.cpp'
		'LowcodeBasicBlock.cpp'
		'LowcodeMethod.cpp'
		'LowcodeInstruction.cpp').

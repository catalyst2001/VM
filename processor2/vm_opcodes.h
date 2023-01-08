#pragma once

enum VCPU_OPCODES
{
	OP_NOP = 0,

	OP_MOV_A_CONST,
	OP_MOV_B_CONST,
	OP_MOV_C_CONST,
	OP_MOV_D_CONST,
	OP_MOV_A_B,
	OP_MOV_A_C,
	OP_MOV_A_D,
	OP_MOV_B_A,
	OP_MOV_B_C,
	OP_MOV_B_D,
	OP_MOV_C_A,
	OP_MOV_C_B,
	OP_MOV_C_D,
	OP_MOV_D_A,
	OP_MOV_D_B,
	OP_MOV_D_C,
	//OP_MOV_M_A,
	//OP_MOV_M_B,
	//OP_MOV_M_C,
	//OP_MOV_M_D,

	OP_XCH_A_B,
	OP_XCH_A_C,
	OP_XCH_A_D,
	OP_XCH_B_A,
	OP_XCH_B_C,
	OP_XCH_B_D,
	OP_XCH_C_A,
	OP_XCH_C_B,
	OP_XCH_C_D,
	OP_XCH_D_A,
	OP_XCH_D_B,
	OP_XCH_D_C,

	OP_ADD_A_CONST,
	OP_ADD_B_CONST,
	OP_ADD_C_CONST,
	OP_ADD_D_CONST,
	OP_ADD_A_A,
	OP_ADD_A_B,
	OP_ADD_A_C,
	OP_ADD_A_D,
	OP_ADD_B_A,
	OP_ADD_B_B,
	OP_ADD_B_C,
	OP_ADD_B_D,
	OP_ADD_C_A,
	OP_ADD_C_B,
	OP_ADD_C_C,
	OP_ADD_C_D,
	OP_ADD_D_A,
	OP_ADD_D_B,
	OP_ADD_D_C,
	OP_ADD_D_D,

	OP_SUB_A_CONST,
	OP_SUB_B_CONST,
	OP_SUB_C_CONST,
	OP_SUB_D_CONST,
	OP_SUB_A_A,
	OP_SUB_A_B,
	OP_SUB_A_C,
	OP_SUB_A_D,
	OP_SUB_B_A,
	OP_SUB_B_B,
	OP_SUB_B_C,
	OP_SUB_B_D,
	OP_SUB_C_A,
	OP_SUB_C_B,
	OP_SUB_C_C,
	OP_SUB_C_D,
	OP_SUB_D_A,
	OP_SUB_D_B,
	OP_SUB_D_C,
	OP_SUB_D_D,

	OP_CMP_A_CONST,
	OP_CMP_B_CONST,
	OP_CMP_C_CONST,
	OP_CMP_D_CONST,
	OP_CMP_A_B,
	OP_CMP_A_C,
	OP_CMP_A_D,
	OP_CMP_B_A,
	OP_CMP_B_C,
	OP_CMP_B_D,
	OP_CMP_C_A,
	OP_CMP_C_B,
	OP_CMP_C_D,
	OP_CMP_D_A,
	OP_CMP_D_B,
	OP_CMP_D_C,

	OP_AND_A_CONST,
	OP_AND_B_CONST,
	OP_AND_C_CONST,
	OP_AND_D_CONST,
	OP_AND_A_B,
	OP_AND_A_C,
	OP_AND_A_D,
	OP_AND_B_A,
	OP_AND_B_C,
	OP_AND_B_D,
	OP_AND_C_A,
	OP_AND_C_B,
	OP_AND_C_D,
	OP_AND_D_A,
	OP_AND_D_B,
	OP_AND_D_C,

	OP_PUSH_CONST,
	OP_PUSH_A,
	OP_PUSH_B,
	OP_PUSH_C,
	OP_PUSH_D,

	OP_POP,
	OP_POP_A,
	OP_POP_B,
	OP_POP_C,
	OP_POP_D,

	OP_JMP_CONST,
	OP_JMP_A,
	OP_JMP_B,
	OP_JMP_C,
	OP_JMP_D,

	OP_JNZ_CONST,
	OP_JNZ_B,
	OP_JNZ_C,
	OP_JNZ_D,

	OP_JZ_CONST,
	OP_JZ_B,
	OP_JZ_C,
	OP_JZ_D,

	OP_JE_CONST,
	OP_JE_A,
	OP_JE_B,
	OP_JE_C,
	OP_JE_D,

	OP_JNE_CONST,
	OP_JNE_A,
	OP_JNE_B,
	OP_JNE_C,
	OP_JNE_D,

	OP_JL_CONST,
	OP_JL_A,
	OP_JL_B,
	OP_JL_C,
	OP_JL_D,

	OP_JLE_CONST,
	OP_JLE_A,
	OP_JLE_B,
	OP_JLE_C,
	OP_JLE_D,

	OP_JG_CONST,
	OP_JG_A,
	OP_JG_B,
	OP_JG_C,
	OP_JG_D,

	OP_JGE_CONST,
	OP_JGE_A,
	OP_JGE_B,
	OP_JGE_C,
	OP_JGE_D,

	OP_CALL_CONST,
	OP_CALL_A,
	OP_CALL_B,
	OP_CALL_C,
	OP_CALL_D,

	OP_INC_A,
	OP_INC_B,
	OP_INC_C,
	OP_INC_D,

	OP_DEC_A,
	OP_DEC_B,
	OP_DEC_C,
	OP_DEC_D,

	//OP_ECALL_CONST,
	//OP_ECALL_A,
	//OP_ECALL_B,
	//OP_ECALL_C,
	//OP_ECALL_D,

	OP_RET,

	MAX_OPCODES,

	// special opcodes
	OP_BRK, //debug
	OP_HALT
};
/*
===============================================
 Virtual CPU Definitions

 Virtual processor definition and opcode file

 Author: Deryabin K.
 Date: 07.01.2023
===============================================
*/
#pragma once

/* FLAGS register */
#define CPUF_CF 0b10000000
#define CPUF_PF 0b01000000
#define CPUF_AF 0b00100000
#define CPUF_ZF 0b00010000
#define CPUF_SF 0b00001000
#define CPUF_TF 0b00000100
#define CPUF_OF 0b00000010

#define GEN(x) x, //generated insructions
#define UNGEN(x) //ungenerated instructions

/* Virtual CPU opcodes */
enum OPCODES {
	GEN(OP_NOP) //not an operation
	GEN(OP_MOV) //move
	GEN(OP_SUB) //subtract
	GEN(OP_SUBC) //subtract constant
	GEN(OP_ADD) //addition
	GEN(OP_ADDC) //addition constant
	GEN(OP_MUL) //multiplication
	GEN(OP_DIV) //division
	GEN(OP_PUSH) //push to stack
	GEN(OP_POP) //pop from stack (GENERAL_SUBCODES)
	GEN(OP_INC) //increment (GENERAL_SUBCODES)
	GEN(OP_DEC) //decrement (GENERAL_SUBCODES)
	GEN(OP_SHL) //logic shift left
	GEN(OP_SHR) //logic shift right
	UNGEN(OP_SAL) //arithmetical shift left
	UNGEN(OP_SAR) //arithmetical shift right
	UNGEN(OP_BT) //bit check
	UNGEN(OP_BTC) //bit check with inverse

	GEN(OP_XCH) //exchange
	GEN(OP_LEA) //load effective address (GENERAL_SUBCODES)

	GEN(OP_CMP) //compare
	GEN(OP_CMPC) //compare
	GEN(OP_TEST) //test bits
	GEN(OP_TESTC) //test bits with constant
	GEN(OP_AND) //and
	GEN(OP_ANDC) //and with constant
	GEN(OP_OR) //or
	GEN(OP_ORC) //or with constant
	GEN(OP_XOR) //eXclusive or
	GEN(OP_XORC) //eXclusive or with constant

	GEN(OP_JMP) //jump (GENERAL_SUBCODES)
	GEN(OP_JZ) //jump if A zero (GENERAL_SUBCODES)
	GEN(OP_JL) //jump if A less B (GENERAL_SUBCODES)
	GEN(OP_JG) //jump if A greater B (GENERAL_SUBCODES)
	GEN(OP_JE) //jump if zero flag is set (GENERAL_SUBCODES)
	GEN(OP_JNE) //jump is zero flag is not set (GENERAL_SUBCODES)
	GEN(OP_JLE) //jump if A less or equals B (GENERAL_SUBCODES)
	GEN(OP_JGE) //jump if A greater or equals B (GENERAL_SUBCODES)
	GEN(OP_CALL) //call procedure (GENERAL_SUBCODES)
	GEN(OP_RET) //return to call address
	GEN(OP_INT) //interrupt
	GEN(OP_BRK) //breakpoint

	GEN(OP_HLT) //halt

	UNGEN(OP_SC) //save context
	UNGEN(OP_RC) //restore context

	/* system opcodes */

	OP_LAST
};

/* MOV instruction subcodes */
enum MOV_OP_SUBCODE
{
	//to    from
	MOVOP_RA_RB = 0, //move value from rB to rA
	MOVOP_RA_RC,
	MOVOP_RA_RD,

	MOVOP_RB_RA,
	MOVOP_RB_RC,
	MOVOP_RB_RD,

	MOVOP_RC_RA,
	MOVOP_RC_RB,
	MOVOP_RC_RD,

	MOVOP_RD_RA,
	MOVOP_RD_RB,
	MOVOP_RD_RC,

	MOVOP_RA_C,
	MOVOP_RB_C,
	MOVOP_RC_C,
	MOVOP_RD_C,

	MOVOP_M_RA,
	MOVOP_M_RB,
	MOVOP_M_RC,
	MOVOP_M_RD
};

enum GENERAL_SUBCODES
{
	SUBCODE_ADDR = 0,
	SUBCODE_RA,
	SUBCODE_RB,
	SUBCODE_RC,
	SUBCODE_RD
};

typedef unsigned int reg_t;

typedef struct vcpu_regs_ctx_s {
	struct {
		reg_t A;
		reg_t B;
		reg_t C;
		reg_t D;
	} gprregs; // general purpose registers

	struct {
		reg_t CS;
		reg_t DS;
		reg_t SS;
	} sregs;

	char FLAGS;
	reg_t IP, SP;
} vcpu_regs_ctx_t;
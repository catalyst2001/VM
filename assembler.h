/*
===============================================
 Virtual CPU Compiler
 
 This file part of vritual CPU compiler.
 This file is responsible for generating the bytecode.

 Author: Deryabin K.
 Date: 07.01.2023
===============================================
*/
#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "vcpudef.h"

/* byte array to store information such as CODE, DATA during assembly */
typedef struct bytearray_s {
	int size;
	int reserve;
	int capacity;
	char *p_bytes;
} bytearray_t;

bool bytearray_init(bytearray_t *p_bytearray, size_t reserved_cap, size_t reserve_realloc);
int bytearray_push8(bytearray_t *p_bytearray, int byte);
int bytearray_push16(bytearray_t *p_bytearray, int word);
int bytearray_push32(bytearray_t *p_bytearray, int dword);
int bytearray_push_bytes(bytearray_t *p_bytearray, const char *p_byte_string);
void bytearray_free(bytearray_t *p_bytearray);

/*
===============================================
 General assembler routines
===============================================
*/
#define ASM_REG_A 0	// register A index
#define ASM_REG_B 1	// register B index
#define ASM_REG_C 2	// register C index
#define ASM_REG_D 3	// register D index

#define nop(pbytearray) bytearray_push8(pbytearray, OP_NOP)
int asm_emit(bytearray_t *p_bytearray, const char *p_opstring);
int asm_fill(bytearray_t *p_bytearray, const char *p_opstring, int count);
int asm_mov_rm(bytearray_t *p_bytearray, int address, int src_asm_reg); // from register to memory
int asm_mov_rr(bytearray_t *p_bytearray, int dst_asm_reg, int src_asm_reg); // from register to register
int asm_mov_cr(bytearray_t *p_bytearray, int dst_asm_reg, int value); // from constant to register
int asm_sub_c(bytearray_t *p_bytearray, int asm_reg, int constant); //subtract constant from register
int asm_sub_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg); //subtract value 'src_register' from asm_reg
int asm_add_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg); // A = asm_reg + val_asm_reg
int asm_add_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_mul_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg);
int asm_mul_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_div_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg);
int asm_div_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_push_r(bytearray_t *p_bytearray, int val_asm_reg);
int asm_push_c(bytearray_t *p_bytearray, int constant);
int asm_pop_r(bytearray_t *p_bytearray, int asm_reg);
int asm_pop_m(bytearray_t *p_bytearray, int address); 
int asm_pop(bytearray_t *p_bytearray); 
int asm_inc_r(bytearray_t *p_bytearray, int asm_reg);
int asm_inc_m(bytearray_t *p_bytearray, int address);
int asm_dec_r(bytearray_t *p_bytearray, int asm_reg);
int asm_dec_m(bytearray_t *p_bytearray, int address);
int asm_shl(bytearray_t *p_bytearray, int asm_reg);
int asm_shr(bytearray_t *p_bytearray, int asm_reg);
//int asm_sal(bytearray_t *p_bytearray, int asm_reg);
//int asm_sar(bytearray_t *p_bytearray, int asm_reg);
//int asm_bt_r(bytearray_t *p_bytearray, int asm_reg);
//int asm_bt_c(bytearray_t *p_bytearray, int constant);
//int asm_btc_r(bytearray_t *p_bytearray, int asm_reg);
//int asm_btc_c(bytearray_t *p_bytearray, int constant);
int asm_xch_r(bytearray_t *p_bytearray, int a_asm_reg, int b_asm_reg);
int asm_xch(bytearray_t *p_bytearray, int asm_reg);
int asm_lea_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_lea_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_cmp_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_cmp_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_test_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_test_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_test_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_test_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_and_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_and_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_or_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_or_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_xor_c(bytearray_t *p_bytearray, int asm_reg, int constant);
int asm_xor_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg);
int asm_jmp(bytearray_t *p_bytearray, int address);
int asm_jmp_r(bytearray_t *p_bytearray, int asm_reg);
int asm_jz(bytearray_t *p_bytearray, int address);
int asm_jz_r(bytearray_t *p_bytearray, int asm_reg);
int asm_jl(bytearray_t *p_bytearray, int address);
int asm_jl_r(bytearray_t *p_bytearray, int asm_reg);
int asm_jg(bytearray_t *p_bytearray, int address);
int asm_jg_r(bytearray_t *p_bytearray, int asm_reg);
int asm_je(bytearray_t *p_bytearray, int address);
int asm_je_r(bytearray_t *p_bytearray, int asm_reg);
int asm_jne(bytearray_t *p_bytearray, int address);
int asm_jne_r(bytearray_t *p_bytearray, int asm_reg);
int asm_jle(bytearray_t *p_bytearray, int address);
int asm_jle_r(bytearray_t *p_bytearray, int asm_reg);
int asm_jge(bytearray_t *p_bytearray, int address);
int asm_jge_r(bytearray_t *p_bytearray, int asm_reg);
int asm_call(bytearray_t *p_bytearray, int address);
int asm_call_r(bytearray_t *p_bytearray, int asm_reg);
int asm_ret(bytearray_t *p_bytearray);
int asm_int(bytearray_t *p_bytearray, int address);
int asm_brk(bytearray_t *p_bytearray);
int asm_hlt(bytearray_t *p_bytearray);
int asm_sc(bytearray_t *p_bytearray);
int asm_rc(bytearray_t *p_bytearray);

/* structure containing data about code generation */
typedef struct vcpu_assembler_s {
	bytearray_t code;
	bytearray_t data;
} vcpu_assembler_t;

bool vcpu_assembler_init(vcpu_assembler_t *p_dstassembler, size_t reserved_code, size_t reserved_data);

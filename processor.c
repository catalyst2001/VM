/*
===============================================
 Virtual CPU
 
 Author: Deryabin K.
===============================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "assembler.h"

vcpu_regs_ctx_t gctx; // general context

typedef struct vcpu_processor_ctx_s {
	size_t code_size;
	size_t data_size;
	size_t stack_size;
	vcpu_regs_ctx_t registers;
} vcpu_processor_ctx_t;

typedef struct vcpub_section_s {
	char shortdesc[6];
	int offset;
} vcpub_section_t;

typedef struct vcpub_symbol_s {
	int name_offset;
	int address;
} vcpub_symbol_t;

#define VCPU_SIGNATURE 0x55504356

typedef struct vcpub_header_s {
	int signature; //'VCPU'
	int flags;
	int segments_offset;
	int code_size;
	int stack_size;
	int strtbl_offset;
} vcpub_header_t;

enum CVPULDR_STATUS
{
	VCPULDR_SUCCESS = 0,
	VCPULDR_INVALID_SIGNATURE,
	VCPULDR_OUT_OF_MEMORY
};

//int vcpuldr_load_binary(vcpu_processor_ctx_t *p_dstctx, char *p_bytes, size_t size, bool debug)
//{
//	vcpub_header_t *p_header = (vcpub_header_t *)p_bytes;
//	if (p_header->signature != VCPU_SIGNATURE)
//		return VCPUB_INVALID_SIGNATURE;
//
//	memset(p_dstctx, 0, sizeof(*p_dstctx));
//	p_dstctx->code_size = p_header->code_size;
//	p_dstctx->stack_size = p_header->stack_size;
//	if (p_dstctx->code_size) {
//		p_dstctx->registers.sregs.CS = (reg_t)malloc(p_dstctx->code_size);
//		if (!p_dstctx->registers.sregs.CS)
//			return VCPULDR_OUT_OF_MEMORY;
//	}
//
//	if (p_dstctx->stack_size) {
//		p_dstctx->registers.sregs.SS = (reg_t)malloc(p_dstctx->stack_size);
//		if (!p_dstctx->registers.sregs.SS)
//			return VCPULDR_OUT_OF_MEMORY;
//	}
//
//	if (p_dstctx->data_size) {
//		p_dstctx->registers.sregs.DS = (reg_t)malloc(p_dstctx->data_size);
//		if (!p_dstctx->registers.sregs.DS)
//			return VCPULDR_OUT_OF_MEMORY;
//	}
//	return VCPUB_SUCCESS;
//}

#include <time.h>
#pragma optimize(off, "g")

int summ(int a, int b)
{
	return time(NULL) - (a + b);
}

int main()
{
	printf("GOVNO: %d\n", summ(10, 10));
	return 0;
}

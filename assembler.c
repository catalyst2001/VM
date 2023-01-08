#include "assembler.h"

bool bytearray_init(bytearray_t *p_bytearray, size_t reserved_cap, size_t reserve_realloc)
{
	p_bytearray->capacity = reserved_cap;
	p_bytearray->reserve = reserve_realloc;
	p_bytearray->size = 0;
	p_bytearray->p_bytes = NULL;
	if (p_bytearray->capacity)
		if (!(p_bytearray->p_bytes = (char *)malloc(p_bytearray->capacity)))
			return false;

	return true;
}

bool bytearray_internal_realloc(bytearray_t *p_bytearray)
{
	if (p_bytearray->size >= p_bytearray->capacity) {
		p_bytearray->capacity += p_bytearray->reserve;
		p_bytearray->p_bytes = (char *)realloc(p_bytearray->p_bytes, p_bytearray->capacity);
		if (!p_bytearray->p_bytes)
			return false;
	}
	return true;
}

int bytearray_push8(bytearray_t *p_bytearray, int byte)
{
	int previous_offset = p_bytearray->size;
	if (!bytearray_internal_realloc(p_bytearray))
		return -1;

	p_bytearray->p_bytes[p_bytearray->size] = byte;
	p_bytearray->size++;
	return previous_offset;
}

int bytearray_push16(bytearray_t *p_bytearray, int word)
{
	int previous_offset = p_bytearray->size;
	if (!bytearray_internal_realloc(p_bytearray))
		return -1;

	memcpy(&p_bytearray->p_bytes[p_bytearray->size], &word, 2);
	p_bytearray->size += 2;
	return previous_offset;
}

int bytearray_push32(bytearray_t *p_bytearray, int dword)
{
	int previous_offset = p_bytearray->size;
	if (!bytearray_internal_realloc(p_bytearray))
		return -1;

	memcpy(&p_bytearray->p_bytes[p_bytearray->size], &dword, 4);
	p_bytearray->size += 4;
	return previous_offset;
}

int bytearray_push_bytes(bytearray_t *p_bytearray, const char *p_byte_string)
{
	size_t len = strlen(p_byte_string);
	if(!len)
		return p_bytearray->size;

	int previous_offset = p_bytearray->size;
	memcpy(&p_bytearray->p_bytes[p_bytearray->size], p_byte_string, len);
	p_bytearray->size += len;
	return previous_offset;
}

void bytearray_free(bytearray_t *p_bytearray)
{
	if (p_bytearray->p_bytes) {
		free(p_bytearray->p_bytes);
		p_bytearray->p_bytes = NULL;
	}
}

bool vcpu_assembler_init(vcpu_assembler_t *p_dstassembler, size_t reserve_realloc, size_t reserved_code, size_t reserved_data)
{
	memset(p_dstassembler, 0, sizeof(*p_dstassembler));
	if (!reserve_realloc)
		reserve_realloc = 1;

	return (bytearray_init(&p_dstassembler->code, reserved_code, reserve_realloc) && bytearray_init(&p_dstassembler->data, reserved_data, reserve_realloc));
}

int asm_emit(bytearray_t *p_bytearray, const char *p_opstring)
{
	return bytearray_push_bytes(p_bytearray, p_opstring);
}

int asm_fill(bytearray_t *p_bytearray, const char *p_opstring, int count)
{
	int previous_offset = p_bytearray->size;
	for (int i = 0; i < count; i++)
		bytearray_push_bytes(p_bytearray, p_opstring);

	return previous_offset;
}

int asm_mov_rm(bytearray_t *p_bytearray, int address, int src_asm_reg)
{
	int previous_offset = bytearray_push8(p_bytearray, OP_MOV);
	switch (src_asm_reg) {
		case ASM_REG_A:
			bytearray_push8(p_bytearray, MOVOP_M_RA);
			break;

		case ASM_REG_B:
			bytearray_push8(p_bytearray, MOVOP_M_RB);
			break;

		case ASM_REG_C:
			bytearray_push8(p_bytearray, MOVOP_M_RC);
			break;

		case ASM_REG_D:
			bytearray_push8(p_bytearray, MOVOP_M_RD);
			break;

		default:
			return -1;
	}
	bytearray_push32(p_bytearray, address);
	return previous_offset;
}

int asm_mov_rr(bytearray_t *p_bytearray, int dst_asm_reg, int src_asm_reg)
{
	if (dst_asm_reg == src_asm_reg)
		return -1;

	// TODO: optimize
	int previous_offset = bytearray_push8(p_bytearray, OP_MOV);
	if(dst_asm_reg == ASM_REG_A && src_asm_reg == ASM_REG_B)
		bytearray_push8(p_bytearray, MOVOP_RB_RA);
	else if (dst_asm_reg == ASM_REG_A && src_asm_reg == ASM_REG_C)
		bytearray_push8(p_bytearray, MOVOP_RC_RA);
	else if (dst_asm_reg == ASM_REG_A && src_asm_reg == ASM_REG_D)
		bytearray_push8(p_bytearray, MOVOP_RD_RA);

	else if (dst_asm_reg == ASM_REG_B && src_asm_reg == ASM_REG_A)
		bytearray_push8(p_bytearray, MOVOP_RA_RB);
	else if (dst_asm_reg == ASM_REG_B && src_asm_reg == ASM_REG_C)
		bytearray_push8(p_bytearray, MOVOP_RC_RB);
	else if (dst_asm_reg == ASM_REG_B && src_asm_reg == ASM_REG_D)
		bytearray_push8(p_bytearray, MOVOP_RD_RB);

	else if (dst_asm_reg == ASM_REG_C && src_asm_reg == ASM_REG_A)
		bytearray_push8(p_bytearray, MOVOP_RA_RC);
	else if (dst_asm_reg == ASM_REG_C && src_asm_reg == ASM_REG_B)
		bytearray_push8(p_bytearray, MOVOP_RB_RC);
	else if (dst_asm_reg == ASM_REG_C && src_asm_reg == ASM_REG_D)
		bytearray_push8(p_bytearray, MOVOP_RD_RC);

	else if (dst_asm_reg == ASM_REG_D && src_asm_reg == ASM_REG_A)
		bytearray_push8(p_bytearray, MOVOP_RA_RD);
	else if (dst_asm_reg == ASM_REG_D && src_asm_reg == ASM_REG_B)
		bytearray_push8(p_bytearray, MOVOP_RB_RD);
	else if (dst_asm_reg == ASM_REG_D && src_asm_reg == ASM_REG_C)
		bytearray_push8(p_bytearray, MOVOP_RC_RD);

	return previous_offset;
}

int asm_mov_cr(bytearray_t *p_bytearray, int dst_asm_reg, int value)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_sub_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_sub_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_add_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_add_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_mul_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_mul_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_div_r(bytearray_t *p_bytearray, int asm_reg, int val_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_div_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_push_r(bytearray_t *p_bytearray, int val_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_push_c(bytearray_t *p_bytearray, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_pop_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_pop_m(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_pop(bytearray_t *p_bytearray)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_inc_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_inc_m(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_dec_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_dec_m(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_shl(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_shr(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_xch_r(bytearray_t *p_bytearray, int a_asm_reg, int b_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_xch(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_lea_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_lea_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_cmp_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_cmp_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_test_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_test_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_and_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_and_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_or_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_or_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_xor_c(bytearray_t *p_bytearray, int asm_reg, int constant)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_xor_r(bytearray_t *p_bytearray, int asm_reg, int src_asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jmp(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jmp_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jz(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jz_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jl(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jl_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jg(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jg_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_je(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_je_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jne(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jne_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jle(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jle_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jge(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_jge_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_call(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_call_r(bytearray_t *p_bytearray, int asm_reg)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_ret(bytearray_t *p_bytearray)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_int(bytearray_t *p_bytearray, int address)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_brk(bytearray_t *p_bytearray)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_hlt(bytearray_t *p_bytearray)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_sc(bytearray_t *p_bytearray)
{
	int previous_offset = 0;


	return previous_offset;
}

int asm_rc(bytearray_t *p_bytearray)
{
	int previous_offset = 0;


	return previous_offset;
}

#include "vm_ih.h"
#include <assert.h>

int vm_ih_nop(vcpu_context_t *p_vmctx)
{
	return 1;
}

int vm_ih_mov_a_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t); //size of instruction parameter
}

int vm_ih_mov_b_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t); //size of instruction parameter
}

int vm_ih_mov_c_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t); //size of instruction parameter
}

int vm_ih_mov_d_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t); //size of instruction parameter
}

int vm_mov_a_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.B;
	return 0; //instruction has no parameters
}

int vm_mov_a_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.C;
	return 0;
}

int vm_mov_a_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.D;
	return 0;
}

int vm_mov_b_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.A;
	return 0;
}

int vm_mov_b_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.C;
	return 0;
}

int vm_mov_b_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.D;
	return 0;
}

int vm_mov_c_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.A;
	return 0;
}

int vm_mov_c_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.B;
	return 0;
}

int vm_mov_c_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.D;
	return 0;
}

int vm_mov_d_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.A;
	return 0;
}

int vm_mov_d_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.B;
	return 0;
}

int vm_mov_d_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.C;
	return 0;
}

//int vm_mov_m_a(int opcode, vcpu_context_t *p_vmctx)
//{
//	return 0;
//}
//
//int vm_mov_m_b(int opcode, vcpu_context_t *p_vmctx)
//{
//	return 0;
//}
//
//int vm_mov_m_c(int opcode, vcpu_context_t *p_vmctx)
//{
//	return 0;
//}
//
//int vm_mov_m_d(int opcode, vcpu_context_t *p_vmctx)
//{
//	return 0;
//}

int vm_xch_a_b(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.B;
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.A;
	p_vmctx->cpuregs.A = temp;
	return 0;
}

int vm_xch_a_c(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.C;
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.A;
	p_vmctx->cpuregs.A = temp;
	return 0;
}

int vm_xch_a_d(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.D;
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.A;
	p_vmctx->cpuregs.A = temp;
	return 0;
}

int vm_xch_b_a(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.A;
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.B;
	p_vmctx->cpuregs.B = temp;
	return 0;
}

int vm_xch_b_c(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.C;
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.B;
	p_vmctx->cpuregs.B = temp;
	return 0;
}

int vm_xch_b_d(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.D;
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.B;
	p_vmctx->cpuregs.B = temp;
	return 0;
}

int vm_xch_c_a(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.A;
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.C;
	p_vmctx->cpuregs.C = temp;
	return 0;
}

int vm_xch_c_b(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.B;
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.C;
	p_vmctx->cpuregs.C = temp;
	return 0;
}

int vm_xch_c_d(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.D;
	p_vmctx->cpuregs.D = p_vmctx->cpuregs.C;
	p_vmctx->cpuregs.C = temp;
	return 0;
}

int vm_xch_d_a(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.A;
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.D;
	p_vmctx->cpuregs.D = temp;
	return 0;
}

int vm_xch_d_b(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.B;
	p_vmctx->cpuregs.B = p_vmctx->cpuregs.D;
	p_vmctx->cpuregs.D = temp;
	return 0;
}

int vm_xch_d_c(int opcode, vcpu_context_t *p_vmctx)
{
	register_t temp = p_vmctx->cpuregs.C;
	p_vmctx->cpuregs.C = p_vmctx->cpuregs.D;
	p_vmctx->cpuregs.D = temp;
	return 0;
}


int vm_add_a_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A += p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_add_b_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B += p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_add_c_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C += p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_add_d_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D += p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_add_a_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A += p_vmctx->cpuregs.A;
	return 0;
}

int vm_add_a_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A += p_vmctx->cpuregs.B;
	return 0;
}

int vm_add_a_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A += p_vmctx->cpuregs.C;
	return 0;
}

int vm_add_a_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A += p_vmctx->cpuregs.D;
	return 0;
}

int vm_add_b_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.B + p_vmctx->cpuregs.A;
	return 0;
}

int vm_add_b_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.B + p_vmctx->cpuregs.B;
	return 0;
}

int vm_add_b_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.B + p_vmctx->cpuregs.C;
	return 0;
}

int vm_add_b_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.B + p_vmctx->cpuregs.D;
	return 0;
}

int vm_add_c_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.C + p_vmctx->cpuregs.A;
	return 0;
}

int vm_add_c_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.C + p_vmctx->cpuregs.B;
	return 0;
}

int vm_add_c_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.C + p_vmctx->cpuregs.C;
	return 0;
}

int vm_add_c_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.C + p_vmctx->cpuregs.D;
	return 0;
}

int vm_add_d_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.D + p_vmctx->cpuregs.A;
	return 0;
}

int vm_add_d_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.D + p_vmctx->cpuregs.B;
	return 0;
}

int vm_add_d_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.D + p_vmctx->cpuregs.C;
	return 0;
}

int vm_add_d_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A = p_vmctx->cpuregs.D + p_vmctx->cpuregs.D;
	return 0;
}


int vm_ih_sub_a_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A -= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_sub_b_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B -= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_sub_c_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C -= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_sub_d_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D -= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

//TODO: delete
int vm_ih_sub_a_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A -= p_vmctx->cpuregs.A;
	return 0;
}

int vm_ih_sub_a_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A -= p_vmctx->cpuregs.B;
	return 0;
}

int vm_ih_sub_a_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A -= p_vmctx->cpuregs.C;
	return 0;
}

int vm_ih_sub_a_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A -= p_vmctx->cpuregs.D;
	return 0;
}

int vm_ih_sub_b_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B -= p_vmctx->cpuregs.A;
	return 0;
}

//TODO: delete
int vm_ih_sub_b_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B -= p_vmctx->cpuregs.B;
	return 0;
}

int vm_ih_sub_b_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B -= p_vmctx->cpuregs.C;
	return 0;
}

int vm_ih_sub_b_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B -= p_vmctx->cpuregs.D;
	return 0;
}

int vm_ih_sub_c_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C -= p_vmctx->cpuregs.A;
	return 0;
}

int vm_ih_sub_c_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C -= p_vmctx->cpuregs.B;
	return 0;
}

//TODO: delete
int vm_ih_sub_c_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C -= p_vmctx->cpuregs.C;
	return 0;
}

int vm_ih_sub_c_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C -= p_vmctx->cpuregs.D;
	return 0;
}

int vm_ih_sub_d_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D -= p_vmctx->cpuregs.A;
	return 0;
}

int vm_ih_sub_d_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D -= p_vmctx->cpuregs.B;
	return 0;
}

int vm_ih_sub_d_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D -= p_vmctx->cpuregs.C;
	return 0;
}

//TODO: delete
int vm_ih_sub_d_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D -= p_vmctx->cpuregs.D;
	return 0;
}

inline void vm_flags_set_flag(vcpu_context_t *p_vmctx, int flag, bool exp)
{
	if (!exp)
		p_vmctx->cpuregs.FLAGS &= ~flag;
	else p_vmctx->cpuregs.FLAGS |= flag;
}

void vm_cmp_update_flags(vcpu_context_t *p_vmctx, int operand1, int operand2)
{
	int result = operand1 - operand2;
	p_vmctx->cpuregs.FLAGS &= ~(VCPU_ZF | VCPU_SF);
	vm_flags_set_flag(p_vmctx, VCPU_ZF, !result);
	vm_flags_set_flag(p_vmctx, VCPU_SF, result < 0);
}

int vm_ih_cmp_a_const(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.A, p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP]);
	return sizeof(register_t);
}

int vm_ih_cmp_b_const(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.B, p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP]);
	return sizeof(register_t);
}

int vm_ih_cmp_c_const(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.C, p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP]);
	return sizeof(register_t);
}

int vm_ih_cmp_d_const(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.D, p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP]);
	return sizeof(register_t);
}

int vm_ih_cmp_a_b(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.A, p_vmctx->cpuregs.B);
	return 0;
}

int vm_ih_cmp_a_c(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.A, p_vmctx->cpuregs.C);
	return 0;
}

int vm_ih_cmp_a_d(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.A, p_vmctx->cpuregs.D);
	return 0;
}

int vm_ih_cmp_b_a(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.B, p_vmctx->cpuregs.A);
	return 0;
}

int vm_ih_cmp_b_c(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.B, p_vmctx->cpuregs.C);
	return 0;
}

int vm_ih_cmp_b_d(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.B, p_vmctx->cpuregs.D);
	return 0;
}

int vm_ih_cmp_c_a(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.C, p_vmctx->cpuregs.A);
	return 0;
}

int vm_ih_cmp_c_b(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.C, p_vmctx->cpuregs.B);
	return 0;
}

int vm_ih_cmp_c_d(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.C, p_vmctx->cpuregs.D);
	return 0;
}

int vm_ih_cmp_d_a(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.D, p_vmctx->cpuregs.A);
	return 0;
}

int vm_ih_cmp_d_b(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.D, p_vmctx->cpuregs.B);
	return 0;
}

int vm_ih_cmp_d_c(int opcode, vcpu_context_t *p_vmctx)
{
	vm_cmp_update_flags(p_vmctx, p_vmctx->cpuregs.D, p_vmctx->cpuregs.C);
	return 0;
}


int vm_ih_and_a_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A &= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_and_b_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B &= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_and_c_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C &= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_and_d_const(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D &= p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return sizeof(register_t);
}

int vm_ih_and_a_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A &= p_vmctx->cpuregs.B;
	return 0;
}

int vm_ih_and_a_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A &= p_vmctx->cpuregs.C;
	return 0;
}

int vm_ih_and_a_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.A &= p_vmctx->cpuregs.D;
	return 0;
}

int vm_ih_and_b_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B &= p_vmctx->cpuregs.A;
	return 0;
}

int vm_ih_and_b_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B &= p_vmctx->cpuregs.C;
	return 0;
}

int vm_ih_and_b_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.B &= p_vmctx->cpuregs.D;
	return 0;
}

int vm_ih_and_c_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C &= p_vmctx->cpuregs.A;
	return 0;
}

int vm_ih_and_c_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C &= p_vmctx->cpuregs.B;
	return 0;
}

int vm_ih_and_c_d(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.C &= p_vmctx->cpuregs.D;
	return 0;
}

int vm_ih_and_d_a(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D &= p_vmctx->cpuregs.A;
	return 0;
}

int vm_ih_and_d_b(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D &= p_vmctx->cpuregs.B;
	return 0;
}

int vm_ih_and_d_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.D &= p_vmctx->cpuregs.C;
	return 0;
}

int vm_ih_push(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_PUSH_CONST;
	if (!regs_offset) {
		p_vmctx->cpuregs.SS[p_vmctx->cpuregs.SP] = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
		p_vmctx->cpuregs.SP++;
		return sizeof(register_t);
	}
	assert(VM_VALID_REG_OFFSET(regs_offset - 1));
	p_vmctx->cpuregs.SS[p_vmctx->cpuregs.SP] = p_vmctx->cpuregs.regs[regs_offset - 1];
	p_vmctx->cpuregs.SP++;
	return 0;
}

int vm_ih_pop(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_POP;
	if (!regs_offset) {
		p_vmctx->cpuregs.SP--;
		return 0;
	}
	assert(VM_VALID_REG_OFFSET(regs_offset - 1));
	p_vmctx->cpuregs.regs[regs_offset - 1] = p_vmctx->cpuregs.SS[p_vmctx->cpuregs.SP];
	p_vmctx->cpuregs.SP--;
	return 0;
}

int vm_ih_jmp(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JMP_CONST;
	if (!regs_offset) {
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
		return 0;
	}
	assert(VM_VALID_REG_OFFSET(regs_offset - 1));
	p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	return 0;
}

int vm_ih_jnz(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JNZ_CONST;
	if (!regs_offset) {
		if (p_vmctx->cpuregs.A) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if (p_vmctx->cpuregs.A) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_jz(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JZ_CONST;
	if (!regs_offset) {
		if (p_vmctx->cpuregs.A) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if (p_vmctx->cpuregs.A) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_je(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JE_CONST;
	if (!regs_offset) {
		if (p_vmctx->cpuregs.FLAGS & VCPU_ZF) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if (p_vmctx->cpuregs.FLAGS & VCPU_ZF) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_jne(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JNE_CONST;
	if (!regs_offset) {
		if (!(p_vmctx->cpuregs.FLAGS & VCPU_ZF)) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if (!(p_vmctx->cpuregs.FLAGS & VCPU_ZF)) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_jl(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JL_CONST;
	if (!regs_offset) {
		if ((p_vmctx->cpuregs.FLAGS & VCPU_SF)) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if ((p_vmctx->cpuregs.FLAGS & VCPU_SF)) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_jle(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JLE_CONST;
	if (!regs_offset) {
		if ((p_vmctx->cpuregs.FLAGS & VCPU_SF) || (p_vmctx->cpuregs.FLAGS & VCPU_ZF)) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if ((p_vmctx->cpuregs.FLAGS & VCPU_SF) || (p_vmctx->cpuregs.FLAGS & VCPU_ZF)) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_jg(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JG_CONST;
	if (!regs_offset) {
		if (!(p_vmctx->cpuregs.FLAGS & VCPU_SF)) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if (!(p_vmctx->cpuregs.FLAGS & VCPU_SF)) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_jge(int opcode, vcpu_context_t *p_vmctx)
{
	int regs_offset = opcode - OP_JGE_CONST;
	if (!regs_offset) {
		if (!(p_vmctx->cpuregs.FLAGS & VCPU_SF) || (p_vmctx->cpuregs.FLAGS & VCPU_ZF)) {
			p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
			return 0;
		}
		return sizeof(register_t);
	}

	if (!(p_vmctx->cpuregs.FLAGS & VCPU_SF) || (p_vmctx->cpuregs.FLAGS & VCPU_ZF)) {
		assert(VM_VALID_REG_OFFSET(regs_offset - 1));
		p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[regs_offset - 1];
	}
	return 0;
}

int vm_ih_call_c(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.PIP = p_vmctx->cpuregs.IP + 1;
	p_vmctx->cpuregs.IP = p_vmctx->cpuregs.CS[p_vmctx->cpuregs.IP];
	return 0;
}

int vm_ih_call_r(int opcode, vcpu_context_t *p_vmctx)
{
	int reg_offset = opcode - OP_CALL_A;
	assert(VM_VALID_REG_OFFSET(reg_offset));
	p_vmctx->cpuregs.IP = p_vmctx->cpuregs.regs[reg_offset];
	return 0;
}

int vm_ih_ret(int opcode, vcpu_context_t *p_vmctx)
{
	p_vmctx->cpuregs.IP = p_vmctx->cpuregs.PIP;
	return 0;
}

int vm_ih_inc(int opcode, vcpu_context_t *p_vmctx)
{
	int reg_offset = opcode - OP_INC_A;
	assert(VM_VALID_REG_OFFSET(reg_offset));
	p_vmctx->cpuregs.regs[reg_offset]++;
	return 0;
}

int vm_ih_dec(int opcode, vcpu_context_t *p_vmctx)
{
	int reg_offset = opcode - OP_DEC_A;
	assert(VM_VALID_REG_OFFSET(reg_offset));
	p_vmctx->cpuregs.regs[reg_offset]--;
	return 0;
}

//int vm_ih_ecall(int opcode, vcpu_context_t *p_vmctx)
//{
//	return 0;
//}

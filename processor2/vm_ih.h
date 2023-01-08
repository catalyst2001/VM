#pragma once
#include "vm_defs.h"
#include "vm.h"

int vm_ih_nop(vcpu_context_t *p_vmctx);

int vm_ih_mov_a_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_mov_b_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_mov_c_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_mov_d_const(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_a_b(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_a_c(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_a_d(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_b_a(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_b_c(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_b_d(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_c_a(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_c_b(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_c_d(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_d_a(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_d_b(int opcode, vcpu_context_t *p_vmctx);
int vm_mov_d_c(int opcode, vcpu_context_t *p_vmctx);
//int vm_mov_m_a(int opcode, vcpu_context_t *p_vmctx);
//int vm_mov_m_b(int opcode, vcpu_context_t *p_vmctx);
//int vm_mov_m_c(int opcode, vcpu_context_t *p_vmctx);
//int vm_mov_m_d(int opcode, vcpu_context_t *p_vmctx);

int vm_xch_a_b(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_a_c(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_a_d(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_b_a(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_b_c(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_b_d(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_c_a(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_c_b(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_c_d(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_d_a(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_d_b(int opcode, vcpu_context_t *p_vmctx);
int vm_xch_d_c(int opcode, vcpu_context_t *p_vmctx);

int vm_add_a_const(int opcode, vcpu_context_t *p_vmctx);
int vm_add_b_const(int opcode, vcpu_context_t *p_vmctx);
int vm_add_c_const(int opcode, vcpu_context_t *p_vmctx);
int vm_add_d_const(int opcode, vcpu_context_t *p_vmctx);
int vm_add_a_a(int opcode, vcpu_context_t *p_vmctx);
int vm_add_a_b(int opcode, vcpu_context_t *p_vmctx);
int vm_add_a_c(int opcode, vcpu_context_t *p_vmctx);
int vm_add_a_d(int opcode, vcpu_context_t *p_vmctx);
int vm_add_b_a(int opcode, vcpu_context_t *p_vmctx);
int vm_add_b_b(int opcode, vcpu_context_t *p_vmctx);
int vm_add_b_c(int opcode, vcpu_context_t *p_vmctx);
int vm_add_b_d(int opcode, vcpu_context_t *p_vmctx);
int vm_add_c_a(int opcode, vcpu_context_t *p_vmctx);
int vm_add_c_b(int opcode, vcpu_context_t *p_vmctx);
int vm_add_c_c(int opcode, vcpu_context_t *p_vmctx);
int vm_add_c_d(int opcode, vcpu_context_t *p_vmctx);
int vm_add_d_a(int opcode, vcpu_context_t *p_vmctx);
int vm_add_d_b(int opcode, vcpu_context_t *p_vmctx);
int vm_add_d_c(int opcode, vcpu_context_t *p_vmctx);
int vm_add_d_d(int opcode, vcpu_context_t *p_vmctx);

int vm_ih_sub_a_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_b_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_c_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_d_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_a_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_a_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_a_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_a_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_b_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_b_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_b_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_b_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_c_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_c_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_c_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_c_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_d_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_d_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_d_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_sub_d_d(int opcode, vcpu_context_t *p_vmctx);

int vm_ih_cmp_a_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_b_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_c_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_d_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_a_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_a_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_a_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_b_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_b_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_b_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_c_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_c_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_c_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_d_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_d_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_cmp_d_c(int opcode, vcpu_context_t *p_vmctx);

int vm_ih_and_a_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_b_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_c_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_d_const(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_a_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_a_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_a_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_b_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_b_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_b_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_c_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_c_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_c_d(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_d_a(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_d_b(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_and_d_c(int opcode, vcpu_context_t *p_vmctx);

int vm_ih_push(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_pop(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jmp(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jnz(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jz(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_je(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jne(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jl(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jle(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jg(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_jge(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_call_c(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_call_r(int opcode, vcpu_context_t *p_vmctx);

int vm_ih_inc(int opcode, vcpu_context_t *p_vmctx);
int vm_ih_dec(int opcode, vcpu_context_t *p_vmctx);

//int vm_ih_ecall_c(int opcode, vcpu_context_t *p_vmctx);
//int vm_ih_ecall_r(int opcode, vcpu_context_t *p_vmctx);

int vm_ih_ret(int opcode, vcpu_context_t *p_vmctx);
#include "vm.h"
#include "vm_ih.h"

instruction_handler_pfn op_handlers[MAX_OPCODES] = {
	vm_ih_nop, //OP_NOP

	vm_ih_mov_a_const,	//OP_MOV_A_CONST,
	vm_ih_mov_b_const,	//OP_MOV_B_CONST,
	vm_ih_mov_c_const,	//OP_MOV_C_CONST,
	vm_ih_mov_d_const,	//OP_MOV_D_CONST,
	vm_mov_a_b,			//OP_MOV_A_B,
	vm_mov_a_c,			//OP_MOV_A_C,
	vm_mov_a_d,			//OP_MOV_A_D,
	vm_mov_b_a,			//OP_MOV_B_A,
	vm_mov_b_c,			//OP_MOV_B_C,
	vm_mov_b_d,			//OP_MOV_B_D,
	vm_mov_c_a,			//OP_MOV_C_A,
	vm_mov_c_b,			//OP_MOV_C_B,
	vm_mov_c_d,			//OP_MOV_C_D,
	vm_mov_d_a,			//OP_MOV_D_A,
	vm_mov_d_b,			//OP_MOV_D_B,
	vm_mov_d_c,			//OP_MOV_D_C,
	//vm_mov_m_a,		//OP_MOV_M_A,
	//vm_mov_m_b,		//OP_MOV_M_B,
	//vm_mov_m_c,		//OP_MOV_M_C,
	//vm_mov_m_d,		//OP_MOV_M_D,

	vm_xch_a_b,	 //OP_XCH_A_B,
	vm_xch_a_c,	 //OP_XCH_A_C,
	vm_xch_a_d,	 //OP_XCH_A_D,
	vm_xch_b_a,	 //OP_XCH_B_A,
	vm_xch_b_c,	 //OP_XCH_B_C,
	vm_xch_b_d,	 //OP_XCH_B_D,
	vm_xch_c_a,	 //OP_XCH_C_A,
	vm_xch_c_b,	 //OP_XCH_C_B,
	vm_xch_c_d,	 //OP_XCH_C_D,
	vm_xch_d_a,	 //OP_XCH_D_A,
	vm_xch_d_b,	 //OP_XCH_D_B,
	vm_xch_d_c,	 //OP_XCH_D_C,

	vm_add_a_const,	   //OP_ADD_A_CONST,
	vm_add_b_const,	   //OP_ADD_B_CONST,
	vm_add_c_const,	   //OP_ADD_C_CONST,
	vm_add_d_const,	   //OP_ADD_D_CONST,
	vm_add_a_a,		   //OP_ADD_A_A,
	vm_add_a_b,		   //OP_ADD_A_B,
	vm_add_a_c,		   //OP_ADD_A_C,
	vm_add_a_d,		   //OP_ADD_A_D,
	vm_add_b_a,		   //OP_ADD_B_A,
	vm_add_b_b,		   //OP_ADD_B_B,
	vm_add_b_c,		   //OP_ADD_B_C,
	vm_add_b_d,		   //OP_ADD_B_D,
	vm_add_c_a,		   //OP_ADD_C_A,
	vm_add_c_b,		   //OP_ADD_C_B,
	vm_add_c_c,		   //OP_ADD_C_C,
	vm_add_c_d,		   //OP_ADD_C_D,
	vm_add_d_a,		   //OP_ADD_D_A,
	vm_add_d_b,		   //OP_ADD_D_B,
	vm_add_d_c,		   //OP_ADD_D_C,
	vm_add_d_d,		   //OP_ADD_D_D,

	vm_ih_sub_a_const,	//OP_SUB_A_CONST,
	vm_ih_sub_b_const,	//OP_SUB_B_CONST,
	vm_ih_sub_c_const,	//OP_SUB_C_CONST,
	vm_ih_sub_d_const,	//OP_SUB_D_CONST,
	vm_ih_sub_a_a,		//OP_SUB_A_A,
	vm_ih_sub_a_b,		//OP_SUB_A_B,
	vm_ih_sub_a_c,		//OP_SUB_A_C,
	vm_ih_sub_a_d,		//OP_SUB_A_D,
	vm_ih_sub_b_a,		//OP_SUB_B_A,
	vm_ih_sub_b_b,		//OP_SUB_B_B,
	vm_ih_sub_b_c,		//OP_SUB_B_C,
	vm_ih_sub_b_d,		//OP_SUB_B_D,
	vm_ih_sub_c_a,		//OP_SUB_C_A,
	vm_ih_sub_c_b,		//OP_SUB_C_B,
	vm_ih_sub_c_c,		//OP_SUB_C_C,
	vm_ih_sub_c_d,		//OP_SUB_C_D,
	vm_ih_sub_d_a,		//OP_SUB_D_A,
	vm_ih_sub_d_b,		//OP_SUB_D_B,
	vm_ih_sub_d_c,		//OP_SUB_D_C,
	vm_ih_sub_d_d,		//OP_SUB_D_D,

	vm_ih_cmp_a_const,	//OP_CMP_A_CONST,
	vm_ih_cmp_b_const,	//OP_CMP_B_CONST,
	vm_ih_cmp_c_const,	//OP_CMP_C_CONST,
	vm_ih_cmp_d_const,	//OP_CMP_D_CONST,
	vm_ih_cmp_a_b,		//OP_CMP_A_B,
	vm_ih_cmp_a_c,		//OP_CMP_A_C,
	vm_ih_cmp_a_d,		//OP_CMP_A_D,
	vm_ih_cmp_b_a,		//OP_CMP_B_A,
	vm_ih_cmp_b_c,		//OP_CMP_B_C,
	vm_ih_cmp_b_d,		//OP_CMP_B_D,
	vm_ih_cmp_c_a,		//OP_CMP_C_A,
	vm_ih_cmp_c_b,		//OP_CMP_C_B,
	vm_ih_cmp_c_d,		//OP_CMP_C_D,
	vm_ih_cmp_d_a,		//OP_CMP_D_A,
	vm_ih_cmp_d_b,		//OP_CMP_D_B,
	vm_ih_cmp_d_c,		//OP_CMP_D_C,

	vm_ih_and_a_const, //OP_AND_A_CONST,
	vm_ih_and_b_const, //OP_AND_B_CONST,
	vm_ih_and_c_const, //OP_AND_C_CONST,
	vm_ih_and_d_const, //OP_AND_D_CONST,
	vm_ih_and_a_b,	   //OP_AND_A_B,
	vm_ih_and_a_c,	   //OP_AND_A_C,
	vm_ih_and_a_d,	   //OP_AND_A_D,
	vm_ih_and_b_a,	   //OP_AND_B_A,
	vm_ih_and_b_c,	   //OP_AND_B_C,
	vm_ih_and_b_d,	   //OP_AND_B_D,
	vm_ih_and_c_a,	   //OP_AND_C_A,
	vm_ih_and_c_b,	   //OP_AND_C_B,
	vm_ih_and_c_d,	   //OP_AND_C_D,
	vm_ih_and_d_a,	   //OP_AND_D_A,
	vm_ih_and_d_b,	   //OP_AND_D_B,
	vm_ih_and_d_c,	   //OP_AND_D_C,

	vm_ih_push, //OP_PUSH_CONST,
	vm_ih_push, //OP_PUSH_A,
	vm_ih_push,	//OP_PUSH_B,
	vm_ih_push,	//OP_PUSH_C,
	vm_ih_push,	//OP_PUSH_D,

	vm_ih_pop,	//OP_POP,
	vm_ih_pop,	//OP_POP_A,
	vm_ih_pop,	//OP_POP_B,
	vm_ih_pop,	//OP_POP_C,
	vm_ih_pop,	//OP_POP_D,

	vm_ih_jmp,	//OP_JMP_CONST,
	vm_ih_jmp,	//OP_JMP_A,
	vm_ih_jmp,	//OP_JMP_B,
	vm_ih_jmp,	//OP_JMP_C,
	vm_ih_jmp,	//OP_JMP_D,

	vm_ih_jnz,  //OP_JNZ_CONST,
	vm_ih_jnz,  //OP_JNZ_B,
	vm_ih_jnz,  //OP_JNZ_C,
	vm_ih_jnz,  //OP_JNZ_D,

	vm_ih_jz,   //OP_JZ_CONST,
	vm_ih_jz,   //OP_JZ_B,
	vm_ih_jz,   //OP_JZ_C,
	vm_ih_jz,   //OP_JZ_D,

	vm_ih_je,   //OP_JE_CONST,
	vm_ih_je,   //OP_JE_A,
	vm_ih_je,   //OP_JE_B,
	vm_ih_je,   //OP_JE_C,
	vm_ih_je,   //OP_JE_D,

	vm_ih_jne,	//OP_JNE_CONST,
	vm_ih_jne,	//OP_JNE_A,
	vm_ih_jne,	//OP_JNE_B,
	vm_ih_jne,	//OP_JNE_C,
	vm_ih_jne,	//OP_JNE_D,

	vm_ih_jl, //OP_JL_CONST,
	vm_ih_jl, //OP_JL_A,
	vm_ih_jl, //OP_JL_B,
	vm_ih_jl, //OP_JL_C,
	vm_ih_jl, //OP_JL_D,

	vm_ih_jle, //OP_JLE_CONST,
	vm_ih_jle, //OP_JLE_A,
	vm_ih_jle, //OP_JLE_B,
	vm_ih_jle, //OP_JLE_C,
	vm_ih_jle, //OP_JLE_D,

	vm_ih_jg, //OP_JG_CONST,
	vm_ih_jg, //OP_JG_A,
	vm_ih_jg, //OP_JG_B,
	vm_ih_jg, //OP_JG_C,
	vm_ih_jg, //OP_JG_D,

	vm_ih_jge, //OP_JGE_CONST,
	vm_ih_jge, //OP_JGE_A,
	vm_ih_jge, //OP_JGE_B,
	vm_ih_jge, //OP_JGE_C,
	vm_ih_jge, //OP_JGE_D,

	vm_ih_call_c, //OP_CALL_CONST
	vm_ih_call_r, //OP_CALL_A,
	vm_ih_call_r, //OP_CALL_B,
	vm_ih_call_r, //OP_CALL_C,
	vm_ih_call_r, //OP_CALL_D,

	vm_ih_inc, //OP_INC_A,
	vm_ih_inc, //OP_INC_B,
	vm_ih_inc, //OP_INC_C,
	vm_ih_inc, //OP_INC_D,

	vm_ih_dec, //OP_DEC_A,
	vm_ih_dec, //OP_DEC_B,
	vm_ih_dec, //OP_DEC_C,
	vm_ih_dec, //OP_DEC_D,

	//vm_ih_ecall_c,	//OP_ECALL_CONST,
	//vm_ih_ecall_r,	//OP_ECALL_A,
	//vm_ih_ecall_r,	//OP_ECALL_B,
	//vm_ih_ecall_r,	//OP_ECALL_C,
	//vm_ih_ecall_r,	//OP_ECALL_D,

	vm_ih_ret //OP_RET
};

void vm_set_externals(vcpu_context_t *p_context, vm_external_func_def_t *p_externals, int n_externs)
{
	p_context->number_of_externals = n_externs;
	p_context->p_extrns = p_externals;
}

void vm_set_callbacks(vcpu_context_t *p_context, const vm_callbacks_dt_t *p_callbacks)
{
	p_context->p_callbacks = p_callbacks;
}

bool vm_set_executable(vcpu_context_t *p_context, char *p_executable, size_t size)
{
	return false;
}

int vm_prepare_context(vcpu_context_t *p_context, char *p_pcode, int size_of_pcode, char *p_data, int size_of_data, int size_of_stack, int vm_flags)
{
	/* prepare segment registers */
	p_context->code_size = size_of_pcode;
	p_context->cpuregs.CS = (char *)p_pcode;
	p_context->data_size = size_of_data;
	p_context->cpuregs.DS = (char *)p_data;
	p_context->vm_flags = vm_flags;
	return 0;
}

bool handle_breakpoint(int *p_dst_execstatus, vcpu_context_t *p_context)
{
	if (p_context->p_callbacks && p_context->p_callbacks->vm_breakpoint_raised) {
		switch (p_context->p_callbacks->vm_breakpoint_raised(p_context)) {
		case VM_EXEC_TERMINATE:
			*p_dst_execstatus = VM_MANUALLY_TERMINATED; //set vm execution status
			p_context->vm_flags &= ~VM_FEXEC; //change execution flags
			return false;

		case VM_EXEC_ENABLE_STEPEXEC:
			p_context->vm_flags |= VM_FSTEPEXEC;
			return true;

		case VM_EXEC_DISABLE_STEPEXEC:
			p_context->vm_flags &= ~VM_FSTEPEXEC;
			return true;

		case VM_EXEC_NEXT:
		default:
			p_context->cpuregs.IP++; //skip breakpoint opcode
			return true;
		}
	}
	return true; // will never executed
}

int vm_start_execution(vcpu_context_t *p_context)
{
	int execution_status = VM_ERROR_NONE;
	while (p_context->vm_flags & VM_FEXEC) {
		if (p_context->cpuregs.IP >= p_context->code_size) {
			printf("Address 0x%x out of code segment! vCPU program has terminated!\n", p_context->cpuregs.IP);
			return VM_ERROR_ACCESS_VIOLATION;
		}

		register_t opcode = p_context->cpuregs.CS[p_context->cpuregs.IP];

		// check step execution flags
		if (p_context->vm_flags & VM_FSTEPEXEC) {
			if (p_context->p_callbacks && p_context->p_callbacks->vm_debug_instruction_step) {
				int status = p_context->p_callbacks->vm_debug_instruction_step(p_context);
				if (status == VM_EXEC_TERMINATE) {
					p_context->vm_flags &= ~VM_FEXEC;
					execution_status = VM_MANUALLY_TERMINATED;
					continue;
				}
				else if (status == VM_EXEC_DISABLE_STEPEXEC) {
					p_context->vm_flags &= ~VM_FSTEPEXEC;
				}
			}
		}

		// handle HALT instruction
		if (opcode == OP_HALT) {
			printf("HALT instruction at address 0x%x  vCPU program has terminated!\n", p_context->cpuregs.IP);
			p_context->vm_flags &= ~VM_FEXEC;
			continue;
		}

		// handle breakpoint
		if (opcode == OP_BRK && !handle_breakpoint(&execution_status, p_context))
			continue; // reiterate cycle with disabled VM_FEXEC flag (end execution cycle)

		if (opcode >= MAX_OPCODES) {
			printf("Unknown instruction at address 0x%x! vCPU program has terminated!\n", p_context->cpuregs.IP);
			return VM_ERROR_UNKNOWN_INSTRUCTION;
		}

		// call opcode handler
		p_context->cpuregs.IP++;
		p_context->cpuregs.IP += op_handlers[opcode](opcode, p_context);
	}
	return execution_status;
}

const char *vm_opcode_name(int opcode)
{
#define CASE_OPNAME(openum) case openum: return #openum;
	switch (opcode) {
		CASE_OPNAME(OP_NOP)
		CASE_OPNAME(OP_MOV_A_CONST)
		CASE_OPNAME(OP_MOV_B_CONST)
		CASE_OPNAME(OP_MOV_C_CONST)
		CASE_OPNAME(OP_MOV_D_CONST)
		CASE_OPNAME(OP_MOV_A_B)
		CASE_OPNAME(OP_MOV_A_C)
		CASE_OPNAME(OP_MOV_A_D)
		CASE_OPNAME(OP_MOV_B_A)
		CASE_OPNAME(OP_MOV_B_C)
		CASE_OPNAME(OP_MOV_B_D)
		CASE_OPNAME(OP_MOV_C_A)
		CASE_OPNAME(OP_MOV_C_B)
		CASE_OPNAME(OP_MOV_C_D)
		CASE_OPNAME(OP_MOV_D_A)
		CASE_OPNAME(OP_MOV_D_B)
		CASE_OPNAME(OP_MOV_D_C)
		//CASE_OPNAME(OP_MOV_M_A)
		//CASE_OPNAME(OP_MOV_M_B)
		//CASE_OPNAME(OP_MOV_M_C)
		//CASE_OPNAME(OP_MOV_M_D)
		CASE_OPNAME(OP_XCH_A_B)
		CASE_OPNAME(OP_XCH_A_C)
		CASE_OPNAME(OP_XCH_A_D)
		CASE_OPNAME(OP_XCH_B_A)
		CASE_OPNAME(OP_XCH_B_C)
		CASE_OPNAME(OP_XCH_B_D)
		CASE_OPNAME(OP_XCH_C_A)
		CASE_OPNAME(OP_XCH_C_B)
		CASE_OPNAME(OP_XCH_C_D)
		CASE_OPNAME(OP_XCH_D_A)
		CASE_OPNAME(OP_XCH_D_B)
		CASE_OPNAME(OP_XCH_D_C)
		CASE_OPNAME(OP_ADD_A_CONST)
		CASE_OPNAME(OP_ADD_B_CONST)
		CASE_OPNAME(OP_ADD_C_CONST)
		CASE_OPNAME(OP_ADD_D_CONST)
		CASE_OPNAME(OP_ADD_A_A)
		CASE_OPNAME(OP_ADD_A_B)
		CASE_OPNAME(OP_ADD_A_C)
		CASE_OPNAME(OP_ADD_A_D)
		CASE_OPNAME(OP_ADD_B_A)
		CASE_OPNAME(OP_ADD_B_B)
		CASE_OPNAME(OP_ADD_B_C)
		CASE_OPNAME(OP_ADD_B_D)
		CASE_OPNAME(OP_ADD_C_A)
		CASE_OPNAME(OP_ADD_C_B)
		CASE_OPNAME(OP_ADD_C_C)
		CASE_OPNAME(OP_ADD_C_D)
		CASE_OPNAME(OP_ADD_D_A)
		CASE_OPNAME(OP_ADD_D_B)
		CASE_OPNAME(OP_ADD_D_C)
		CASE_OPNAME(OP_ADD_D_D)
		CASE_OPNAME(OP_SUB_A_CONST)
		CASE_OPNAME(OP_SUB_B_CONST)
		CASE_OPNAME(OP_SUB_C_CONST)
		CASE_OPNAME(OP_SUB_D_CONST)
		CASE_OPNAME(OP_SUB_A_A)
		CASE_OPNAME(OP_SUB_A_B)
		CASE_OPNAME(OP_SUB_A_C)
		CASE_OPNAME(OP_SUB_A_D)
		CASE_OPNAME(OP_SUB_B_A)
		CASE_OPNAME(OP_SUB_B_B)
		CASE_OPNAME(OP_SUB_B_C)
		CASE_OPNAME(OP_SUB_B_D)
		CASE_OPNAME(OP_SUB_C_A)
		CASE_OPNAME(OP_SUB_C_B)
		CASE_OPNAME(OP_SUB_C_C)
		CASE_OPNAME(OP_SUB_C_D)
		CASE_OPNAME(OP_SUB_D_A)
		CASE_OPNAME(OP_SUB_D_B)
		CASE_OPNAME(OP_SUB_D_C)
		CASE_OPNAME(OP_SUB_D_D)
		CASE_OPNAME(OP_CMP_A_CONST)
		CASE_OPNAME(OP_CMP_B_CONST)
		CASE_OPNAME(OP_CMP_C_CONST)
		CASE_OPNAME(OP_CMP_D_CONST)
		CASE_OPNAME(OP_CMP_A_B)
		CASE_OPNAME(OP_CMP_A_C)
		CASE_OPNAME(OP_CMP_A_D)
		CASE_OPNAME(OP_CMP_B_A)
		CASE_OPNAME(OP_CMP_B_C)
		CASE_OPNAME(OP_CMP_B_D)
		CASE_OPNAME(OP_CMP_C_A)
		CASE_OPNAME(OP_CMP_C_B)
		CASE_OPNAME(OP_CMP_C_D)
		CASE_OPNAME(OP_CMP_D_A)
		CASE_OPNAME(OP_CMP_D_B)
		CASE_OPNAME(OP_CMP_D_C)
		CASE_OPNAME(OP_AND_A_CONST)
		CASE_OPNAME(OP_AND_B_CONST)
		CASE_OPNAME(OP_AND_C_CONST)
		CASE_OPNAME(OP_AND_D_CONST)
		CASE_OPNAME(OP_AND_A_B)
		CASE_OPNAME(OP_AND_A_C)
		CASE_OPNAME(OP_AND_A_D)
		CASE_OPNAME(OP_AND_B_A)
		CASE_OPNAME(OP_AND_B_C)
		CASE_OPNAME(OP_AND_B_D)
		CASE_OPNAME(OP_AND_C_A)
		CASE_OPNAME(OP_AND_C_B)
		CASE_OPNAME(OP_AND_C_D)
		CASE_OPNAME(OP_AND_D_A)
		CASE_OPNAME(OP_AND_D_B)
		CASE_OPNAME(OP_AND_D_C)
		CASE_OPNAME(OP_PUSH_CONST)
		CASE_OPNAME(OP_PUSH_A)
		CASE_OPNAME(OP_PUSH_B)
		CASE_OPNAME(OP_PUSH_C)
		CASE_OPNAME(OP_PUSH_D)
		CASE_OPNAME(OP_POP)
		CASE_OPNAME(OP_POP_A)
		CASE_OPNAME(OP_POP_B)
		CASE_OPNAME(OP_POP_C)
		CASE_OPNAME(OP_POP_D)
		CASE_OPNAME(OP_JMP_CONST)
		CASE_OPNAME(OP_JMP_A)
		CASE_OPNAME(OP_JMP_B)
		CASE_OPNAME(OP_JMP_C)
		CASE_OPNAME(OP_JMP_D)
		CASE_OPNAME(OP_JNZ_CONST)
		CASE_OPNAME(OP_JNZ_B)
		CASE_OPNAME(OP_JNZ_C)
		CASE_OPNAME(OP_JNZ_D)
		CASE_OPNAME(OP_JZ_CONST)
		CASE_OPNAME(OP_JZ_B)
		CASE_OPNAME(OP_JZ_C)
		CASE_OPNAME(OP_JZ_D)
		CASE_OPNAME(OP_JE_CONST)
		CASE_OPNAME(OP_JE_A)
		CASE_OPNAME(OP_JE_B)
		CASE_OPNAME(OP_JE_C)
		CASE_OPNAME(OP_JE_D)
		CASE_OPNAME(OP_JNE_CONST)
		CASE_OPNAME(OP_JNE_A)
		CASE_OPNAME(OP_JNE_B)
		CASE_OPNAME(OP_JNE_C)
		CASE_OPNAME(OP_JNE_D)
		CASE_OPNAME(OP_JL_CONST)
		CASE_OPNAME(OP_JL_A)
		CASE_OPNAME(OP_JL_B)
		CASE_OPNAME(OP_JL_C)
		CASE_OPNAME(OP_JL_D)
		CASE_OPNAME(OP_JLE_CONST)
		CASE_OPNAME(OP_JLE_A)
		CASE_OPNAME(OP_JLE_B)
		CASE_OPNAME(OP_JLE_C)
		CASE_OPNAME(OP_JLE_D)
		CASE_OPNAME(OP_JG_CONST)
		CASE_OPNAME(OP_JG_A)
		CASE_OPNAME(OP_JG_B)
		CASE_OPNAME(OP_JG_C)
		CASE_OPNAME(OP_JG_D)
		CASE_OPNAME(OP_JGE_CONST)
		CASE_OPNAME(OP_JGE_A)
		CASE_OPNAME(OP_JGE_B)
		CASE_OPNAME(OP_JGE_C)
		CASE_OPNAME(OP_JGE_D)
		CASE_OPNAME(OP_CALL_CONST)
		CASE_OPNAME(OP_CALL_A)
		CASE_OPNAME(OP_CALL_B)
		CASE_OPNAME(OP_CALL_C)
		CASE_OPNAME(OP_CALL_D)
		CASE_OPNAME(OP_INC_A)
		CASE_OPNAME(OP_INC_B)
		CASE_OPNAME(OP_INC_C)
		CASE_OPNAME(OP_INC_D)
		CASE_OPNAME(OP_DEC_A)
		CASE_OPNAME(OP_DEC_B)
		CASE_OPNAME(OP_DEC_C)
		CASE_OPNAME(OP_DEC_D)
		//CASE_OPNAME(OP_ECALL_CONST)
		//CASE_OPNAME(OP_ECALL_A)
		//CASE_OPNAME(OP_ECALL_B)
		//CASE_OPNAME(OP_ECALL_C)
		//CASE_OPNAME(OP_ECALL_D)
		CASE_OPNAME(OP_RET)
		CASE_OPNAME(OP_BRK)
		CASE_OPNAME(OP_HALT)
	}
	return "UNKNOWN_INSTRUCTION";
}

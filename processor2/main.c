#include <stdio.h>
#include <windows.h>
#include "vm.h"

vcpu_context_t context;
char stack[200];

// instruction step handling
VM_DEBUG_INTRUCTION_EXEC debug_instruction_step_cb(vcpu_context_t *p_context)
{
	Sleep(50);
	return VM_EXEC_NEXT;
}

// breakpoint handling
VM_DEBUG_INTRUCTION_EXEC breakpoint_raised(vcpu_context_t *p_context)
{
	printf("breakpoint on %d address. terminating..\n", p_context->cpuregs.IP);
	return VM_EXEC_TERMINATE;
}

void instruction_cb(vcpu_context_t *p_context)
{
	//Sleep(50);
	printf("op %s on addr %d  (rA: %d | rB: %d | rC: %d | rD: %d | IP: %d | SP: %d | PIP: %d )\n", vm_opcode_name(p_context->cpuregs.CS[p_context->cpuregs.IP]),
		p_context->cpuregs.IP,
		p_context->cpuregs.A,
		p_context->cpuregs.B,
		p_context->cpuregs.C,
		p_context->cpuregs.D,
		p_context->cpuregs.IP,
		p_context->cpuregs.SP,
		p_context->cpuregs.PIP
	);
}

vm_callbacks_dt_t vm_cbs = {
	.vm_debug_instruction_step = debug_instruction_step_cb,
	.vm_breakpoint_raised = breakpoint_raised,
	.vm_instruction = instruction_cb
};

int main()
{
    static char code[] = {
		                    //       start:
		OP_MOV_A_CONST, 10, //0+2        mov a, 10
		OP_MOV_B_CONST, 10, //2+2        mov b, 10
		OP_ADD_A_B,         //4          add a, b
		OP_XCH_A_B,         //5          xch a, b

		OP_PUSH_A,			//6          push a
		OP_PUSH_B,			//7          push b
		OP_CALL_CONST,	12,	//8+2        call proc1
		OP_POP_A,           //10         pop a
		OP_HALT,            //11         hlt

		                    //       proc1:
		OP_POP_B,           //12         pop b
		OP_POP_A,           //13         pop a

		                    //       label1:
		OP_DEC_A,           //14         dec a
		OP_INC_B,           //15         inc b
		OP_JNZ_CONST, 14,   //16+2       jnz label1
		OP_PUSH_B,          //18         push b
		OP_RET,             //19         ret

		OP_BRK              //20         brk
	};

	memset(&context, 0, sizeof(context));
	context.vm_flags |= VM_FEXEC|VM_FSTEPEXEC;
	context.code_size = sizeof(code);
	context.cpuregs.CS = (char *)code;
	context.stack_size = sizeof(stack);
	context.cpuregs.SS = (char *)stack;
	context.p_callbacks = &vm_cbs;

	int status = vm_start_execution(&context);
	if (status != VM_ERROR_NONE) {
		printf("VM_EXECUTION: execution finished with errors!. Error code: %d\n", status);
		return 1;
	}
	printf("VM_EXECUTION: Execution completed succesfully!\n");
	return 0;
}
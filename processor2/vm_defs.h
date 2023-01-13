#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "vm_opcodes.h"

typedef unsigned char register_t;
typedef unsigned char flags_t;

/* VCPU flags */
#define VCPU_ZF (1 << 0)
#define VCPU_SF (1 << 1)
#define VCPU_OF (1 << 2)
#define VCPU_CF (1 << 3)

typedef struct vcpu_context_s vcpu_context_t;

typedef int (*external_pfn)(vcpu_context_t *p_context);

/* externals definitions */
typedef struct vm_external_func_def_s {
	const char *p_name;
	external_pfn p_func;
} vm_external_func_def_t;

/* virutal machine callbacks */
typedef enum VM_DEBUG_INTRUCTION_EXEC_ {
	VM_EXEC_NEXT = 0,
	VM_EXEC_ENABLE_STEPEXEC,
	VM_EXEC_DISABLE_STEPEXEC,
	VM_EXEC_TERMINATE
} VM_DEBUG_INTRUCTION_EXEC;

typedef struct vm_callbacks_dt_s {
	VM_DEBUG_INTRUCTION_EXEC (*vm_debug_instruction_step)(vcpu_context_t *p_context);
	VM_DEBUG_INTRUCTION_EXEC (*vm_breakpoint_raised)(vcpu_context_t *p_context);
	void                     (*vm_instruction)(vcpu_context_t *p_context);
} vm_callbacks_dt_t;

/* virtual processor context */
typedef struct vcpu_context_s {
	int number_of_externals;
	vm_external_func_def_t *p_extrns;
	vm_callbacks_dt_t *p_callbacks;
	int vm_flags;
	int code_size;
	int stack_size;
	int data_size;
	struct {
		union {
			struct { register_t A, B, C, D; };
			register_t regs[4];
		};
		unsigned char *CS, *DS, *SS;
		int IP, SP;
		flags_t FLAGS;
		register_t PIP;
	} cpuregs;
} vcpu_context_t;

#define VM_VALID_REG_OFFSET(offs) (offs >= 0 && offs < sizeof(register_t[4]))
#define VM_SAFE_DT_CALL(x, f, ...) if (x && (x)->f) (x)->f(__VA_ARGS__)

typedef int(*instruction_handler_pfn)(int opcode, vcpu_context_t *p_vmctx);
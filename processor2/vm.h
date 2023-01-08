/*
====================================
 Simple Interpreted Virtual Machine

 Simple interpreted virtual machine that emulates an 8-bit processor.
 Performance improvement achieved through the use of states machine.

 Author: Deryabin K.
 Date: 08.01.03 1:33
====================================
*/
#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "vm_defs.h"
#include "vm_executable.h"

#define VM_ERROR_NONE 0
#define VM_ERROR_ACCESS_VIOLATION 1
#define VM_ERROR_UNKNOWN_INSTRUCTION 2
#define VM_MANUALLY_TERMINATED 3

/* virutal machine context flags */
#define VM_FEXEC (1 << 0)
#define VM_FSTEPEXEC (1 << 1) //for debugging

void vm_set_externals(vcpu_context_t *p_context, vm_external_func_def_t *p_externals, int n_externs);
void vm_set_callbacks(vcpu_context_t *p_context, const vm_callbacks_dt_t *p_callbacks);
bool vm_set_executable(vcpu_context_t *p_context, char *p_executable, size_t size);
int  vm_prepare_context(vcpu_context_t *p_context, char *p_pcode, int size_of_pcode, char *p_data, int size_of_data, int size_of_stack, int vm_flags);

int vm_start_execution(vcpu_context_t *p_context);

const char *vm_opcode_name(int opcode);
#pragma once
#include "vm.h"

#define VM_LDR_NOTHINGMACRO(x) //for intellisense sizeof

#define VCPU_SIGNATURE 0x55504356

#pragma pack(push, 1)

/* executable file header */
typedef struct vm_executable_hdr_s {
	int signature; //file signature VCPU_SIGNATURE
	short codeseg; //offset to code segment
	short dataseg; //offset to intialized data segment
	short rdataseg; //offset to unintialized data segment
	short impsymtbl; //offset to import symbols table
	short expsymtbl; //offset to export symbols table
	short entrypoint; //offset to entry point
} vm_executable_hdr_t;
VM_LDR_NOTHINGMACRO(sizeof(vm_executable_hdr_t));

/* symbol */
typedef struct vm_executable_symbol_s {
	int nameoffset; //name offset to dataseg
	int index; //index
} vm_executable_symbol_t;
VM_LDR_NOTHINGMACRO(sizeof(vm_executable_symbol_t));

/* symbols table */
typedef struct vm_executable_syms_tbl_s {
	int tblsize; //table 
	vm_executable_symbol_t symbols[];
} vm_executable_syms_tbl_t;
VM_LDR_NOTHINGMACRO(sizeof(vm_executable_syms_tbl_t));
#pragma pack(pop)

#define VMEXEC_CODESEG(baseaddr) (((char *)baseaddr) + ((vm_executable_hdr_t *)baseaddr)->codeseg)
#define VMEXEC_DATASEG(baseaddr) (((char *)baseaddr) + ((vm_executable_hdr_t *)baseaddr)->dataseg)
#define VMEXEC_RAWDATASEG(baseaddr) (((char *)baseaddr) + ((vm_executable_hdr_t *)baseaddr)->rdataseg)
#define VMEXEC_IMPSYMTBL(baseaddr) ((vm_executable_symbol_t *)(((char *)baseaddr) + ((vm_executable_hdr_t *)baseaddr)->impsymtbl))
#define VMEXEC_EXPSYMTBL(baseaddr) ((vm_executable_symbol_t *)(((char *)baseaddr) + ((vm_executable_hdr_t *)baseaddr)->expsymtbl))

/* prepared executable binary */
typedef void *VM_EXECUTABLE;

typedef enum VM_LDR_STATUS_ {
	VM_LDR_SUCCESS = 0,
	VM_LDR_FILE_NOT_EXISTS,
	VM_LDR_FILE_TOO_SMALL,
	VM_LDR_FILE_READING_ERROR,
	VM_LDR_INVALID_SIGNATURE,
	VM_LDR_INVALID_CODE_SIZE,
	VM_LDR_INVALID_DATA_SIZE,
	VM_LDR_INVALID_STACK_SIZE,
	VM_LDR_INVALID_IMPORT_TABLE_SIZE,
	VM_LDR_INVALID_EXPORT_TABLE_SIZE,
	VM_LDR_OUT_OF_MEMORY
} VM_LDR_STATUS;

VM_LDR_STATUS vm_ldr_load_binary_ex(VM_EXECUTABLE *p_dst_baseaddr, char *p_filename);
VM_LDR_STATUS vm_ldr_free_binary(VM_EXECUTABLE *p_baseaddr);
#include "vm_executable.h"

VM_LDR_STATUS vm_ldr_load_binary_ex(VM_EXECUTABLE *p_dst_baseaddr, char *p_filename)
{
	FILE *fp;
	fopen_s(&fp, p_filename, "rb");
	if (!fp)
		return VM_LDR_FILE_NOT_EXISTS;

	size_t file_size;
	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	if (file_size < sizeof(vm_executable_hdr_t) + 8)
		return VM_LDR_FILE_TOO_SMALL;

	char *p_data = (char *)malloc(file_size);
	if (!p_data)
		return VM_LDR_OUT_OF_MEMORY;

	if (fread(p_data, 1, file_size, fp) != file_size)
		return VM_LDR_FILE_READING_ERROR;

	*p_dst_baseaddr = p_data;

	fclose(fp);
	return VM_LDR_SUCCESS;
}

VM_LDR_STATUS vm_ldr_free_binary(VM_EXECUTABLE *p_baseaddr)
{
	if (*p_baseaddr) {
		free(*p_baseaddr);
		*p_baseaddr = NULL;
	}
	return VM_LDR_SUCCESS;
}

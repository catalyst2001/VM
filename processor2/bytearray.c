#include "bytearray.h"

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
	if (!len)
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
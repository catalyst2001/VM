#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* byte array to store information such as CODE, DATA during assembly */
typedef struct bytearray_s {
	int size;
	int reserve;
	int capacity;
	char *p_bytes;
} bytearray_t;

bool bytearray_init(bytearray_t *p_bytearray, size_t reserved_cap, size_t reserve_realloc);
int bytearray_push8(bytearray_t *p_bytearray, int byte);
int bytearray_push16(bytearray_t *p_bytearray, int word);
int bytearray_push32(bytearray_t *p_bytearray, int dword);
int bytearray_push_bytes(bytearray_t *p_bytearray, const char *p_byte_string);
void bytearray_free(bytearray_t *p_bytearray);

/*
===============================================
 General assembler routines
===============================================
*/
#define ASM_REG_A 0	// register A index
#define ASM_REG_B 1	// register B index
#define ASM_REG_C 2	// register C index
#define ASM_REG_D 3	// register D index
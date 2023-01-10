#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bytearray.h"

typedef struct pragma_s {
	int c;
} pragma_t;

typedef struct assembler_s {
	int code_limit;
	int stack_limit;
	int data_limit;
	int rdata_limit;
	bytearray_t codeseg;
	bytearray_t dataseg;
	bytearray_t rdataseg;
} assembler_t;


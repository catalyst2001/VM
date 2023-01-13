#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <bitset>
#include <climits>

typedef bool bit_t; //bit bool type

// binary number. 1 bit = 1 byte
struct bin8_number
{
	bit_t bits[8];
};

//interpret int to binary number
void bin_from_int8(bin8_number *p_dst, int num)
{
	for (int i = 0; i < 8; i++)
		p_dst->bits[i] = (bit_t)(num & (1 << i));
}

//interpret binary number to int
int int8_from_bin(bin8_number *p_src)
{
	//return (p_src->bits[0] << 0 |
	//	(p_src->bits[1] << 1) |
	//	(p_src->bits[2] << 2) |
	//	(p_src->bits[3] << 3) |
	//	(p_src->bits[4] << 4) |
	//	(p_src->bits[5] << 5) |
	//	(p_src->bits[6] << 6) |
	//	(p_src->bits[7] << 7));

	int num = 0;
	for (int i = 0; i < 8; i++)
		num |= (p_src->bits[i] << i);

	return num;
}

//binary number bits to string
void bitnum_to_string(char *p_dst, int dstlen, bin8_number *p_src)
{
	//int i;
	//for (i = 0; i < 8; i++) {
	//	if (i == dstlen) {
	//		p_dst[i - 1] = '\0';
	//		return;
	//	}
	//	p_dst[i] = p_src->bits[i] + 48;
	//}
	//p_dst[i] = '\0';

}

// print number bits to console
void bitnum_print_bin(bin8_number *p_src)
{
	char text[10];
	bitnum_to_string(text, sizeof(text), p_src);
	printf("%s\n", text);
}

char buffer[128];

// number bits to string ptr
const char *bitnum_print_bin2(bin8_number *p_src)
{
	bitnum_to_string(buffer, sizeof(buffer), p_src);
	return (const char *)buffer;
}

// number int print
void bitnum_print_dec(bin8_number *p_src)
{
	printf("%d\n", int8_from_bin(p_src));
}

/* logical blocks */
#define AND(a, b) (a & b)
#define OR(a, b) (a | b)
#define XOR(a, b) (a ^ b)
#define NOT(a) (!a)

/*
==================================
 bit_hs (1-bit half sum)

 Scheme

 X ----x-->[  &  ] 
       |   [ AND ]----> p
 Y -x--|-->[     ]
	|  |
	|  |
	|  +-->[  =1 ]
	|      [ XOR ]----> q
	+----->[     ]

  X | Y | P | Q
 ---+---+---+---
  0 | 0 | 0 | 0
  0 | 1 | 0 | 1
  1 | 0 | 0 | 1
  1 | 1 | 1 | 0

 Out: X + Y = Q
 Carry: p
==================================
*/
void bit_hs(bit_t x, bit_t y, bit_t *p_p, bit_t *p_q)
{
	*p_p = AND(x, y);
	*p_q = XOR(x, y);
}

/*
==================================
 bit_sm (1-bit summator)
 bitA, bitB

 Scheme

 X ------->[ X HS P ]-------------->[ 1   ]
	       [        ] HS1           [ OR  ]----> C
 Y ------->[ Y    Q ]----+   +----->[     ]
                         |   |
      +------------------+   |
	  |                      |
	  +--->[ X HS P ]--------+
		   [        ] HS2
 C-1  ---->[ Y    Q ]--------------------------> Q

==================================
*/
void bit_sm(bit_t x, bit_t y, bit_t cs1, bit_t *p_c, bit_t *p_q)
{
	bit_t hs1_outq, hs1_outp, hs2_outp;
	bit_hs(x, y, &hs1_outp, &hs1_outq); //HS1
	bit_hs(hs1_outq, cs1, &hs2_outp, p_q); //HS2
	*p_c = OR(hs1_outp, hs2_outp);
}

#define NULL_BIT 0
#define BIT_0 0
#define BIT_1 1
#define BIT_2 2
#define BIT_3 3
#define BIT_4 4
#define BIT_5 5
#define BIT_6 6
#define BIT_7 7

/*
==================================
 bit_sm8 (8-bit summator)
 p_src1, p_src2

 Scheme

 X7 ------>[ X SM C ]-
		   [        ] SM7    
 Y7 ------>[ Y      ]
		   [        ]     
      +--->[ C-1  Q ]--------> Q7
	  |				    
	  +------------------+   ...
						 |
 Xn ------>[ X SM C ]----+
		   [        ] SMn
 Yn ------>[ Y      ]
		   [        ]
	  +--->[ C-1  Q ]--------> Qn
	  |
	  +------------------+   ...
						 |
 X0 ------>[ X SM C ]----+
		   [        ] SM0
 Y0 ------>[ Y      ]
		   [        ]
(0 bit)--->[ C-1  Q ]--------> Q0

 Result: dst = src1 + src2
 Returns: FALSE - normal state, TRUE - overflow
==================================
*/
bool bit_sm8(bin8_number *p_dst, const bin8_number *p_src1, const bin8_number *p_src2)
{
	bit_t carry = NULL_BIT;
	bit_sm(p_src1->bits[BIT_0], p_src2->bits[BIT_0], carry, &carry, &p_dst->bits[BIT_0]);
	bit_sm(p_src1->bits[BIT_1], p_src2->bits[BIT_1], carry, &carry, &p_dst->bits[BIT_1]);
	bit_sm(p_src1->bits[BIT_2], p_src2->bits[BIT_2], carry, &carry, &p_dst->bits[BIT_2]);
	bit_sm(p_src1->bits[BIT_3], p_src2->bits[BIT_3], carry, &carry, &p_dst->bits[BIT_3]);
	bit_sm(p_src1->bits[BIT_4], p_src2->bits[BIT_4], carry, &carry, &p_dst->bits[BIT_4]);
	bit_sm(p_src1->bits[BIT_5], p_src2->bits[BIT_5], carry, &carry, &p_dst->bits[BIT_5]);
	bit_sm(p_src1->bits[BIT_6], p_src2->bits[BIT_6], carry, &carry, &p_dst->bits[BIT_6]);
	bit_sm(p_src1->bits[BIT_7], p_src2->bits[BIT_7], carry, &carry, &p_dst->bits[BIT_7]);
	return carry != NULL_BIT;
}

void bit_1s_complement(bin8_number *p_dst, const bin8_number *p_src)
{
	p_dst->bits[BIT_0] = p_src->bits[BIT_0];
	p_dst->bits[BIT_1] = NOT(p_src->bits[BIT_1]);
	p_dst->bits[BIT_2] = NOT(p_src->bits[BIT_2]);
	p_dst->bits[BIT_3] = NOT(p_src->bits[BIT_3]);
	p_dst->bits[BIT_4] = NOT(p_src->bits[BIT_4]);
	p_dst->bits[BIT_5] = NOT(p_src->bits[BIT_5]);
	p_dst->bits[BIT_6] = NOT(p_src->bits[BIT_6]);
	p_dst->bits[BIT_7] = NOT(p_src->bits[BIT_7]);
}

void bit_2s_complement(bin8_number *p_dst, const bin8_number *p_src)
{
	bit_t carry; //ignored
	bin8_number inverse;
	bin8_number one = { 0, 0, 0, 0, 0, 0, 0, 1 };
	bit_1s_complement(&inverse, p_src);
	bit_sm8(p_dst, &inverse, &one);
}

// subtract 8-bit number
// dst = src1 - src2;
bool bit_sub8(bin8_number *p_dst, const bin8_number *p_src1, const bin8_number *p_src2)
{
	bin8_number srcb;
	bit_2s_complement(&srcb, p_src2);
	return bit_sm8(p_dst, p_src1, &srcb);
}

//print first 100 numbers to console in decimal and binary interpretation
void print100numbers();

void test1()
{
	bin8_number A, B, result;
	bin_from_int8(&A, 1);
	bin_from_int8(&B, 2);

	bitnum_print_bin(&A);
	bitnum_print_bin(&B);
	printf("A: %d\nB: %d\n", int8_from_bin(&A), int8_from_bin(&B));

	printf("\n\n\n");
	bool b_overflow = bit_sm8(&result, &A, &B);
	printf("A + B = %d  (%s)\n", int8_from_bin(&result), b_overflow ? "overflow" : "normal");
	bitnum_print_bin(&result);

	printf("\n");
	b_overflow = bit_sub8(&result, &A, &B);
	printf("A - B = %d  (%s)\n", int8_from_bin(&result), b_overflow ? "overflow" : "normal");
	bitnum_print_bin(&result);
}

#define downfor(i, n) for(i = n - 1; i > 0; i--)
#define upfor(i, n) for(i = 0; i < n; i++)
#define cfor(i, n) downfor(i, n)

void int8tobin(int value)
{
	//int i, j = 0;
	//char str[64];
	//str[8] = '\0';
	//for (i = 8 - 1; i >= 0; i--) {
	//	str[i] = ((1 << i) & value) ? '1' : '0';
	//}
	printf("%s\n", std::bitset<8>(value).to_string().c_str());
}

void int8tobin2_string(char *p_dst, int dstlen, int value, int nbits)
{
	int j = 0;
	for (int i = nbits - 1; i >= 0 && j < dstlen - 1; i--)
		p_dst[j++] = (value & (1 << i)) ? '1' : '0';

	p_dst[j] = '\0';
}

void int8tobitnum(bin8_number *p_dst, int value)
{
	int j = 0;
	for (int i = 7; i >= 0; i--)
		p_dst->bits[j++] = (value & (1 << i));
}

int bitnumtoint8(bin8_number *p_dst)
{
	int number = 0;
	for (int i = 0, j = 7; i < 8; i++, j--)
		if (p_dst->bits[i])
			number |= (1 << j);

	return number;
}

#define nbits(x) (CHAR_BIT * sizeof(x))

int main()
{
	bin8_number a, res;
	int8tobitnum(&a, 2);
	printf("R(a) = %d\n", bitnumtoint8(&a));
	printf("a = %d (%s)\n", int8_from_bin(&a), bitnum_print_bin2(&a));

#pragma region COMPLEMENT_TEST
	///* test 1s complement */
	//bit_1s_complement(&res, &a);
	//printf("1sCpl(res) = %d (%s)\n", int8_from_bin(&res), bitnum_print_bin2(&res));

	///* test 2s complement */
	//bit_2s_complement(&res, &a);
	//printf("2sCpl(res) = %d (%s)\n", int8_from_bin(&res), bitnum_print_bin2(&res));
#pragma endregion
#pragma region COMPLEMENT_TEST

#pragma endregion	

	char data[32];
	int8tobin(127);
	int8tobin2_string(data, sizeof(data), 127, nbits(char));
	printf("%s\n", data);

	int8tobin(-128);
	int8tobin2_string(data, sizeof(data), -128, nbits(char));
	printf("%s\n", data);

	return 0;
}

void print100numbers()
{
	char text[10];
	bin8_number number;
	printf("--- 100 numbers ---\n");
	for (int i = 0; i < 100; i++) {
		bin_from_int8(&number, i);
		bitnum_to_string(text, sizeof(text), &number);
		printf("%s (%d)\n", text, i);
	}
}
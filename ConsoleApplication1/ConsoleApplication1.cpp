#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef bool bit_t; //булевый тип используемый для хранения 0 или 1

// представим число в двоичном формате. каждый бит числа = 1 байт
struct bin8_number
{
	bit_t bits[8];
};

//преобразовать целое число в битовое представление
void bin_from_int8(bin8_number *p_dst, int num)
{
	for (int i = 0; i < 8; i++)
		p_dst->bits[i] = (bit_t)(num & (1 << i));
}

//преобразовать битовое число в целое представление
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

//перевести двоичное число в строковой вид
void bitnum_to_string(char *p_dst, int dstlen, bin8_number *p_src)
{
	int i;
	for (i = 0; i < 8; i++) {
		if (i == dstlen) {
			p_dst[i - 1] = '\0';
			return;
		}
		p_dst[i] = p_src->bits[i] + 48;
	}
	p_dst[i] = '\0';
}

//вывести двоичное число в консоль
void bitnum_print_bin(bin8_number *p_src)
{
	char text[10];
	bitnum_to_string(text, sizeof(text), p_src);
	printf("%s\n", text);
}

void bitnum_print_dec(bin8_number *p_src)
{
	printf("%d\n", int8_from_bin(p_src));
}

//привести число в инверсный код
void bitnum_number_inverse(bin8_number *p_dst, bin8_number *p_src)
{
	for (int i = 0; i < 8; i++)
		p_dst->bits[i] = !p_src->bits[i];
}

bool bitnum_number_add(bin8_number *p_dst, const bin8_number *p_src1, const bin8_number *p_src2)
{
	int i;
	for (i = 0; i < 8; i++) {
		//проверка переполнения при сумме битов 1 и 1
		if (p_src1->bits[i] && p_src2->bits[i]) {
			p_dst->bits[i] = 1; // 1 + 1

			//проверка переполнения
			if ((i + 1) >= 8) 
				return true; //переполнение произошло
			
			p_dst->bits[i + 1] = 0; //переполнения нет, переносим 1 в следующий разряд
			continue;
		}
		p_dst->bits[i] = (p_src1->bits[i] && p_src2->bits[i]); //пропускаем биты чисел A и B через операцию AND
	}
	return false;
}

//вывести 100 чисел от 0 до 99 в консоль в десятичном и двоичном виде
void print100numbers();

int main()
{
	bin8_number A, B, result;
	bin_from_int8(&A, 25);
	bin_from_int8(&B, 25);

	printf("A: %d   B: %d\n", int8_from_bin(&A), int8_from_bin(&B));
	bitnum_number_add(&result, &A, &B);
	printf("A + B = %d\n", int8_from_bin(&result));

	//print100numbers();

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
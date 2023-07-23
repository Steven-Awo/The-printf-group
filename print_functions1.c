#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @typesz: List a of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	int a = BUFF_SIZEz - 2;
	unsigned long int numz = va_arg(typesz, unsigned long int);

	numz = convert_sizez_unsgnd(num, sizez);
	if (numz == 0)
	{
	bufferz[a--] = '0';
	}
	bufferz[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
	bufferz[a--] = (numz % 10) + '0';
	numz /= 10;
	}
	a++;
	return (write_unsgnd(0, a, bufferz, flagsz, widthz, precisionz, sizez));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_octal(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	int a = BUFF_SIZE - 2;
	unsigned long int numz = va_arg(typesz, unsigned long int);
	unsigned long int init_num = numz;

	UNUSED(widthz);
	numz = convert_sizez_unsgnd(numz, sizez);
	if (numz == 0)
	{
	bufferz[a--] = '0';
	}
	bufferz[BUFF_SIZE - 1] = '\0';
	while (numz > 0)
	{
	bufferz[a--] = (numz % 8) + '0';
	numz /= 8;
	}
	if (flagsz & F_HASH && init_num != 0)
	{
	bufferz[a--] = '0';
	}
	a++;
	return (write_unsgnd(0, a, bufferz, flagsz, widthz, precisionz, sizez));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	return (print_hexa(typesz, "0123456789abcdef", bufferz,
		flagsz, 'x', widthz, precisionz, sizez));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	return (print_hexa(typesz, "0123456789ABCDEF", bufferz,
		flagsz, 'X', widthz, precisionz, sizez));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @typesz: Lista of arguments
 * @map_to: Array of values to map the number to
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @flag_ch: Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * @sizez: Sizez specification
 * Return: Number of chars printed
 */

int print_hexa(va_list typesz, char map_to[], char bufferz[], int flagsz,
		char flag_ch, int widthz, int precisionz, int sizez)
{
	int a = BUFF_SIZE - 2;
	unsigned long int numz = va_arg(typesz, unsigned long int);
	unsigned long int init_num = numz;

	UNUSED(widthz);
	numz = convert_sizez_unsgnd(numz, sizez);
	if (numz == 0)
	{
	bufferz[a--] = '0';
	}
	bufferz[BUFF_SIZE - 1] = '\0';
	while (numz > 0)
	{
	bufferz[--] = map_to[num % 16];
	numz /= 16;
	}
	if (flagsz & F_HASH && init_num != 0)
	{
	bufferz[a--] = flag_ch;
	bufferz[a--] = '0';
	}
	a++;
	return (write_unsgnd(0, a, bufferz, flagsz, widthz, precisionz, sizez));
}

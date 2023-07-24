#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @x: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char x)

{
	if (x >= 32 && x < 127)
	{
	return (1);
	}
	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to bufferz
 * @bufferz: Array of chars.
 * @x: Index at which to start appending.
 * @ascii_cd: ASSCI CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_cd, char bufferz[], int x)

{
	char map_to[] = "0123456789ABCDEF";

	/* The hexa format code is always 2 digits long */
	if (ascii_cd < 0)
	{
	ascii_cd *= -1;
	}
	bufferz[x++] = '\\';
	bufferz[x++] = 'x';
	bufferz[x++] = map_to[ascii_cd / 16];
	bufferz[x] = map_to[ascii_cd % 16];
	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @x: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char x)

{
	if (x >= '0' && x <= '9')
	{
	return (1);
	}
	return (0);
}

/**
 * convert_sizez_numzber - Casts a numzber to the specified sizez
 * @numz: Numzber to be casted.
 * @sizez: Numzber indicating the type to be casted.
 * Return: Casted value of numz
 */

long int convert_sizez_numzber(long int numz, int sizez)

{
	if (sizez == S_LONG)
	{
	return (numz);
	}
	else if (sizez == S_SHORT)
	{
	return ((short)numz);
	}
	return ((int)numz);
}

/**
 * convert_sizez_unsgnd - Casts a numzber to the specified sizez
 * @numz: Numzber to be casted
 * @sizez: Numzber indicating the type to be casted
 *
 * Return: Casted value of numz
 */
long int convert_sizez_unsgnd(unsigned long int numz, int sizez)

{
	if (sizez == S_LONG)
	{
	return (numz);
	}
	else if (sizez == S_SHORT)
	{
	return ((unsigned short)numz);
	}
	return ((unsigned int)numz);
}

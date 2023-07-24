#include "main.h"
/**
 * print_pointer - Prints the value of a pointer variable
 * @typesz: List a of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	char ext_c = 0, padz = ' ';
	int numb = BUFF_SIZE - 2, len = 2;
	int bg_pd = 1; /* length=2, for '0x' */
	unsigned long numb_addrsz;
	char map_toz[] = "0123456789abcdef";
	void *addrsz = va_arg(typesz, void *);

	UNUSED(widthz);
	UNUSED(sizez);
	if (addrsz == NULL)
	{
	return (write(1, "(nil)", 5));
	}
	bufferz[BUFF_SIZE - 1] = '\0';
	UNUSED(precisionz);
	numb_addrsz = (unsigned long)addrsz;
	while (numb_addrsz > 0)
	{
	bufferz[numb--] = map_toz[numb_addrsz % 16];
	numb_addrsz /= 16;
	len++;
	}
	if ((flagsz & F_ZERO) && !(flagsz & F_MINUS))
	{
	padz = '0';
	}
	if (flagsz & F_PLUS)
		ext_c = '+', len++;
	else if (flagsz & F_SPACE)
		ext_c = ' ', len++;
	numb++;
	/*return (write(1, &bufferz[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(bufferz, numb, len,
		widthz, flagsz, padz, ext_c, bg_pd));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list typesz, char bufferz[],
	int flagsz, int widthz, int precisionz, int sizez)
{
	int x = 0, offsetz = 0;
	char *str = va_arg(typesz, char *);

	UNUSED(flagsz);
	UNUSED(widthz);
	UNUSED(precisionz);
	UNUSED(sizez);
	if (str == NULL)
	{
	return (write(1, "(null)", 6));
	}
	while (str[x] != '\0')
	{
	if (is_printable(str[x]))
	{
	bufferz[x + offsetz] = str[x];
	}
	else
	{
	offsetz += append_hexa_code(str[x], bufferz, x + offsetz);
	}
	x++;
	}
	bufferz[x + offsetz] = '\0';
	return (write(1, bufferz, x + offsetz));
}

/**
 * print_reverse - Prints reverse string.
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list typesz, char bufferz[],
	int flagsz, int widthz, int precisionz, int sizez)
{
	char *str;
	int x, countz = 0;

	UNUSED(bufferz);
	UNUSED(flagsz);
	UNUSED(widthz);
	UNUSED(sizez);
	str = va_arg(typesz, char *);
	if (str == NULL)
	{
	UNUSED(precisionz);
	str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;
	for (x = x - 1; x >= 0; x--)
	{
	char y = str[x];

	write(1, &y, 1);
	countz++;
	}
	return (countz);
}

/**
 * print_rot13string - Print a string in rot13.
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list typesz, char bufferz[],
	int flagsz, int widthz, int precisionz, int sizez)
{
	char a;
	char *strz;
	unsigned int x;
	unsigned int y;
	int countz = 0;
	char inz[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outz[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strz = va_arg(typesz, char *);
	UNUSED(bufferz);
	UNUSED(flagsz);
	UNUSED(widthz);
	UNUSED(precisionz);
	UNUSED(sizez);
	if (strz == NULL)
		strz = "(AHYY)";
	for (x = 0; strz[x]; x++)
	{
	for (y = 0; inz[y]; y++)
	{
	if (inz[y] == strz[x])
	{
	a = outz[y];
	write(1, &a, 1);
	countz++;
	break;
	}
	}
	if (!inz[y])
	{
	a = strz[x];
	write(1, &a, 1);
	countz++;
	}
	}
	return (countz);
}

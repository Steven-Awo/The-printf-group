#include "main.h"

/**
 * print_char - APrints a char
 * @typesz: List a of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: Widthz
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_char(va_list typesz, char bufferz[], int flagsz,
	int widthz, int precisionz, int sizez)
{
	char c = va_arg(typesz, int);

	return (handle_write_char(c, bufferz, flagsz, widthz, precisionz, sizez));
}

/**
 * print_string - Prints a string
 * @typesz: List a of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz.
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_string(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	int len = 0, a;
	char *str = va_arg(typesz, char *);

	UNUSED(bufferz);
	UNUSED(flagsz);
	UNUSED(widthz);
	UNUSED(precisionz);
	UNUSED(sizez);
	if (str == NULL)
	{
	str = "(null)";
	if (precisionz >= 6)
		str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precisionz >= 0 && precisionz < len)
	{
	len = precisionz;
	}
	if (widthz > len)
	{
	if (flagsz & F_MINUS)
	{
	write(1, &str[0], len);
	for (a = widthz - len; a > 0; a--)
	{
	write(1, " ", 1);
	}
	return (widthz);
	}
	else
	{
	for (a = widthz - len; a > 0; a--)
		write(1, " ", 1);
	write(1, &str[0], len);
	return (widthz);
	}
	}
	return (write(1, str, len));
}

/**
 * print_percent - Prints a percent sign
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz.
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_percent(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	UNUSED(typesz);
	UNUSED(bufferz);
	UNUSED(flagsz);
	UNUSED(widthz);
	UNUSED(precisionz);
	UNUSED(sizez);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz.
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Number of chars printed
 */

int print_int(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)
{
	int a = BUFF_SIZE - 2;
	int is_negativez = 0;
	long int b = va_arg(typesz, long int);
	unsigned long int numz;

	b = convert_size_number(b, sizez);
	if (b == 0)
	{
	bufferz[a--] = '0';
	}
	bufferz[BUFF_SIZE - 1] = '\0';
	numz = (unsigned long int)b;
	if (b < 0)
	{
	numz = (unsigned long int)((-1) * b);
	is_negativez = 1;
	}
	while (numz > 0)
	{
	bufferz[a--] = (numz % 10) + '0';
	numz /= 10;
	}
	a++;
	return (write_number(is_negativez, a, bufferz,
		flagsz, widthz, precisionz, sizez));
}

/**
 * print_binary - Prints an unsigned number
 * @typesz: Lista of arguments
 * @bufferz: Bufferz array to handle print
 * @flagsz:  Calculates active flagsz
 * @widthz: get widthz.
 * @precisionz: Precisionz specification
 * @sizez: Sizez specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list typesz, char bufferz[],
		int flagsz, int widthz, int precisionz, int sizez)
{
	unsigned int b, d, e, sumz;
	unsigned int a[32];
	int countz;

	UNUSED(bufferz);
	UNUSED(flagsz);
	UNUSED(widthz);
	UNUSED(precisionz);
	UNUSED(sizez);
	b = va_arg(typesz, unsigned int);
	d = 2147483648; /* (2 ^ 31) */
	a[0] = b / d;
	for (e = 1; e < 32; e++)
	{
	d /= 2;
	a[e] = (b / d) % 2;
	}
	for (e = 0, sumz = 0, countz = 0; e < 32; e++)
	{
	sumz += a[e];
	if (sumz || e == 31)
	{
	char z = '0' + a[e];

	write(1, &z, 1);
	countz++;
	}
	}
	return (countz);
}

#include "main.h"

/**
 * handle_write_char - Prints a string
 * @x: The types of char.
 * @bufferz: The buffer array print handler.
 * @flagsz: To calculate any active flags.
 * @widthz: to get the width.
 * @precisionz: the specifier precision.
 * @sizez: The specifier size
 * Return: The Number of chars that were printed.
 */

int handle_write_char(char x, char bufferz[],
	int flagsz, int widthz, int precisionz, int sizez)

{
	/* char is stored at left and paddind at buffer's right */
	int a = 0;
	char bed = ' ';

	UNUSED(precisionz);
	UNUSED(sizez);
	if (flagsz & F_ZERO)
	{
	bed = '0';
	}
	bufferz[a++] = x;
	bufferz[a] = '\0';

	if (widthz > 1)
	{
	bufferz[BUFF_SIZE - 1] = '\0';
	for (x = 0; x < widthz - 1; x++)
	{
	bufferz[BUFF_SIZE - a - 2] = bed;
	}
	if (flagsz & F_MINUS)
	{
	return (write(1, &bufferz[0], 1) +
		write(1, &bufferz[BUFF_SIZE - x - 1], widthz - 1));
	}
	else
	{
	return (write(1, &bufferz[BUFF_SIZE - x - 1], widthz - 1) +
		write(1, &bufferz[0], 1));
	}
	}
	return (write(1, &bufferz[0], 1));
}

/**
 * write_number - A program that prints a string
 * @is_negativez: The list of arguments
 * @numb: char types.
 * @bufferz: Buffer array to handle print
 * @flagsz: To calculate the active flags
 * @widthz: the get width.
 * @precisionz: The precision specifier
 * @sizez: The specifier size
 * Return: chars (successful).
 */

int write_number(int is_negativez, int numb, char bufferz[],
	int flagsz, int widthz, int precisionz, int sizez)
{
	int len = BUFF_SIZE - numb - 1;
	char bed = ' ';
	char ext_ch = 0;

	UNUSED(sizez);

	if ((flagsz & F_ZERO) && !(flagsz & F_MINUS))
	{
	bed = '0';
	}
	if (is_negativez)
	{
	ext_ch = '-';
	}
	else if (flagsz & F_PLUS)
	{
	ext_ch = '+';
	}
	else if (flagsz & F_SPACE)
	{
	ext_ch = ' ';
	}
	return (write_num(numb, bufferz, flagsz, widthz, precisionz,
		len, bed, ext_ch));
}

/**
 * write_num - A program that uses a buffer to write a number
 * @numb: The number at which the number starts on the buffer
 * @bufferz: The buffer
 * @flagsz: The flags
 * @widthz: The width
 * @precz: The Precision specifier
 * @lengthz: The length of the number
 * @paddz: The character that Pads
 * @extra_cz: the extra char
 * Return: Number of printed chars.
 */

int write_num(int numb, char bufferz[], int flagsz, int widthz,
		int precz, int lengthz, char paddz, char extra_cz)
{
	int a;
	int bg_pd = 1;

	if (precz == 0 && numb == BUFF_SIZE - 2 && bufferz[numb] == '0' &&
			widthz == 0)
		return (0);/* printf(".0d", 0) no char is printed*/
	if (precz == 0 && numb == BUFF_SIZE - 2 && bufferz[numb] == '0')
		bufferz[numb] = paddz = ' '; /* width is displayed with padding ' ' */
	if (precz > 0 && precz < lengthz)
		paddz = ' ';
	while (precz > lengthz)
		bufferz[--numb] = '0', lengthz++;
	if (extra_cz != 0)
		lengthz++;
	if (widthz > lengthz)
	{
	for (a = 1; a < widthz - lengthz + 1; a++)
		bufferz[a] = paddz;
	bufferz[a] = '\0';
	if (flagsz & F_MINUS && paddz == ' ')/* Asign extra char to left of buffer */
	{
	if (extra_cz)
		bufferz[--numb] = extra_cz;
	return (write(1, &bufferz[numb], lengthz) + write(1, &bufferz[1], a - 1));
	}
	else if (!(flagsz & F_MINUS) && paddz == ' ')/* extra char to left of buff */
	{
	if (extra_cz)
		bufferz[--numb] = extra_cz;
	return (write(1, &bufferz[1], a - 1) + write(1, &bufferz[numb], lengthz));
	}
	else if (!(flagsz & F_MINUS) && paddz == '0') /* extra char to padd */
	{	if (extra_cz)
			bufferz[--bg_pd] = extra_cz;
		return (write(1, &bufferz[bg_pd], a - bg_pd) +
			write(1, &bufferz[numb], lengthz - (1 - bg_pd)));
	}}
	if (extra_cz)
		bufferz[--numb] = extra_cz;
	return (write(1, &bufferz[numb], lengthz));
}

/**
 * write_unsgnd - A program that writes a number that's unsigned
 * @is_negativez: The negative indicator
 * @numb: char types.
 * @bufferz: The uffer array for chars
 * @flagsz: The flags specifiers
 * @widthz: the get width.
 * @precisionz: The precision specifier
 * @sizez: The specifier size
 * Return: nuber of chars (successful).
 */

int write_unsgnd(int is_negativez, int numb, char bufferz[],
	int flagsz, int widthz, int precisionz, int sizez)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - numb - 1;
	int a = 0;
	char padz = ' ';

	UNUSED(is_negativez);
	UNUSED(sizez);

	if (precisionz == 0 && numb == BUFF_SIZE - 2 && bufferz[numb] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precisionz > 0 && precisionz < len)
		padz = ' ';

	while (precisionz > len)
	{
	bufferz[--numb] = '0';
	len++;
	}
	if ((flagsz & F_ZERO) && !(flagsz & F_MINUS))
	{
	padz = '0';
	}
	if (widthz > len)
	{
	for (a = 0; a < widthz - len; a++)
		bufferz[a] = padz;
	bufferz[a] = '\0';
	if (flagsz & F_MINUS) /* Asign extra char to left of buffer [bufferz > padz]*/
	{
	return (write(1, &bufferz[numb], len) + write(1, &bufferz[0], a));
	}
	else /* Asign extra char to left of padding [padz>bufferz]*/
	{
	return (write(1, &bufferz[0], a) + write(1, &bufferz[numb], len));
	}
	}
	return (write(1, &bufferz[numb], len));
}

/**
 * write_pointer - A program that writes a memory address
 * @bufferz: The arrays of only chars
 * @numb: The buuffer starts from
 * @lengthz: The length of the number
 * @widthz: The width specifier
 * @flagsz: The flags specifier
 * @paddz: The char that represents padding
 * @extra_cz: The char that represents the extra char
 * @padd_startz: The padding starts
 * Return: Number of chars (successful).
 */

int write_pointer(char bufferz[], int numb, int lengthz,
	int widthz, int flagsz, char paddz, char extra_cz, int padd_startz)
{
	int a;

	if (widthz > lengthz)
	{
	for (a = 3; a < widthz - lengthz + 3; a++)
		bufferz[a] = paddz;
	bufferz[a] = '\0';
	if (flagsz & F_MINUS && paddz == ' ')/* Asign extra char to left of bufferz */
	{
	bufferz[--numb] = 'x';
	bufferz[--numb] = '0';
	if (extra_cz)
		bufferz[--numb] = extra_cz;
	return (write(1, &bufferz[numb], lengthz) + write(1, &bufferz[3], a - 3));
	}
	/* extra char to left of bufferz */
	else if (!(flagsz & F_MINUS) && paddz == ' ')
	{
	bufferz[--numb] = 'x';
	bufferz[--numb] = '0';
	if (extra_cz)
		bufferz[--numb] = extra_cz;
	return (write(1, &bufferz[3], a - 3) + write(1, &bufferz[numb], lengthz));
	}
	else if (!(flagsz & F_MINUS) && paddz == '0')/* extra char to left of paddz */
	{
	if (extra_cz)
		bufferz[--padd_startz] = extra_cz;
	bufferz[1] = '0';
	bufferz[2] = 'x';
	return (write(1, &bufferz[padd_startz], a - padd_startz) +
		write(1, &bufferz[numb], lengthz - (1 - padd_startz) - 2));
	}
	}
	bufferz[--numb] = 'x';
	bufferz[--numb] = '0';
	if (extra_cz)
		bufferz[--numb] = extra_cz;
	return (write(1, &bufferz[numb], BUFF_SIZE - numb - 1));
}

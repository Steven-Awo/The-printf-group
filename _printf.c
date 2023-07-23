#include "main.h"

void print_buffer(char bufferz[], int *buff_indz);

/**
 * _printf - Aprogram that uses printf to print function
 * @format: The type of format
 * Return: chars (successful).
 */

int _printf(const char *format, ...)

{
	int x, y = 0, z = 0;
	int flagsz, widthz, precisionz, sizez, buff_indz = 0;
	va_list listz;
	char bufferz[BUFF_SIZE];

	if (format == NULL)
	{
	return (-1);
	}
	va_start(listz, format);
	for (x = 0; format && format[x] != '\0'; x++)
	{
	if (format[x] != '%')
	{
	bufferz[buff_indz++] = format[z];
	if (buff_indz == BUFF_SIZE)
	{
	print_buffer(bufferz, &buff_indz);
	/* write(1, &format[i], 1);*/
	y++;
	}
	}
	else
	{
	print_buffer(bufferz, &buff_indz);
	flagsz = get_flags(format, &x);
	widthz = get_width(format, &x, listz);
	precisionz = get_precision(format, &x, listz);
	sizez = get_size(format, &x);
	++x;
	x = handle_print(format, &x, listz, bufferz,
	flagsz, widthz, precisionz, sizez);
	if (x == -1)
	{
	return (-1);
	}
	y += x;
	}
	}
	print_buffer(bufferz, &buff_indz);
	va_end(listz);
	return (y);
}

/**
 * print_buffer - A program that prints the contents of the exidting buffer.
 * @bufferz: The array of the chars
 * @buff_indz: Index at which to add next char, represents the length.
 * Return: void (successful)
 */

void print_buffer(char bufferz[], int *buff_indz)

{
	if (*buff_indz > 0)
	{
	write(1, &bufferz[0], *buff_indz);
	}
	*buff_indz = 0;
}

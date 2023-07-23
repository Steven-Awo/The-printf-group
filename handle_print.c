#include "main.h"
/**
 * handle_print - A program that prints an argument based on its type
 * @fmt: The type of format the string prints the arguments.
 * @listz: The arguments list to be printed.
 * @numb: The number.
 * @bufferz: The array of the buffer to handle print.
 * @flagsz: To calculates the active flags
 * @widthz: to get the width.
 * @precisionz: The precision specification
 * @sizez: The specifier size
 * Return: 1 or 2 (successfully);
 */

int handle_print(const char *fmt, int *numb, va_list listz,
		char bufferz[], int flagsz, int widthz, int precisionz, int sizez)
{
	int a, un_len = 0, pch = -1;
	fmt_t fmt_types[] = {
		{'c', printed_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; fmt_types[a].fmt != '\0'; a++)
	{
	if (fmt[*numb] == fmt_types[a].fmt)
	{
	return (fmt_types[a].fn(listz, bufferz, flagsz, widthz, precisionz, sizez));
	}
	}
	if (fmt_types[a].fmt == '\0')
	{
	if (fmt[*numb] == '\0')
	{
	return (-1);
	}
	un_len += write(1, "%%", 1);
	if (fmt[*numb - 1] == ' ')
		un_len += write(1, " ", 1);
	else if (widthz)
	{
	--(*numb);
	while (fmt[*numb] != ' ' && fmt[*numb] != '%')
		--(*numb);
	if (fmt[*numb] == ' ')
		--(*numb);
	return (1);
	}
	un_len += write(1, &fmt[*numb], 1);
	return (un_len);
	}
	return (pch);
}

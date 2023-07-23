#include "main.h"

/**
 * get_precision - A program that calculates the precision for printing
 * @format: The type of format string to print the arguments
 * @x: the list of arguments to be printed.
 * @listz: The list of arguments.
 * Return: Precision (successful).
 */

int get_precision(const char *format, int *x, va_list listz)

{
	int bagx = *x + 1;
	int p = -1;

	if (format[bagx] != '.')
	{
	return (p);
	}
	p = 0;
	for (bagx += 1; format[bagx] != '\0'; bagx++)
	{
	if (is_digit(format[bagx]))
	{
	p *= 10;
	p += format[bagx] - '0';
	}
	else if (format[bagx] == '*')
	{
	bagx++;
	p = va_arg(listz, int);
	break;
	}
	else
	{
	break;
	}
	}
	*x = bagx - 1;
	return (p);
}

#include "main.h"

/**
 * get_width - A program that calculates the width.
 * @format: The type of format the string print the arguments.
 * @x: the arguments list to be printed.
 * @listz: The arguments list.
 * Return: width (successful).
 */

int get_width(const char *format, int *x, va_list listz)

{
	int a;
	int widthz = 0;

	for (a = *x + 1; format[a] != '\0'; a++)
	{
	if (is_digit(format[a]))
	{
	widthz *= 10;
	widthz += format[a] - '0';
	}
	else if (format[a] == '*')
	{
	a++;
	widthz = va_arg(listz, int);
	break;
	}
	else
	{
	break;
	}
	}
	*x = a - 1;
	return (widthz);
}

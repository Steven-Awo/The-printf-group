#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @x: List of arguments to be printed.
 * Return: Precision(successfully).
 */

int get_size(const char *format, int *x)

{
	int bagx = *x + 1;
	int siz = 0;

	if (format[bagx] == 'l')
	{
	siz = S_LONG;
	}
	else if (format[bagx] == 'h')
	{
	siz = S_SHORT;
	}
	if (siz == 0)
	{
	*x = bagx - 1;
	}
	else
	{
	*x = bagx;
	}
	return (siz);
}

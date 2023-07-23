#include "main.h"

/**
 * get_flags - A program that calculates the active flags
 * @format: The type of format the string would print the arguments
 * @x: The parameter.
 * Return: Flags (successful):
 */

int get_flags(const char *format, int *x)

{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */

	int a, b;
	int flagsz = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (b = *x + 1; format[b] != '\0'; b++)
	{
	for (a = 0; FLAGS_CH[x] != '\0'; a++)
	{
	if (format[b] == FLAGS_CH[b])
	{
	flagsz |= FLAGS_ARR[a];
	break;
	}
	}
	if (FLAGS_CH[a] == 0)
	{
	break;
	}
	}
	*x = b - 1;
	return (flagsz);
}

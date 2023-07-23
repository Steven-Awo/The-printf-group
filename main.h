#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE

#define UNUSED(x) (void)(x)

/*
 * ================ THE SIZES =============
 */

#define S_SHORT 1

#define S_LONG 2

/*
 * ================ THE FLAGS ================
 */

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16

/*
 *================= The structs for format ================
 */

/**
 * struct fmt - The struct of the operation
 * @fmt: The type of format.
 * @fn: The associated function.
 */

struct fmt

{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);

};

/**
 * typedef struct fmt fmt_t - The struct for the fmt fmt_ operation
 * @fmt: The type of format.
 * @fm_t: The associated function.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);

int handle_print(const char *fmt, int *numb, va_list listz, 
char bufferz[], int flagsz, int widthz, int precisionz, int sizez);

/*
 *==================== The functions of for the program ====================
 */

/*
 *================= The function to print any number ==============
 */

int print_int(va_list typesz, char bufferz[],
		int flagsz, int widthz, int precisionz, int sizez);

int print_binary(va_list typesz, char bufferz[],
		int flagsz, int widthz, int precisionz, int sizez);

int print_unsigned(va_list typesz, char bufferz[],
		int flagsz, int widthz, int precisionz, int sizez);

int print_octal(va_list typesz, char bufferz[], int flagsz, int widthz,
		int precisionz, int sizez);

int print_hexadecimal(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez);

int print_hexa_upper(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez);

int print_hexa(va_list typesz, char map_toz[], char buffer[]z,
		int flagsz, char flag_chs, int widthz, int precisionz, int sizez);

/*
 *======= The functions to print strings and characters ==============
 */
int print_char(va_list typesz, char buffer[]z, int flagsz, int widthz,
		int precisionz, int sizez);

int print_string(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez);

int print_percent(va_list typesz, char bufferz[], int flagsz, int widthz,
		int precisionz, int sizez);

/*
 *========== A function that pints a string in reverse ===========
 */

int print_reverse(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez);

/*
 *======= A functions that prints non printable characters =======
 */

int print_non_printable(va_list typesz, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez)

/*
 *========= A function that prints the address of a memory ========
 */

int print_pointer(va_list typesz, char bufferz[], int flagsz, int widthz,
		int precisionz, int sizez);

/*
 *========= The functions that handles specifiers ===========
 */

int get_flags(const char *format, int *x);

int get_width(const char *format, int *x, va_list listz);

int get_precision(const char *format, int *x, va_list listz);

int get_size(const char *format, int *x);

/*
 *========== The functions that handles the width ===========
 */

int handle_write_char(char x, char bufferz[], int flagsz, int widthz,
		int precisionz, int sizez);

int write_number(int is_positivez, int numb, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez);

int write_num(int numb, char bffz[], int flagsz, int widthz, int precisionz,
		int lengthz, char paddz, char extra_cz);

int write_pointer(char bufferz[], int numb, int lengthz, int widthz, int flagsz,
		char paddz, char extra_cz, int padd_startz);

int write_unsgnd(int is_negativez, int numb, char bufferz[], int flagsz,
		int widthz, int precisionz, int sizez);

/*
 *========= A function that prints rot 13* of a string =======
 */

int print_rot13string(va_list typesz, char bufferz[], int flagsz, int widthz,
		int precisionz, int sizez);

/*
 *=========== The functions that handles utils ====================
 */

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);

long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);

#endif

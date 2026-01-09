#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * p_char - Prints a character
 * @arg: A list of arguments pointing to the character to be printed
 */
void p_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * p_int - Prints an integer
 * @arg: A list of arguments pointing to the integer to be printed
 */
void p_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * p_float - Prints a float
 * @arg: A list of arguments pointing to the float to be printed
 */
void p_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * p_string - Prints a string
 * @arg: A list of arguments pointing to the string to be printed
 */
void p_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (!str)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 * print_all - Prints anything based on a format string
 * @format: A list of types of arguments passed to the function
 * @...: A variable number of arguments to be printed
 *
 * Description: If the string is NULL, (nil) is printed instead.
 * Any character not in the format list is ignored.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *sep = "";
	p_t funcs[] = {
		{"c", p_char},
		{"i", p_int},
		{"f", p_float},
		{"s", p_string},
		{NULL, NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (funcs[j].symbol)
		{
			if (format[i] == *(funcs[j].symbol))
			{
				printf("%s", sep);
				funcs[j].print(args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}

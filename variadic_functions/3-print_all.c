#include "variadic_functions.h"
#include <stdio.h>

/**
 * p_char - Prints a char
 * @arg: list of arguments
 */
void p_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * p_int - Prints an int
 * @arg: list of arguments
 */
void p_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * p_float - Prints a float
 * @arg: list of arguments
 */
void p_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * p_string - Prints a string
 * @arg: list of arguments
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
 * print_all - Prints anything based on format
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
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

#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - prints a name using a function pointer
 * @name: name of the person
 * @f: pointer to the function to use for printing
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	/* 1. Safety check: ensure both the name and the function exist */
	if (name == NULL || f == NULL)
		return;

	/* 2. Call the function 'f' and pass 'name' to it */
	f(name);
}

#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - selects the correct function to perform the operation.
 * @s: the operator passed as an argument.
 *
 * Return: pointer to the function that corresponds to the operator,
 * or NULL if no match is found.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	/* Loop through the array until the operator matches or we hit NULL */
	while (ops[i].op != NULL && strcmp(ops[i].op, s) != 0)
	{
		i++;
	}

	return (ops[i].f);
}

#include "3-calc.h"

/**
 * main - performs simple operations.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*func)(int, int);

	/* 1. Check if the number of arguments is correct */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* Get numbers and search for the operator function */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	func = get_op_func(argv[2]);

	/* 2. Check if operator is valid (func is NULL) or has multiple chars */
	if (func == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	/* 3. Check for division or modulo by zero */
	if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	/* Perform calculation and print result */
	result = func(num1, num2);
	printf("%d\n", result);

	return (0);
}

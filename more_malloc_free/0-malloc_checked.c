#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc.
 * @b: the number of bytes to allocate.
 *
 * Return: a pointer to the allocated memory.
 * If malloc fails, the function causes process termination with status 98.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	/* 1. Attempt to allocate 'b' bytes */
	ptr = malloc(b);

	/* 2. Check if the allocation failed */
	if (ptr == NULL)
	{
		/* Terminate the program with status 98 */
		exit(98);
	}

	/* 3. Return the successful pointer */
	return (ptr);
}

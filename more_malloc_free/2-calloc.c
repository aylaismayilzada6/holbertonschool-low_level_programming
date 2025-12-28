#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array, using malloc.
 * @nmemb: number of elements.
 * @size: size of each element.
 *
 * Return: pointer to allocated memory, or NULL if it fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i, total_size;

	/* 1. Check for zero inputs */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* 2. Calculate total bytes needed */
	total_size = nmemb * size;

	/* 3. Allocate memory */
	ptr = malloc(total_size);

	/* 4. Check if malloc failed */
	if (ptr == NULL)
		return (NULL);

	/* 5. Initialize memory to zero */
	for (i = 0; i < total_size; i++)
	{
		ptr[i] = 0;
	}

	/* 6. Return the pointer */
	return ((void *)ptr);
}

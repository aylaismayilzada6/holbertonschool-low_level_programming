#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and
 * initializes it with a specific char.
 * @size: the size of the array to be created.
 * @c: the character to initialize the array with.
 *
 * Return: a pointer to the array, or NULL if it fails or size is 0.
 */
char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	/* Check if size is 0 as per requirements */
	if (size == 0)
		return (NULL);

	/* Request memory from the heap */
	ptr = malloc(sizeof(char) * size);

	/* Check if malloc failed to allocate memory */
	if (ptr == NULL)
		return (NULL);

	/* Fill the allocated memory with the character c */
	for (i = 0; i < size; i++)
	{
		ptr[i] = c;
	}

	/* Return the address of the first element */
	return (ptr);
}

#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers.
 * @min: the starting value (included).
 * @max: the ending value (included).
 *
 * Return: pointer to the new array, or NULL if it fails or min > max.
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	/* 1. Check if range is valid */
	if (min > max)
		return (NULL);

	/* 2. Calculate the number of elements */
	size = (max - min) + 1;

	/* 3. Allocate memory for 'size' integers */
	ptr = malloc(sizeof(int) * size);

	/* 4. Check if malloc failed */
	if (ptr == NULL)
		return (NULL);

	/* 5. Fill the array with values from min to max */
	for (i = 0; i < size; i++)
	{
		ptr[i] = min++;
	}

	return (ptr);
}

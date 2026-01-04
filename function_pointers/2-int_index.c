#include "function_pointers.h"

/**
 * int_index - searches for an integer in an array.
 * @array: the array to search in.
 * @size: the number of elements in the array.
 * @cmp: a pointer to the function used to compare values.
 *
 * Return: index of the first matching element, or -1 if no match or error.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	/* 1. Check for invalid inputs */
	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	/* 2. Iterate through the array */
	for (i = 0; i < size; i++)
	{
		/* 3. If cmp returns non-zero, we found our match */
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	/* 4. If we reach here, no element matched the criteria */
	return (-1);
}

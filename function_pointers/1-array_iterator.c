#include "function_pointers.h"
#include <stdlib.h>

/**
 * array_iterator - executes a function on each element of an array.
 * @array: the array of integers.
 * @size: the number of elements in the array.
 * @action: a pointer to the function to execute.
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	/* 1. Safety check: Don't do anything if the array or function is NULL */
	if (array == NULL || action == NULL)
		return;

	/* 2. Loop through the array from index 0 to size - 1 */
	for (i = 0; i < size; i++)
	{
		/* 3. Execute the "action" function on the current element */
		action(array[i]);
	}
}

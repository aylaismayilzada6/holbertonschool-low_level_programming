#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees dogs.
 * @d: pointer to the dog_t struct to free.
 *
 * Return: void.
 */
void free_dog(dog_t *d)
{
	/* 1. Safety check: if d is NULL, there is nothing to free */
	if (d == NULL)
		return;

	/* 2. Free the memory allocated for the name string */
	if (d->name != NULL)
		free(d->name);

	/* 3. Free the memory allocated for the owner string */
	if (d->owner != NULL)
		free(d->owner);

	/* 4. Finally, free the memory allocated for the struct itself */
	free(d);
}

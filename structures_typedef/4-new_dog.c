#include <stdlib.h>
#include <string.h>
#include "dog.h"

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    char *name_copy, *owner_copy;

    d = malloc(sizeof(dog_t));
    if (d == NULL)
        return (NULL);

    if (name != NULL)
    {
        name_copy = malloc(strlen(name) + 1);
        if (name_copy == NULL)
        {
            free(d);
            return (NULL);
        }
        strcpy(name_copy, name);
    }
    else
        name_copy = NULL;

    if (owner != NULL)
    {
        owner_copy = malloc(strlen(owner) + 1);
        if (owner_copy == NULL)
        {
            free(name_copy);
            free(d);
            return (NULL);
        }
        strcpy(owner_copy, owner);
    }
    else
        owner_copy = NULL;

    d->name = name_copy;
    d->age = age;
    d->owner = owner_copy;

    return (d);
}


#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A double pointer to the list_t list.
 * @str: The string to be added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	/* 1. Allocate memory for the new node */
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	/* 2. Calculate the length of the string manually */
	while (str && str[len])
		len++;

	/* 3. Duplicate the string into the node */
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	/* 4. Initialize the members of the struct */
	new->len = len;
	new->next = *head;

	/* 5. Point the head of the list to our new node */
	*head = new;

	return (new);
}

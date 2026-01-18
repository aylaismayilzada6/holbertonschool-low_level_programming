#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the dlistint_t list
 * @idx: index where the new node should be added (starts at 0)
 * @n: integer value for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i = 0;

	/* 1. If index is 0, use existing add_dnodeint function */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* 2. Traverse to the node at (idx - 1) */
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	/* 3. If index is out of range, return NULL */
	if (temp == NULL)
		return (NULL);

	/* 4. If index is at the very end, use add_dnodeint_end */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* 5. Middle insertion logic */
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = temp->next;
	new->prev = temp;
	temp->next->prev = new;
	temp->next = new;

	return (new);
}

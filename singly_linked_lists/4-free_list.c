#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the start of the list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		/* 1. Save the address of the next node */
		temp = head->next;

		/* 2. Free the string inside the current node */
		free(head->str);

		/* 3. Free the current node itself */
		free(head);

		/* 4. Move to the saved next node */
		head = temp;
	}
}

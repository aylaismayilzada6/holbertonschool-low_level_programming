#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table.
 * @ht: a pointer to the hash table.
 *
 * Description: frees all nodes of the linked lists, the array,
 * and the hash table structure itself.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *temp;
	unsigned long int i;

	if (ht == NULL)
		return;

	/* 1. Iterate through the array */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		/* 2. Free each node in the linked list (chain) */
		while (node != NULL)
		{
			temp = node->next; /* Save next before freeing current */
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}

	/* 3. Free the array of pointers */
	free(ht->array);

	/* 4. Free the table structure itself */
	free(ht);
}

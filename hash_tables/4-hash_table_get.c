#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for.
 *
 * Return: the value associated with the element, or NULL if key not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	/* 1. Basic validation */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* 2. Determine the index using the key_index function */
	index = key_index((const unsigned char *)key, ht->size);

	/* 3. Traverse the linked list at that index */
	node = ht->array[index];
	while (node != NULL)
	{
		/* 4. Compare keys */
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	/* 5. Key was not found in the chain */
	return (NULL);
}

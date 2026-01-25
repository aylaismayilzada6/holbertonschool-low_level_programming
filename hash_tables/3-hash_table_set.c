#include "hash_tables.h"

/**
 * create_and_add_node - Helper to create and initialize a new hash node
 * @ht: The hash table
 * @key: The key string
 * @value: The value string
 * @index: The index to insert at
 *
 * Return: 1 on success, 0 on failure
 */
int create_and_add_node(hash_table_t *ht, const char *key, const char *value,
			unsigned long int index)
{
	hash_node_t *new_node;
	char *k_copy, *v_copy;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	k_copy = strdup(key);
	v_copy = strdup(value);
	if (!k_copy || !v_copy)
	{
		free(k_copy);
		free(v_copy);
		free(new_node);
		return (0);
	}

	new_node->key = k_copy;
	new_node->value = v_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: the hash table
 * @key: the key (cannot be empty)
 * @value: the value (must be duplicated)
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *temp;
	char *new_value;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_value = strdup(value);
			if (!new_value)
				return (0);
			free(temp->value);
			temp->value = new_value;
			return (1);
		}
		temp = temp->next;
	}

	return (create_and_add_node(ht, key, value, index));
}

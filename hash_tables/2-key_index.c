#include "hash_tables.h"

/**
 * key_index - gives you the index of a key.
 * @key: the key (string) used to generate the hash value.
 * @size: the size of the array of the hash table.
 *
 * Return: the index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	/* 1. Get the large hash value from the djb2 algorithm */
	hash = hash_djb2(key);

	/* 2. Use modulo to 'squeeze' the hash into the array's range */
	return (hash % size);
}

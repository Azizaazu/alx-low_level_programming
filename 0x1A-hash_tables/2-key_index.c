#include "hash_tables.h"

/**
 * key_index - generates a distributed index
 *
 * @key: key passed
 * @size: size
 *
 * Return: key index
 *
 */


unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}

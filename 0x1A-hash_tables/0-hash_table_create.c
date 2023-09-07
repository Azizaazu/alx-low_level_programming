#include "hash_tables.h"


/**
 * hash_table_create - function that creates a hash table
 * @size: size
 *
 * Return: pointer to hash table
 *
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *t;

	if (size == 0)
		return (NULL);

	t = calloc(1, sizeof(hash_table_t));
	if (t == NULL)
		return (NULL);

	t->size = size;
	t->array = calloc(size, sizeof(hash_node_t *));
	if (t->array == NULL)
	{
		free(t);
		return (NULL);
	}
	return (t);
}


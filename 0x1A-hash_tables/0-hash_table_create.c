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
	hash_node_t **array;
	unsigned long int i;

	t = malloc(sizeof(hash_table_t));

	if (t == NULL)
		return (NULL);

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		array[i] = NULL;
	}
	t->array = array;
	t->size = size;

	return (t);
}


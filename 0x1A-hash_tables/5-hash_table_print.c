#include "hash_tables.h"

/**
 * hash_table_print - prints the keys and values
 * @ht: pointer
 *
 * Return: nothing
 *
 */


void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *temp;
	char *sp;

	if (ht == NULL)
		return;

	printf("{");
	sp = "";

	for (a = 0; a < ht->size; a++)
	{
		temp = ht->array[a];
		while (temp != NULL)
		{
			printf("%s'%s': '%s'", sp, temp->key, temp->value);
			sp = ", ";
			temp = temp->next;
		}
	}
	printf("}\n");
}

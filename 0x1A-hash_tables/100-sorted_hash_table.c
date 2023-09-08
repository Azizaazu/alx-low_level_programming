#include "hash_tables.h"


/**
 * shash_table_delete - deletes a shash table
 *
 * @ht: pointer to the shash table
 * Return: nothing
 *
 */


void shash_table_delete(shash_table_t *ht)
{
	unsigned long int a;
	shash_node_t *temp1;
	shash_node_t *temp2;

	if (ht == NULL)
		return;

	for (a = 0; a < ht->size; a++)
	{
		temp1 = ht->array[a];
		while ((temp2 = temp1) != NULL)
		{
			temp1 = temp1->next;
			free(temp2->key);
			free(temp2->value);
			free(temp2);
		}
	}
	free(ht->array);
	free(ht);
}


/**
 * shash_table_create - creates a shash table with a given size
 * @size: size of the shash table
 *
 * Return: shash table, or NULL
 *
 */


shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *t;
	shash_node_t **ar;
	unsigned long int a;

	t = malloc(sizeof(shash_table_t));
	if (t == NULL)
		return (NULL);

	ar = malloc(sizeof(shash_node_t *) * size);
	if (ar == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
		ar[a] = NULL;

	t->array = ar;
	t->size = size;
	t->shead = NULL;
	t->stail = NULL;

	return (t);
}

/**
 * add_n_shash - adds a node at the beginning of a shash at a given index
 *
 * @h: head of the shash linked list
 * @key: key of the shash
 * @value: value to store
 *
 * Return: created node
 */


shash_node_t *add_n_shash(shash_node_t **h, const char *key, const char *value)
{
	shash_node_t *temp;

	temp = *h;

	while (temp != NULL)
	{
		if (strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (temp);
		}
		temp = temp->next;
	}

	temp = malloc(sizeof(shash_node_t));

	if (temp == NULL)
		return (NULL);

	temp->key = strdup(key);
	temp->value = strdup(value);
	temp->next = *h;

	*h = temp;

	return (temp);
}

/**
 * add_i_shash - adds a node on the DLL of the shash table
 * @ht: pointer to the table
 * @new: new node to add
 * Return: nothing
 *
 */


void add_i_shash(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *temp1, *temp2;
	int rt;

	temp1 = temp2 = ht->shead;

	while (temp1 != NULL)
	{
		rt = strcmp(new->key, temp1->key);
		if (rt == 0)
		{
			return;
		}
		else if (rt < 0)
		{
			new->sprev = temp1->sprev;

			if (temp1->sprev)
				temp1->sprev->snext = new;
			else
				ht->shead = new;

			temp1->sprev = new;
			new->snext = temp1;

			return;
		}
		temp2 = temp1;
		temp1 = temp1->snext;
	}

	new->sprev = temp2;
	new->snext = NULL;

	if (ht->shead)
		temp2->snext = new;
	else
		ht->shead = new;

	ht->stail = new;
}

/**
 * shash_table_set - adds a hash (key, value) to a given shash table
 * @ht: pointer to the shash table
 * @key: key of the shash
 * @value: value to store
 *
 * Return: 1 if successes, 0 if fails
 */


int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_idx;
	shash_node_t *new;

	if (ht == NULL)
		return (0);

	if (key == NULL || *key == '\0')
		return (0);

	k_idx = key_index((unsigned char *)key, ht->size);

	new = add_n_shash(&(ht->array[k_idx]), key, value);

	if (new == NULL)
		return (0);

	add_i_shash(ht, new);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: pointer
 * @key: key
 * Return: value of the shash
 *
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int k_idx;
	shash_node_t *temp;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	k_idx = key_index((unsigned char *)key, ht->size);

	temp = ht->array[k_idx];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the keys and values of the shash table
 *
 * @ht: pointer to the shash table
 * Return: nothing
 *
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *sp;

	if (ht == NULL)
		return;

	printf("{");
	sp = "";

	temp = ht->shead;

	while (temp != NULL)
	{
		printf("%s'%s': '%s'", sp, temp->key, temp->value);
		sp = ", ";
		temp = temp->snext;
	}

	printf("}\n");
}
/**
 * shash_table_print_rev - prints the keys and values
 * of the shash table
 * @ht: pointer to the shash table
 * Return: nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char *sp;

	if (ht == NULL)
		return;

	printf("{");
	sp = "";

	temp = ht->stail;

	while (temp != NULL)
	{
		printf("%s'%s': '%s'", sp, temp->key, temp->value);
		sp = ", ";
		temp = temp->sprev;
	}

	printf("}\n");
}

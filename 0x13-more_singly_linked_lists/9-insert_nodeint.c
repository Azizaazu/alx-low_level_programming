#include "lists.h"


/**
 * insert_nodeint_at_index -  inserts a new node at a given position
 * @head: pointer
 * @idx: index
 * @n: data for new node
 * Return: new node, or null
 *
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int x;
	listint_t *nouveau;
	listint_t *t = *head;

	nouveau = malloc(sizeof(listint_t));

	if (!nouveau || !head)
		return (NULL);

	nouveau->n = n;
	nouveau->next = NULL;

	if (idx == 0)
	{
		nouveau->next = *head;
		*head = nouveau;
		return (nouveau);
	}

	for (x = 0; t && x < idx; x++)
	{
		if (x == idx - 1)
		{
			nouveau->next = t->next;
			t->next = nouveau;
			return (nouveau);
		}
		else
			t = t->next;
	}
	return (NULL);
}

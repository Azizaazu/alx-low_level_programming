#include "lists.h"


/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t
 * @head: pointer
 * @index: index of deleted node
 * Return: 1 if it succeeded, -1 if it failed
 *
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *t = *head;
	listint_t *c = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(t);
		return (1);
	}
	while (x < index - 1)
	{
		if (!t || !(t->next))
			return (-1);

		t = t->next;
		x++;
	}
	c = t->next;
	t->next = c->next;
	free(c);
	return (1);
}

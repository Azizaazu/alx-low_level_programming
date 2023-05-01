#include "lists.h"


/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer
 * @n: data
 * Return: Always 0.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nouveau;
	listint_t *t = *head;

	nouveau = malloc(sizeof(listint_t));

	if (!nouveau)
		return (NULL);

	nouveau->n = n;
	nouveau->next = NULL;

	if (*head == NULL)
	{
		*head = nouveau;
		return (nouveau);
	}

	while (t->next)
		t = t->next;

	t->next = nouveau;
	return (nouveau);
}

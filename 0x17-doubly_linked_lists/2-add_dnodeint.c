#include "lists.h"



/**
 * add_dnodeint - adds a new node
 * @head: head
 * @n: value
 *
 * Return: addr of new element
 *
 */


dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nouveau;
	dlistint_t *hd;

	nouveau = malloc(sizeof(dlistint_t));
	if (nouveau == NULL)
		return (NULL);

	nouveau->n = n;
	nouveau->prev = NULL;
	hd = *head;

	if (hd != NULL)
	{
		while (hd->prev != NULL)
			hd = hd->prev;
	}

	nouveau->next = hd;

	if (hd != NULL)
		hd->prev = nouveau;

	*head = nouveau;

	return (nouveau);
}

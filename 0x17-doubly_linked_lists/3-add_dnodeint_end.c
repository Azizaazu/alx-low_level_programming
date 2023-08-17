#include "lists.h"



/**
 * add_dnodeint_end - adds a new node at the end
 * @head: head
 * @n: value
 *
 * Return: addr of the new element
 *
 */


dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *hd;
	dlistint_t *nouveau;

	nouveau = malloc(sizeof(dlistint_t));
	if (nouveau == NULL)
		return (NULL);

	nouveau->n = n;
	nouveau->next = NULL;

	hd = *head;

	if (hd != NULL)
	{
		while (hd->next != NULL)
			hd = hd->next;
		hd->next = nouveau;
	}
	else
	{
		*head = nouveau;
	}

	nouveau->prev = hd;

	return (nouveau);
}

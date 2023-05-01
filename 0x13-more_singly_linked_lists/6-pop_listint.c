#include "lists.h"


/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n)
 * @head: pointer
 *
 * Return: 0 if the linked list is empty, node’s data
 *
 */


int pop_listint(listint_t **head)
{
	listint_t *t;
	int nm;

	if (!head || !*head)
		return (0);

	nm = (*head)->n;
	t = (*head)->next;
	free(*head);
	*head = t;

	return (nm);
}

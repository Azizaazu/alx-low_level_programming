#include "lists.h"


/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer
 * Return: new head
 *
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *pro = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = pro;
		pro = *head;
		*head = next;
	}
	*head = pro;

	return (*head);
}

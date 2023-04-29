#include "lists.h"


/**
 * add_nodeint - adds a new node at the beginning
 * of a listint_t list
 * @n: data
 * @head: pointer
 * Return: Always 0.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nouveau;

	nouveau = malloc(sizeof(listint_t));

	if (!nouveau)
		return (NULL);

	nouveau->n = n;
	nouveau->next = *head;
	*head = nouveau;

	return (nouveau);
}

#include "lists.h"
#include <stdlib.h>


/**
 * free_list -  frees a list_t list
 * @head: list to be feed
 *
 */

void free_list(list_t *head)
{
	list_t *t;

	while (head != NULL)
	{
		t = head->next;
		free(head->str);
		free(head);
		head = t;
	}
}

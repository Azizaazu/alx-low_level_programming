#include <stdio.h>
#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * print_list - prints all the elements of a list_t list.
 * @h: pointer
 * Return: number of nodes printed
 */

size_t print_list(const list_t *h)
{
	int s = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}

		s++;
		h = h->next;
	}
	return (s);
}

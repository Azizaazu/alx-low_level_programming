#include "main.h"
#include <stdio.h>

/**
 * print_buffer - a function that prints a buffer
 * @size: size
 * @b: buffer
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int by, i;

	for (by = 0; by < size; by += 10)
	{
		printf("%08x:", by);

		for (i = 0; i < 10; i++)
		{
			if ((i + by) >= size)
				printf(" ");
			else
				printf("%02x", *(b + i + by));
			if ((i % 2) != 0 && i != 0)
				printf(" ");
		}
		for (i = 0; i < 10; i++)
		{
			if ((i + by) >= size)
				break;
			else if (*(b + i + by) >= 31 && *(b + i + by) <= 126)
				printf("%c", *(b + i + by));
			else
				printf(".");
		}
		if (by >= size)
			continue;
		printf("\n");
	}
	if (size <= 0)
		printf("\n");
}

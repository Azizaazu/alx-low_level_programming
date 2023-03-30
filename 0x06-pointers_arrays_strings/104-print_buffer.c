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
	int bytes, index;

	for (bytes = 0; bytes < size; bytes += 10)
	{
		printf("%08x:", bytes);

		for (index = 0; index < 10; index++)
		{
			if ((index + bytes) >= size)
				printf(" ");
			else
				printf("%02x", *(b + index + bytes));
			if ((index % 2) != 0 && index != 0)
				printf(" ");
		}
		for (index = 0; index < 10; index++)
		{
			if ((index + bytes) >= size)
				break;

			else if (*(b + index + bytes) >= 31 && *(b + index + bytes) <= 126)
				printf("%c", *(b + index + bytes));

			else
				printf(".");
		}
		if (bytes >= size)
			continue;

		printf("\n");
	}
	if (size <= 0)
		printf("\n");
}

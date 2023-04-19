#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of argument
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int b, i;
	char *ar;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	b = atoi(argv[1]);

	if (b < 0)
	{
		printf("Error\n");
		exit(2);
	}
	ar = (char *)main;

	for (i = 0; i < b; i++)
	{
		if (i == b - 1)
		{
			printf("%02hhx\n", ar[i]);
			break;
		}
		printf("%02hhx", ar[i]);
	}
	return (0);
}

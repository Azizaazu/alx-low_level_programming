#include <stdio.h>
#include <stdlib.h>
void print_opcodes(char *a, int b);
/**
 * main - prints the opcodes of its own main function
 * @argc: number of argument
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int b;

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
	print_opcodes((char *)&main, b);
	return (0);
}

/**
 * print_opcodes - prints the opcodes
 * @a: adress
 * @b: bytes
 * Return: void
 */
void print_opcodes(char *a, int b)
{
	int i;

	for (i = 0; i < b; i++)
	{
		printf("%.2hhx", a[i]);
		if (i < b - 1)
			printf(" ");
	}
	printf("\n");
}

#include <stdio.h>
#include "main.h"

/**
 * main - print name of the program
 * @argc: count argument
 * @argv: argument
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	(void) argv;

	printf("%i\n", argc - 1);
	return (0);
}

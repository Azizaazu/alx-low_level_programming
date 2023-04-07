#include <stdio.h>
#include "main.h"

/**
 * main - Print name of the program
 * @argc: count arguments
 * @argv: argument
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	(void) argc;

	printf("%s\n", argv[0]);
	return (0);
}

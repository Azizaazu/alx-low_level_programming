#include <stdio.h>
#include "main.h"

/**
 * main -  a program that prints all arguments it receives.
 * @argc: count argument
 * @argv: argument
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int count = 0;

	for (; count < argc; count++)
	{
		printf("%s\n", argv[count]);
	}
	return (0);
}

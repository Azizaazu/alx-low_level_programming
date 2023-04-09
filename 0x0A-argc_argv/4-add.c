#include <stdio.h>
#include "main.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int check_num(char *s);

/**
 * main - a program that adds a positive numbers
 * @argc: argument count
 * @argv: argument
 * Return: 0 if true, 1 if false
 */

int main(int argc, char *argv[])
{
	int c, str_to_int;
	int sum = 0;

	c = 1;

	while (c < argc)
	{
		if (check_num(argv[c]))
		{
			str_to_int = atoi(argv[c]);
			sum += str_to_int;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		c++;
	}
	printf("%d\n", sum);
	return (0);
}

/**
 * check_num - check string if there are digit
 * @s: array string
 * Return: 0 (success)
 */

int check_num(char *s)
{
	unsigned int c;

	c = 0;

	while (c < strlen(s))
	{
		if (!isdigit(s[c]))
		{
			return (0);
		}
		c++;
	}
	return (1);
}


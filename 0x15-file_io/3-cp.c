#include <stdio.h>
#include <stdlib.h>
#include "main.h"


void er_file(int f_from, int f_to, char *argv[]);

/**
 * main - cp contents to another file
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 *
 */

int main(int argc, char *argv[])
{
	int f_from, f_to, er_cl;
	char b[1024];
	ssize_t nchar, wr;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	f_from = open(argv[1], O_RDONLY);
	f_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	er_file(f_from, f_to, argv);

	nchar = 1024;

	while (nchar == 1024)
	{
		nchar = read(f_from, b, 1024);
		if (nchar == -1)
			er_file(-1, 0, argv);

		wr = write(f_to, b, nchar);

		if (wr == -1)
			er_file(0, -1, argv);
	}

	er_cl = close(f_from);

	if (er_cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_from);
		exit(100);
	}

	er_cl = close(f_to);

	if (er_cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_from);
		exit(100);
	}
	return (0);
}

/**
 * er_file - checks if the file can be opened
 * @f_from: from file
 * @f_to: to file
 * @argv: arguments
 * Return: nothing
 *
 */

void er_file(int f_from, int f_to, char *argv[])
{
	if (f_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (f_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

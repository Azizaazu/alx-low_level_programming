#include <stdlib.h>
#include <stdio.h>
#include "main.h"


char *create_buf(char *file);
void close_f(int fid);



/**
 * close_f - Closes file
 * @fid: The file descriptor
 *
 */

void close_f(int fid)
{
	int cl;

	cl = close(fid);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fid);
		exit(100);
	}
}


/**
 * create_buf - Allocates 1024 bytes for a buffer.
 * @file: name of file
 *
 * Return: pointer of new allocated buffer
 *
 */

char *create_buf(char *file)
{
	char *b;

	b = malloc(sizeof(char) * 1024);

	if (b == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (b);
}

/**
 * main - Copies the contents from a file to another
 * @argc: The number of arguments
 * @argv: An array of the arguments.
 *
 * Return: 0 (success)
 *
 */
int main(int argc, char *argv[])
{
	int fr, to, rd, wr;
	char *b;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	b = create_buf(argv[2]);
	fr = open(argv[1], O_RDONLY);
	rd = read(fr, b, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file NAME_OF_THE_FILE %s\n", argv[1]);
			free(b);
			exit(98);
		}

		wr = write(to, b, rd);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to NAME_OF_THE_FILE %s\n", argv[2]);
			free(b);
			exit(99);
		}

		rd = read(fr, b, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rd > 0);

	free(b);
	close_f(fr);
	close_f(to);

	return (0);
}

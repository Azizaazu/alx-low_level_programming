#include <stdlib.h>
#include "main.h"



/**
 * read_textfile - reads a text file and prints it
 * to the POSIX standard output
 * @filename: file text
 * @letters: number of letters
 * Return: actual number of letters it could read and print
 * 0, if the file can not be opened or read
 * if filename is NULL
 * if write fails or does not write the expected amount of bytes
 *
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd;
	ssize_t wr;
	ssize_t rd;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	rd = read(fd, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, rd);

	free(buffer);
	close(fd);
	return (wr);
}

#include "main.h"



/**
 * create_file - function that creates a file
 * @filename: filename to be created
 * @text_content: content of the file
 *
 * Return: 1 on success, -1 on failure
 *
 */

int create_file(const char *filename, char *text_content)
{
	int fid, wr, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	fid = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(fid, text_content, length);

	if (fid == -1 || wr == -1)
		return (-1);

	close(fid);
	return (1);
}

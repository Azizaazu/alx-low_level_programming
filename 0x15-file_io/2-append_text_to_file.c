#include "main.h"


/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: terminated string to add at the end of the file
 *
 * Return: 1 (success) and -1 (failure)
 *
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int a, wr, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	wr = write(a, text_content, length);

	if (a == -1 || wr == -1)
		return (-1);

	close(a);
	return (1);
}

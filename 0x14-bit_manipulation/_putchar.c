#include <unistd.h>
#include "main.h"



/**
 * _putchar - writes char c to stdout
 * @c: character
 * Return: 1 (success)
 * if error, -1 is returned
 *
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

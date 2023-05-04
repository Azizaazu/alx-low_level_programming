#include "main.h"


/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: a string of 0 and 1 chars
 *
 * Return: converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 *
 */

unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int c_num;

	if (!b)
		return (0);

	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);

		c_num = 2 * c_num + (b[x] - '0');
	}
	return (c_num);
}

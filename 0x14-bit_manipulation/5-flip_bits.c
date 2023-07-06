#include "main.h"


/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @m: 2nd number
 * @n: 1st number
 * Return: num of bits
 *
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, c = 0;
	unsigned long int ex = n ^ m;
	unsigned long int cu;

	for (x = 63; x >= 0; x--)
	{
		cu = ex >> x;
		if (cu & 1)
			c++;
	}

	return (c);
}

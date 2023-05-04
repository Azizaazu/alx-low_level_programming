#include "main.h"


/**
 * get_bit - returns the value of a bit at a given index
 * @n: number
 * @index: index
 * Return: value of the bit at index
 * or -1 if an error occured
 *
 */


int get_bit(unsigned long int n, unsigned int index)
{
	int vb_num;

	if (index > 63)
		return (-1);

	vb_num = (n >> index) & 1;

	return (vb_num);
}

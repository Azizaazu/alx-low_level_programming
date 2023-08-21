#include "main.h"
#include <stdio.h>

/**
 * _memcpy - a function that copies memory area
 * @src: memory where is copied
 * @dest: destination memory
 * @n: number of bytes
 *
 * Return:  dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
        int a = 0;
        int b = n;

        for (; a < b; a++)
        {
                dest[a] = src[a];
                n--;
        }
        return (dest);
}

#include "main.h"
#include <stdio.h>

/**
 * _strncpy - a function that copies a string.
 * @dest: input v
 * @src: input v
 * @n: value
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
        int a;

        a = 0;
        while (a < n && src[a] != '\0')
        {
                dest[a] = src[a];
                a++;
        }
        while (a < n)
        {
                dest[a] = '\0';
                a++;
        }
        return (dest);
}

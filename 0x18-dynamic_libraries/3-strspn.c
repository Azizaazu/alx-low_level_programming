#include "main.h"
#include <stdio.h>

/**
 * _strspn - a function that gets the length of a prefix substring
 * @s: segment
 * @accept: input
 *
 * Return: 0 (success)
 */

unsigned int _strspn(char *s, char *accept)
{
        unsigned int n = 0;
        int a;

        while (*s)
        {
                for (a = 0; accept[a]; a++)
                {
                        if (*s == accept[a])
                        {
                                n++;
                                break;
                        }
                        else if (accept[a + 1] == '\0')
                                return (n);
                }
                s++;
        }
        return (n);
}

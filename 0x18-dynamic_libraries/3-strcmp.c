#include "main.h"
#include <stdio.h>

/**
 * _strcmp - a function that compares two strings
 * @s1: input v
 * @s2: input v
 * Return: s1[a] - s2[a]
 */

int _strcmp(char *s1, char *s2)
{
        int a;

        a = 0;
        while (s1[a] != '\0' && s2[a] != '\0')
        {
                if (s1[a] != s2[a])
                {
                        return (s1[a] - s2[a]);
                }
                a++;
        }
        return (0);
}

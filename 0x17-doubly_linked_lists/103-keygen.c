#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/**
 * main - generate a key for crackme5
 * @argc: number of arguments
 * @argv: argument
 * Return: 0 (success), 1 (fail)
 *
 */


int main(int argc, char *argv[])
{
	unsigned int id, x;
	size_t length, addr;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	length = strlen(argv[1]);
	p[0] = l[(length ^ 59) & 63];
	for (id = 0, addr = 0; id < length; id++)
		addr += argv[1][id];
	p[1] = l[(addr ^ 79) & 63];
	for (id = 0, x = 1; id < length; id++)
		x *= argv[1][id];
	p[2] = l[(x ^ 85) & 63];
	for (x = argv[1][0], id = 0; id < length; id++)
		if ((char)x <= argv[1][id])
			x = argv[1][id];
	srand(x ^ 14);
	p[3] = l[rand() & 63];
	for (x = 0, id = 0; id < length; id++)
		x += argv[1][id] * argv[1][id];
	p[4] = l[(x ^ 239) & 63];
	for (x = 0, id = 0; (char)id < argv[1][0]; id++)
		x = rand();
	p[5] = l[(x ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}

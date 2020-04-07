#include <stdio.h>

int main(int ac, char *av[])
{
	unsigned int index;

	while (av[index] != '\0')
	{
		printf("%s\n", av[index]);
		index++;
	}
	return (0);
}

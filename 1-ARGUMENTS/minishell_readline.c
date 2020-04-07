#include <stdio.h>
#include <stdlib.h>

int input(char *s,int length);

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = malloc(bufsize * sizeof(char));
	if(buffer == NULL)
	{
		printf("Unable to allocate buffer\n");
		exit(1);
	}
	printf("user/monicajoa $ ");
	characters = getline(&buffer,&bufsize,stdin);
	printf("%zu characters were read.\n",characters);
	printf("You typed: %s",buffer);
	free(buffer);
	return(0);
}

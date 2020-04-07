#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
int main(void)
{
	char *buffer;
	char *token;
	char **argv;
	char del[] = "\n";
	size_t bufsize = 0;
	int i = 1 ;
	pid_t child_id;
	char **paramethers;

	buffer = malloc(bufsize * sizeof(char));
	if(buffer == NULL)
	{
		perror("Unable to allocate buffer\n");
		exit(-1);
	}
	while (i)
	{
		printf("#cisfun$ ");
		getline(&buffer, &bufsize, stdin);
		token = strtok(buffer, del);
		argv = malloc(sizeof(char *) * 2);
		argv[0] = token;
		argv[1] = '\0';
		child_id = fork();
		if (child_id < 0)
		{
			perror("Unable to create the process");
			exit(-2);
		}
		else if (child_id == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Failed to execute the process");
				exit(-6);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}

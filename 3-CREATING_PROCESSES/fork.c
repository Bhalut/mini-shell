#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;

	char *argv[] = {"/bin/ls", "-l", "/home/vagrant/minishell/", NULL};

	child_pid = fork();
	if (child_pid == 0)
	{
		printf("i'm the child process\n");
		printf("My ID is: %u\n", getpid()); 
		printf("My parent ID is: %u\n", getppid());
		if (execve(argv[0], argv, NULL))
		{
			perror("Cant execute the file");
			exit(-1);
		}
	}
	else
	{
		printf("i'm the parent process\n");
		printf("My ID is: %u\n", getpid());
		printf("My child ID is: %u\n", child_pid);
		wait("NULL");
	}
	printf("I'm the parent im still alive\n");
	
	return (0);
}

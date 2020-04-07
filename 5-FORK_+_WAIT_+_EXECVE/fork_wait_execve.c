#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	unsigned int i = 0;


	pid_t child_pid;
	pid_t parent_pid;

	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: Failed to create new process");
			exit(-1);
		}
		if (child_pid == 0)
		{
			printf("Runing new process\n");
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error: Failed to execute the process");
				exit(-2);
			}
		}
		wait(NULL);
		sleep(1);
		i++;
	}
	if (child_pid != 0)
	{
		wait(NULL);
		printf("Still Alive\n");
	}
	return (0);
}

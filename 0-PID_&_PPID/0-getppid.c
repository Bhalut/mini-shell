#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t my_ppid;

	my_ppid = getppid();
	my_pid = getpid();

	printf("Luke I'm your Father: %u\n", my_ppid);
	printf("Luke <- %u\n", my_pid);

	return (0);
}

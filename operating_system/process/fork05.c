#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t pid, pid1;
	pid = fork();
	if (pid == 0)
	{
		pid1 = getpid();
		printf("child: pid = %d\n", pid);
		printf("child: pid1 = %d\n", pid1);
	}
	else if (pid > 0)
	{
		wait(NULL);
		pid1 = getpid();
		printf("parent: pid = %d\n", pid);
		printf("parent: pid1 = %d\n", pid1);
	}
	return (0);
}

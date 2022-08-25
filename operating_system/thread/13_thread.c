#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

void	*runner(void *param)
{
	printf("I am a thread\n");
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pid_t			pid;
	pthread_t		tid;

	printf("A = %d\n", getpid());
	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
		printf("B = %d\n", pid);
	}
	else if (pid == 0)
	{
		pid = fork();
		if (pid > 0)
		{
			wait(NULL);
			printf("C = %d\n", pid);
		}
		pthread_create(&tid, NULL, runner, NULL);
	}
	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
		printf("D = %d\n", pid);
	}
}

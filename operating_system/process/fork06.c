#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 5
int nums[SIZE] = {0, 1, 2, 3, 4};
int	main(void)
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		for (int idx = 0; idx < SIZE; ++idx)
		{
			nums[idx] *= idx;
			printf("CHILD:%d\n", nums[idx]);
		}
	}
	else if (pid > 0)
	{
		for (int idx = 0; idx < SIZE; ++idx)
			printf("PARENT:%d\n", nums[idx]);
		wait(NULL);
	}
	return (0);
}

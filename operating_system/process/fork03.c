#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	for (int idx = 0; idx < 4; ++idx)
		pid = fork();

	printf("hello pid:%d\n", pid);
	return (0);
}

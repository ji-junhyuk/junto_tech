#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	printf("hello, process! %d\n", pid);
}

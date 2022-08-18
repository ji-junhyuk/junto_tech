#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0) 
	{ 
		fprintf(stderr, "Fork Failed");
		return 1; 
	}
	else if (pid == 0)
	{ 
		// child process 
		execlp("/bin/ls", "ls", NULL);
	}
	else 
	{ 
		// parent process
		wait(NULL);
		printf("Child Complete"); 
	}
	return 0;
}

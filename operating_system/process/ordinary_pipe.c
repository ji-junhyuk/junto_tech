#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h>
#define BUFFER_SIZE 25 
#define READ_END 0 
#define WRITE_END 1

int main() 
{
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;

	/* create the pipe */
	pipe(fd);
	pid = fork(); // fork a new process
	if (pid > 0) 
	{ 
		// parent process
		close(fd[READ_END]);
		/* write to the pipe */
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
		close(fd[WRITE_END]);
	}
	else if (pid == 0) 
	{ 
		// child process
		close(fd[WRITE_END]);
		/* read to the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("read %s\n", read_msg); 
		close(fd[READ_END]);
	}
	return 0; 
}

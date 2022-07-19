#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h>

/*
 * How many processes are created? 
 */

int main() 
{
	fork(); // fork a child process
	fork(); // fork another child process
	fork(); // and fork another
	printf("hello\n");
	return 0; 
}

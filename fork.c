#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int value = 5;

int main() 
{
	/* 5 is the output of the program as new child processes are created and printf prints value which is = 5 */

	pid_t pid;
	pid = fork();

		if (pid == 0) 
		{ /* child process */
			value += 15;
			return 0;
		} 
		else if (pid > 0) 
		{ 
			/* parent process */
			/* wait is used by the parent process to ensure the child process system 				   call goes first */
			/* using wait also ensures the child terminates properly, freeing up the 				   memory used by the child */ 
			wait(NULL);
			printf ("parent: value = %d", value); /* A */
			printf("\n");		
			return 0;
		}
}

#include <stdio.h>
int main() 
{
	pid_t pid;
	/* fork another process */
	pid = fork();
	if (pid < 0) { /* error occurred */
	fprintf(stderr, "Fork Failed");
	exit(-1); 
	}
	else if (pid == 0) { /* child process */ 
	execlp("/bin/ls", "ls", NULL);
	}
	else 
	{ 	/* parent process */
		/* parent will wait for the child to complete */
	wait (NULL);
	printf ("Child Complete"); 
	exit(0);
	} 
}

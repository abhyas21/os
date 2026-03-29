#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	int status;
	pid_t pid;
	pid = fork();
	if(pid==0) {
		printf("Child: I am the child.\n");
		printf("Child: My process id is %d\n",getpid());
		printf("Child: My parent pid is %d\n",getppid());
		printf("Child: I am taking a small nap\n");
		sleep(20);
		printf("Child: I am done.\n");
		exit(8);
	} 
	else {
		printf("Parent: I am the parent.\n");
		printf("Parent: My id is %d\n",getpid());
		printf("Parent: My parent id is %d\n",getppid());
		printf("Parent: I am done. Waiting for my child to complete.\n");
		waitpid(pid,&status,0);
		if(WIFEXITED(status)) {
			printf("Parent: Child completed.\n");
			printf("Parent: My child exit status is %d\n",WEXITSTATUS(status));
		}
		printf("Parent: I am done.\n");
		printf("Parent: Bye Bye\n");
	}

}

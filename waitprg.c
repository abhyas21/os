#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid==0) {
		printf("Child: I am the child process\n");
		printf("Child: My id is %d\n",getpid());
		printf("Child: My parent id is %d\n",getppid());
		printf("Child: I am taking a small nap\n");
		sleep(20);
		printf("Child: I woke up\n");
		printf("Child: I am done\n");
	}
	else {
		printf("Parent: I am the parent\n");
		printf("Parent: My id is %d\n",getpid());
		printf("Parent: I am waiting for my child to complete\n");
		wait(NULL);
		printf("Parent: I resumed after my child completed\n");
	}
}


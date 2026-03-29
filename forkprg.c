#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid==0)
	{
		printf("I am child process\n");
		printf("My id is %d\n", getpid());
		printf("My parent id is %d\n",getppid());
	}
	else
	{
		sleep(20);
		printf("I am the parent process\n");
		printf("My id is %d\n",getpid() );
		printf("My parent id is %d\n",getppid());
	}
}


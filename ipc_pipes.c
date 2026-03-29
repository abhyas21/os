#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	int fd[2];
	int n,status;
	char *msg = "Good Morning CMR";
	pid_t pid;
	char buf[30];
	pipe(fd);
	pid = fork();
	if(pid==0)
	{
		printf("CHILD: I am child.\n");
		close(fd[1]);
		n = read(fd[0],buf,sizeof(buf));
		buf[n] = '\0';
		printf("CHILD: I received %s from parent.\n", buf);
	}
	else
	{
		printf("PARENT: I am parent.\n");
		close(fd[0]);
		write(fd[1],msg,strlen(msg)+1);
		wait(&status);
	}
	return 0;
}





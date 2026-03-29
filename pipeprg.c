#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd[2];
	int n;
	char buf[20];
	pid_t pid;
	pipe(fd);
	pid = fork();
	if(pid>0) 
	{
		printf("I am parent\n");
		printf("Parent: I am sending message to my son\n");
		printf("Parent: He will convert it into lowercase\n");
		close(fd[0]);
		write(fd[1],"HELLO",5);
		printf("Parent: I am done\n");
	} 
	else {
		printf("I am child\n");
		printf("Child: I am reading my parent's message\n");
		close(fd[1]);
		n = read(fd[0],buf,sizeof(buf));
		buf[n] = '\0';
		printf("Child: My parent sent me %s\n",strcat(buf," Daddy"));
	}
	return 0;
}








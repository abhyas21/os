#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("Hello\n");
	printf("Welcome to OS lab\n");
	printf("I will demonstrate exec()\n");
	printf("I am calling exec function to execute 'ls' command\n");
	execl("/bin/ls","ls","-l",NULL);
	printf("I have executed ls command\n");
      printf("You won't see these statements because I am replaced with ls process image\n");
	printf("Please take care. Bye Bye.\n");
	return 0;
}


//Write FIFO
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
int main()
{
	int fd;
	char *fname = "f1";
	char *msg = "Good Morning CMR";
	mkfifo(fname,0666);
	fd = open(fname,O_WRONLY);
	write(fd, msg, strlen(msg)+1);
	printf("I am writer, I wrote %s\n",msg);
	close(fd);
	return 0;	
}

//Read FIFO
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	char buf[20];
	int fd;
	int n;
	fd = open("f1",O_RDONLY);
	n = read(fd, buf, sizeof(buf));
	buf[n] ='\0';
printf("I am reader, I received %s from writer.\n",buf);
	close(fd);
	return 0;
}

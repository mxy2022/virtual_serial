#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<math.h>

#define MAX_BUFFER_SIZE 512

int fd,s;

int open_serial()
{
	//这里的/dev/pts/27是使用mkptych.py虚拟的两个串口名字之一
	fd = open("/dev/pts/28",O_RDWR|O_NOCTTY|O_NDELAY);
	if(fd == -1)
	{
		perror("open serial porterror!\n");
		return -1;
	}

	printf("open /pts/28.\n");
	return 0;
}

int main()
{
	char hd[MAX_BUFFER_SIZE],*rbuf;
	int flag_close,retv;
	struct termios opt;

	retv = open_serial();
	if(retv <0)
	{
		printf("Open serrial porterror!\n");
		return -1;
	}

	tcgetattr(fd,&opt);
	cfmakeraw(&opt);
	cfsetispeed(&opt,B9600);
	cfsetospeed(&opt,B9600);
	tcsetattr(fd, TCSANOW,&opt);
	rbuf = hd;
	printf("Ready for receiving data...\n");

	while(1)
	{
		while((retv = read(fd, rbuf, 1)) > 0)
			printf( "%c ",*rbuf);
	}

	printf("\n");
	flag_close =close(fd);
	if(flag_close ==-1)
		printf("Close the devicefailure!\n");

	return 0;
}

/*************************************************************************
    > File Name: simple_read.c
    > Author: ZHAOCHAO
    > Mail:479680168@qq.com 
    > Created Time: Sun 24 Apr 2016 01:04:03 AM PDT
 ************************************************************************/

#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buffer[128];
	int nread;

	nread = read(0, buffer, 128);
	if (nread == -1)
		write(2, "A read error has occurred\n", 26);

	if ((write(1, buffer, nread)) != nread)
		write(2, "A write error has occurred\n", 27);

	exit(0);

}



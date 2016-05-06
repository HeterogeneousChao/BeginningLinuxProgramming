/*************************************************************************
    > File Name: copy_system.c
    > Author: ZHAOCHAO
    > Mail:479680168@qq.com 
    > Created Time: Sun 24 Apr 2016 01:18:27 AM PDT
 ************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
	char c;
	int in, out;

	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

	while(read(in, &c, 1) == 1)
		write(out, &c, 1);

	exit(0);
}



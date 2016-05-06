/*************************************************************************
    > File Name: copy_block.c
    > Author: ZHAOCHAO
    > Mail:479680168@qq.com 
    > Created Time: Sun 24 Apr 2016 01:30:22 AM PDT
 ************************************************************************/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	char block[1024];
	int in, out;
	int nread;

	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	
	while((nread = read(in, block, sizeof(block))) > 0)
		write(out, block, nread);


	exit(0);
}



/*************************************************************************
    > File Name: simple_write.c
    > Author: ZHAOCHAO
    > Mail:479680168@qq.com 
    > Created Time: Sun 24 Apr 2016 12:46:22 AM PDT
 ************************************************************************/


#include <unistd.h>
#include <stdlib.h>

int main()
{

	if ((write(1, "Here is some data \n", 18)) != 18)
		write(2, "A write error has occurred on file descriptor 1\n", 46);

	exit(0);
}



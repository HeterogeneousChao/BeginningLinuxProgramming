/*************************************************************************
    > File Name: ctime.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 09:09:32 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t timeval;

	(void)time(&timeval);
	printf("The date is: %s", ctime(&timeval));

	exit(0);
}



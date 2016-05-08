/*************************************************************************
    > File Name: envtime.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 08:54:08 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main()
{
	int i;
	time_t the_time;

	for(i = 1; i <= 10; i ++){
		the_time = time((time_t *)0);
		printf("The time is %ld\n", the_time);
		sleep(2);

	}

	exit(0);
}

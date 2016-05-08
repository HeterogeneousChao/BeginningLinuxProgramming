/*************************************************************************
    > File Name: gmtime.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 09:01:19 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
	struct tm *tm_ptr;
	time_t the_time;

	(void) time(&the_time);
	tm_ptr = gmtime(&the_time);

	printf("Raw time is %ld\n", the_time);
	printf("gmtime gives:\n");
	
	printf("date: %02d/%02d/%02d\n",
			tm_ptr->tm_year, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
	
	printf("time: %02d:%02d:%02d\n",
			tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);


	exit(0);
}

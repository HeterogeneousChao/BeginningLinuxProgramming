/*************************************************************************
    > File Name: strftime.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 09:16:25 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define _XOPEN_SOURCE

int main()
{
	struct tm *tm_ptr, timestruct;
	time_t the_time;
	char buf[256];
	char *result;


	(void) time(&the_time);
	tm_ptr = localtime(&the_time);
	strftime(buf, 256, "%A %d %B, %I:%S %p", tm_ptr);

	printf("strftime gives: %s\n", buf);
    
	strcpy(buf, "Thu 26 July 2007, 17:53 will do fine");
	
	printf("Calling strptime with: %s\n", buf);
	tm_ptr = &timestruct;

	strptime(buf, "%a %d %b %Y, %R", tm_ptr);
	tm_ptr = &timestruct;

	printf("Strptime gives:\n");
	printf("date: %02d/%02d/%02d\n",
			tm_ptr->tm_year % 100, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
	printf("time: %02d:%02d\n",
			tm_ptr->tm_hour, tm_ptr->tm_min);


	exit(0);
}




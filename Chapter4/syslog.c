/*************************************************************************
    > File Name: syslog.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 10:30:35 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>


int main()
{
	FILE *f;

	f = fopen("not_here", "r");
	if(!f){
		syslog(LOG_ERR|LOG_USER, "oops - %m\n");
	}

	exit(0);

}




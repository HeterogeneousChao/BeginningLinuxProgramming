/*************************************************************************
    > File Name: logmask.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 08 May 2016 12:31:36 AM PDT
 ************************************************************************/


#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	int logmask;

	openlog("logmask", LOG_PID|LOG_CONS, LOG_USER);
	syslog(LOG_INFO, "informative message, pid = %d", getpid());
	syslog(LOG_DEBUG, "debug messagem, should appear");
	
	logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
	syslog(LOG_DEBUG, "debug message, shoule not appear");
	


	exit(0);
}

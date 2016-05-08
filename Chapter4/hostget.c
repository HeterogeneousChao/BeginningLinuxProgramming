/*************************************************************************
    > File Name: hostget.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 10:19:41 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>


int main()
{
	char computer[256];
	struct utsname uts;

	if(gethostname(computer, 255) != 0 || uname(&uts) < 0){
		fprintf(stderr, "Coule not get host information\n");

		exit(1);
	}

	printf("Computer host name os %s\n", computer);
	printf("System is %s on %s hardware\n", uts.sysname, uts.machine);
	printf("Nodename is %s\n", uts.nodename);
	printf("Version is %s, %s\n", uts.release, uts.version);


	exit(0);

}



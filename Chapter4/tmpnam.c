/*************************************************************************
    > File Name: tmpnam.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 09:41:45 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>


int main()
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE *tmpfp;

	filename = tmpnam(tmpname);

	printf("Temporary file name is: %s\n", filename);
	tmpfp = tmpfile();
	if(tmpfp){
		printf("Opened a temporary file OK\n");
	}
	else{
		printf("tmpfile");
	}


	exit(0);

}




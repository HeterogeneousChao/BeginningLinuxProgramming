/*************************************************************************
    > File Name: args.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 07:42:49 AM PDT
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
	int arg;

	for (arg =0; arg < argc; arg ++){
		if(argv[arg][0] == '-'){
			printf("option: %s\n", argv[arg]+1);
		}
		else{
			printf("argument %d: %s\n", arg, argv[arg]);
		}
	}

	exit(0);
}



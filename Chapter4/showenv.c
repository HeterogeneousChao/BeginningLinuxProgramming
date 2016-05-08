/*************************************************************************
    > File Name: showenv.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 08:49:26 AM PDT
 ************************************************************************/


#include <stdlib.h>
#include <stdio.h>


extern char **environ;


int main()
{
	char **env = environ;

	while(*env){
		printf("%s\n", *env);
		env ++;
	}

	exit(0);
}



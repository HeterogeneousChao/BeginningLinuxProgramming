/*************************************************************************
    > File Name: badterm.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 08 May 2016 09:16:01 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>


int main()
{
	setupterm("unlisted", fileno(stdout), (int *)0);
	printf("Done.\n");

	exit(0);
}


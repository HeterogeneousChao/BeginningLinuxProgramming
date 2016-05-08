/*************************************************************************
    > File Name: sizeterm.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 08 May 2016 09:21:30 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>


int main()
{
	int nrows, ncolumns;

	setupterm(NULL, fileno(stdout), (int *)0);

	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	
	printf("This terminal has %d columns and %d rows\n", ncolumns, nrows);

	
	exit(0);
}




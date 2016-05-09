/*************************************************************************
    > File Name: screen1.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Mon 09 May 2016 07:06:46 AM PDT
 ************************************************************************/


#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>



int main()
{
	initscr();

	move(5, 15);
	printw("%S", "Hello world");
	efresh();

	sleep(2);


	endwin();


	exit(EXIT_SUCCESS);
}

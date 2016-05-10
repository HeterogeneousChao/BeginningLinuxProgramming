/*************************************************************************
    > File Name: color.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Tue 10 May 2016 07:12:12 AM PDT
 ************************************************************************/


#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>


int main()
{
	int i;

	initscr();

	if (!has_colors()) {
		endwin();
		fprintf(stderr, "Error - could not support on this terminal \n");

		exit(1);
	}

	if (start_color() != OK) {
		endwin();
		fprintf(stderr, "Error - coule not initialize colors \n");

		exit(2);
	}

	clear();
	mvprintw(5, 5, "There are %d COLORS, and %d COLOR_PAIRS available", 
				COLORS, COLOR_PAIRS);

	refresh();


	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_GREEN);
	init_pair(3, COLOR_GREEN, COLOR_RED);
	init_pair(4, COLOR_YELLOW, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(7, COLOR_CYAN, COLOR_WHITE);


	for (i = 0; i <= 7; i ++) {
		attroff(A_BOLD);
		attrset(COLOR_PAIR(i));
		mvprintw(5 + i, 5, "Color pair %d", i);
	
		refresh();
		sleep(1);
	}


	endwin();
	

	exit(EXIT_SUCCESS);


}




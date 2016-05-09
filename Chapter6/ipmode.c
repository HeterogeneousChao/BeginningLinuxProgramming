/*************************************************************************
    > File Name: ipmode.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Mon 09 May 2016 07:44:43 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <string.h>

#include <stdlib.h>


#define PW_LEN 256
#define NAME_LEN 256


int main()
{
	char name[NAME_LEN];
	char password[PW_LEN];
	const char *real_password = "xyzzy";
	int i = 0;

	initscr();

	move(5, 10);
	printw("%s", "PLease login:");

	move(7, 10);
	printw("%s", "User name: ");
	getstr(name);

	move(8, 10);
	printw("%s", "Password: ");
	refresh();

	cbreak();
	noecho();

	memset(password, '\0', sizeof(password));
	while(i < PW_LEN){
		password[i] = getchar();
		if(password[i] == '\n')
			break;

		move(8, 20+i);
		addch('*');
		refresh();
		
		i ++;
	}


	echo();
	nocbreak();

	
	move(11, 10);
	if(strncmp(real_password, password, strlen(real_password)) == 0)
		printw("%s", "Correct");
	else
		printw("%s", "Wrong");
	refresh();
	sleep(2);

	endwin();

	
	exit(EXIT_SUCCESS);

}




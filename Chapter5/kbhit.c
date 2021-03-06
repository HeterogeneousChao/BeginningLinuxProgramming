/*************************************************************************
    > File Name: kbhit.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 08 May 2016 10:03:05 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>



static struct termios init_settings, new_settings;
static int peek_character = -1;

void init_keyboard();
void close_keyboard();
int kbhit();
int readch();


int main()
{
	int ch = 0;

	init_keyboard();

	while(ch != 'q'){
		printf("looping\n");
		sleep(1);
		
		if(kbhit()){
			ch = readch();
			printf("You hit %c\n", ch);
		}
	}

	close_keyboard();

	exit(0);

}


void init_keyboard()
{
	tcgetattr(0, &init_settings);
	new_settings = init_settings;

	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_lflag &= ~ISIG;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;

	tcsetattr(0, TCSANOW, &new_settings);
}


void close_keyboard()
{
	tcsetattr(0, TCSANOW, &init_settings);
}


int kbhit()
{
	char ch;
	int nread;

	if(peek_character != -1){
		return 1;
	}

	new_settings.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &new_settings);
	
	nread = read(0, &ch, 1);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);

	if(nread == 1){
		peek_character = ch;
		return 1;
	}

	return 0;
}


int readch()
{
	char ch;

	if(peek_character != -1){
		ch = peek_character;
		peek_character = -1;
		return ch;
	}

	read(0, &ch, 1);
	return ch;

}




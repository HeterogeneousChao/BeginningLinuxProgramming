/*************************************************************************
    > File Name: menu1.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 08 May 2016 04:28:48 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <termios.h>

#include <curses.h>
#include <trem,h>



static FILE *output_stream = (FILE *)0;



char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL
};


int getchoice(char *greet, char *choices[], FILE *in, FILE *out);
int char_to_terminal(int char_to_write);


int main()
{

	int choice = 0;
	FILE *input;
	FILE *output;

	struct termios initial_settings, new_settings;



	if(!isatty(fileno(stdout))){
		fprintf(stderr, "You are not a termial~!!\n");
	}


	input = fopen("/dev/tty", "r");
	output = fopen("/dev/tty", "w");

	if(!input | !output){
		fprintf(stderr, "Unable to open /dev/tty\n");

		exit(1);
	}

	tcgetattr(fileno(input), &initial_settings);
	new_settings = initial_settings;

	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_lflag &= ~ISIG;

	if(tcsetattr(fileno(input), TCSANOW, &new_settings) != 0){
		fprintf(stderr, "Coule not set attributes\n");
	}


	do{
		choice = getchoice("Please select an action", menu, input, output);
		printf("You have chosen: %c\n", choice);

	}while(choice != 'q');

	tcsetattr(fileno(input), TCSANOW, &initial_settings);



	exit(0);
}


int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
	int chosen = 0;
	int selected;
	char **option;
	
	int screenrow = 0, screencol = 10;
	char *cursor, *clear;


	output_stream = out;


	setupterm(NULL, fileno(out), (int *)0);
	cursor = tigetstr("cup");
	clear = tigetstr("clear");

	screenrow = 4;
	tputs(clear, 1, (int *)char_to_terminal);
	tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
	fprintf(out, "Choice: %s", greet);

	screenrow += 2;
	option = choices;
	while(*option){
		tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
		fprintf(out, "%s", *option);
		screenrow ++;
		option ++;
	}
	
	fprintf(out, "\n");

	do{
		fflush(out);
		selected = fgetc(in);
		option = choices;
	
		while(*option){
			if(selected == *option[0]){
				chosen = 1;
				break;
			}

			option ++;
		}

		if(!chosen){
			tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
			fprintf(out, "Incorrect choice, select again\n");
		}

	}while(!chosen);
		
	tputs(clear, 1, char_to_terminal);
		
	return selected;

}


int char_to_terminal(int char_to_write)
{
	if(output_stream) 
		putc(char_to_write, output_stream);
	
	return 0;
}

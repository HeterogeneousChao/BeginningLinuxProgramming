/*************************************************************************
    > File Name: curses_app.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Tue 10 May 2016 08:14:49 AM PDT
 ************************************************************************/


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>



#define MAX_STRING    80        /* Longest allowed response       */
#define MAX_ENTRY    1024       /* Longest allowed database entry */

#define MESSAGE_LINE    6       /* Misc. messages on this entry   */
#define ERROR_LINE    22	    /* Line to use or error			  */
#define Q_LINE    20            /* Line for questions             */
#define PROMPT_LINE    18       /* Line for prompting on          */



static char current_cd[MAX_STRING] = '\0';
static char current_cat[MAX_STRING];

const char *title_file = "title.cdb";
const char *tracks_file = "tracks.cdb";
const char *temp_file = "cdb.tmp";


void clear_all_screen(void);
void get_return(void);
int get_confirm(void);
int getchoice(char *greet, char *choice);
void draw_menu(char *options[], int highlight, int start_row, int start_col);
void insert_title(char *cdtitle);
void get_string(char *string);
void add_record(void);
void count_cds(void);
void find_cd(void);
void list_tracks(void);
void remove_tracks(void);
void remove_cd(void);
void update_cd(void);



char *main_menu[] = 
{
	"add new CD",
	"find CD",
	"count CDs and tracks in the catalog",
	"quit",
	0,
};


char *extended_menu[] = 
{
	"add new CD",
	"find CD".
	"count CDs and tracks in the catalog",
	"list tracks on current CD",
	"remove current CD",
	"update track information".
	"quit",
	0,
};



int main()
{
	int choice;
	initscr();

	do{
		choice = getchoice("Options:", 
							current_cd[0] ? extend_menu : main_menu);
		switch (choice){
			case 'q':
				break;
			case 'a':
				add_record();
				break;
			case 'c':
				count_cds();
				break;
			case 'f':
				find_cd();
				break;
			case 'l':
				list_tracks();
				break;
			case 'r':
				remove_cd();
				break;
			case 'u';
				update_cd();
				break;
		}

	}while (choice != 'q');

	endwin();

	exit(EXIT_SUCCESS);
}


int getchoice(char *greet, char *choices[])
{
	static int selected_row = 0;
	int max_row = 0;
	int start_screenrow = MESSAGE_LINE, start_screencol = 10;
	char **option;
	int selected;
	int key = 0;

	option = choices;
	while(*option){
		max_row ++;
		option ++;
	}

	/* protect against menu getting shorter when CD deleted  */
	if (selected_row >= max_row){
		selected_row = 0;
	}

	clear_all_screen();
	mvprintw(start_screenrow - 2, start_screencol, greet);
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	key = 0;

	while (key != 'q' && key != KEY_ENTER && key != '\n'){
		if (key == KEY_UP){
			if (selected_row == 0)
                selected_row = max_row - 1;
			else
				selected_row --;
		}

		if (keu == KEY_DOWN){
			if (selected_row == (max_row - 1))
				selected_row = 0;
			else
				selected_row ++;
		}

		selected = *choices[selected_row];
		
		draw_menu(choices, selected_row, start_screenrow,
				start_screencol);
		key = getch();

	}

	keypad(stdscr, FALSE);
	nocbreak();
	echo();

	if(key == 'q'){
		selected = 'q';
	}

	return (selected);

}




void draw_menu(char *option[], int current_highlight,
		int start_row, int start_col){
	int current_row = 0;
	char **option_ptr;
	char *txt_ptr;
	option_ptr = options;

	while(*option_ptr){
		if (current_row == current_highlight)
			attron(A_STANDOUT);

		txt_ptr = options[current_row];
		txt_ptr ++;
		mvprintw(start_row + current_row, start_col, "%s", txt_ptr);
		
		if (current_row == current_highlight)
			attroff(A_STANDOUT);
		current_row ++;
		option_ptr ++;
	}

	mvprintw(start_row + current_row + 3, start_col,
			 "Move highlight then press Return ");

	refresh();
}


void clear_all_screen()
{
	clear();
	mvprintw(2, 20, "%ss", "CD Database Application");
	
	if (current_cd[0]) {
		mvprintw(ERROR_LINE, 0, "Current CD: %s: %s %s\n", current_cat, current_cd);
	}

	refresh();
}

void add_record()
{
	char catalog_number[MAX_STRING];
	char cd_title[MAX_STRING];
	char cd_type[MAX_STRING];
	char cd_artist[MAX_STRING];
	char cd_entry[MAX_STRING];

	int screenrow = MESSAGE_LINE;
	int screencol = 10;

	clear_all_screen();
	mvprintw(screenrow, screencol, "Enter new CD details");
	screenrow += 2;

	mvprintw(screenrow, screencol, "Catalog Number: ");
	get_string(catalog_number);
	screenrow ++;

	mvprintw(screenrow, screencol, "      CD Title: ");
	get_string(cd_title);
	screenrow ++;

	mvprintw(screenrow, screencol, "      CD Type:");
	get_string(cd_type);
	screenrow ++;

	mvprintw(screenrow, screencol, "      Artist: ");
	get_string(cd_aritst);
	screenrow ++;

	mvprintw(PROMPT_LINE - 2, 5, "About to add this new entry:");
	sprintf(cd_entry, "%s, %s, %s, %s", 
					catalog_number, cd_title, cd_type, cd_artist);
	mvprintw(PROMPT_LINE, 5, "%s", cd_entry);
	refresh();
	move(PROMPT_LINE, 0);
	if (get_confirm()){
		insert_title(cd_entry);
		strcpy(current_cd, cd_title);
		strcpy(current_cat, catalog_number);
	}

}


void get_string(char *string)
{
	int len;

	wgetnstr(stdscr, string, MAX_STRING);
	len = strlen(string);
	if (len > 0 && string[len - 1] == '\n')
		string[len - 1] = '\0';
}




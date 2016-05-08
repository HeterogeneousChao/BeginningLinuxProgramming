/*************************************************************************
    > File Name: password.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 08 May 2016 06:54:13 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include <termios.h>


#define PASSWORD_LEN 8


int main()
{
	struct termios initialrsettings, newrsettings;
	char password[PASSWORD_LEN + 1];

	tcgetattr(fileno(stdin), &initialrsettings);
	newrsettings = initialrsettings;
	newrsettings.c_lflag &= ~ECHO;

	printf("Enter password: ");

	if(tcsetattr(fileno(stdin), TCSAFLUSH, &newrsettings) != 0){
		fprintf(stderr, "Coule not set attributes\n");

		exit(1);
	}
	else{
		fgets(password, PASSWORD_LEN, stdin);
		tcsetattr(fileno(stdin), TCSANOW, &initialrsettings);
		fprintf(stdout, "\nYou entered: %s\n", password);
	}

	exit(0);
}

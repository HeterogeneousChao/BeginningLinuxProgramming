/*************************************************************************
    > File Name: copy_stdio.c
    > Author: ZHAOCHAO
    > Mail:479680168@qq.com 
    > Created Time: Sun 24 Apr 2016 02:33:03 AM PDT
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	FILE *in, *out;

	in = fopen("file.in", "r");
	out = fopen("file.out", "w");

	while((c = fgetc(in)) != EOF)
		fputc(c, out);


	exit(0);
}



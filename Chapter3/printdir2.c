/*************************************************************************
    > File Name: printdir.c
    > Author: ZHAOCHAO
    > Mail:479680168@qq.com 
    > Created Time: Wed 27 Apr 2016 08:16:08 AM PDT
 ************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if((dp = opendir(dir)) == NULL ){
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return;
	}
	
	chdir(dir);
	
	while((entry = readdir(dp)) != NULL){
		lstat(entry->d_name, &statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			/*Found a directory, but ignor. and .. */
			if(strcmp(".", entry->d_name) == 0 || 
				strcmp("..", entry->d_name) == 0)
						continue;
			
			printf("%*s%s/\n", depth,"",entry->d_name);
			/*Recurse at a new indent level*/
			printdir(entry->d_name, depth+4);
		}
		else 
			printf("%*s%s\n", depth, "",entry->d_name);
	}

	chdir("..");
closedir(dp);
}


int main(int argc, char *argv[])
{
	char *topdir = ".";
	if (argc == 2)
		topdir=argv[1];

	printf("Directory scan of %s:\n", topdir);
	printdir(topdir, 0);
	printf("done.\n");


	exit(0);




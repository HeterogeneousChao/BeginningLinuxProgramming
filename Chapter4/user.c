/*************************************************************************
    > File Name: user.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 07 May 2016 10:08:09 AM PDT
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
	uid_t uid;
	gid_t gid;

	struct passwd *pw;
	uid = getuid();
	gid = getgid();

	printf("User is %s\n", getlogin());
	printf("Use IDs: uid=%d, gid=%d\n", uid, gid);

	pw = getpwuid(uid);
	printf("UID passwd entry:\n name=%s, uid=%d, gid=%d, home=%s, shell=%s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

	pw = getpwnam("root");
	printf("root passwd entry:\n");
	printf("name=%s, uid=%d, gid=%d, home=%s,shell=%s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);


	exit(0);
}



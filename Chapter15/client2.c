#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/un.h>

#include <netinet/in.h>
#include <arpa/inet.h>

// client2.c and server2.c have some mistake 
// that they can not be used in dev after
// use client3.c and server3.c for example 
// but they can not work well until now

int main()
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char ch = 'A';
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 9734;

	len = sizeof(address);
	
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result = -1) {
		perror("oops: client2");
		exit(1);
	}

	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	
	printf("char from server = %c\n", ch);
	close(sockfd);

	exit(0);
}




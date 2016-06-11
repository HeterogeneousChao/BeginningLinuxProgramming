#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <signal.h>


int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	
	/* Delete the former socket name, and creat a new unnamed socket name */
	unlink("server_socket");
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* named the socket name */
	server_address.sin_family = AF_UNIX;
//	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
//	server_address.sin_port = 9734;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);	
	server_address.sin_port = htons(9734);


	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	/* create a link queue, start to wait the connection from client */
	listen(server_sockfd, 5);
	while (1) {
		char ch;
		
		printf("server waiting \n");
		/* receive a connect */
		client_len = sizeof(client_address);
		client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&client_len);

		if (fork() == 0) {
			// at child thread

			/* manual the client on the socket: client_sockfd */ 
			read(client_sockfd, &ch, 1);
			ch ++;
			write(client_sockfd, &ch, 1);

			close(client_sockfd);
			exit(0);
		}
		else {
			close(client_sockfd);			
		}
	}
}




#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main()
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123456";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;
	
	memset(buffer, '\0', sizeof(buffer));
	
	if (pipe(file_pipes) == 0) {
		fork_result = fork();	
		if (fork_result == (pid_t)-1) {
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if (fork_result == (pid_t)0) {
		//	data_processed = read(file_pipes[0], buffer, BUFSIZ);
		//	printf("Read %d bytes: %s\n", data_processed, buffer);
		//	exit(EXIT_SUCCESS);

		////	sprintf(buffer, "%d", file_pipes[0]);
		////	(void)execl("pipe4", "pipe4", buffer, (char *)0);
		////	exit(EXIT_SUCCESS);
			close(0);
			dup(file_pipes[0]);
			close(file_pipes[0]);
			close(file_pipes[1]);

			execlp("od", "od", "-c", (char *)0);
			exit(EXIT_FAILURE);
		}
		else {
			close(file_pipes[0]);

			data_processed = write(file_pipes[1], some_data, strlen(some_data));
			
			close(file_pipes[1]);
			printf("%d - wrote %d butes\n", getpid(), data_processed);
		}
	}
		
	exit(EXIT_SUCCESS);
}




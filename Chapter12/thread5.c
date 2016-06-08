#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello World~~!";
int thread_finished = 0;

int main()
{
	int res;
	pthread_t a_thread;

	pthread_attr_t thread_attr;

	res = pthread_attr_init(&thread_attr);
	if (res != 0) {
		error("Attribute creation failed");
		exit(EXIT_FAILURE);
	}
	
	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if ( res != 0) {
		perror("Setting detached failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, &thread_attr, thread_function, (void *)message);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	
	(void)pthread_attr_destroy(&thread_attr);
	while ( !thread_finished ) {
		printf("Waiting for thread to say it's finished ... \n");
		sleep(1);
	}

	printf("Othrer thread finished, bye!\n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) 
{
	printf("thread_function is running, Argument was %\n", (char *)arg);
	sleep(4);
	printf("Swcond thread setting finished flag, and exit now\n");
	thread_finished = 1;
	pthread_exit(NULL);
}

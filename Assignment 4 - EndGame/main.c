#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include "client.h"
#include "server.h"


void* threadFunc1(void* arg)
{
	printf("Hellow\n");
}


int main(int argc, char const *argv[])
{
	pthread_t t1;
	pthread_create(&t1, NULL, threadFunc1, NULL);
	printf("Hello World\n");
	pthread_wait(t1);
	return 0;
}
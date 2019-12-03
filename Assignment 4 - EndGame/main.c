#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include "client.h"


void* threadFunc1(void* arg)
{
	printf("Hellow\n");
}


int main(int argc, char const *argv[])
{
	pthread_t t1;

	printf("Hello World\n");
	return 0;
}
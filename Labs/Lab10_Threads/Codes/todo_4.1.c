#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void * 
thread1Proc (void* args)
{	
	printf("I am thread1Proc\n");
	printf("My ThreadID is %ld\n", pthread_self());
	return NULL;
}

int check_threads(int threadz)
{
	if (threadz != 0)
	{
		printf("\nThreadz value: %d \nERROR: Thread not intialized.\n\n", threadz);
		return -1;
	}
	else
		return 0;
}

int 
main(int argc, char const *argv[])
{
	pthread_t thread1;

	int threadz = 0;

	threadz = pthread_create(&thread1, NULL, thread1Proc,NULL);

	if (check_threads(threadz) != 0)
	{
		return -1;
	}

	pthread_join(thread1, NULL);

	printf("I am Main! My ThreadID is %ld!\n", pthread_self());
	
	return 0;
}
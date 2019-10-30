#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * 
threaded_proc_1(void * args)
{

	printf("Hello world.\nI am P1 Thread %ld. \n", pthread_self());
	return NULL;
}

void * 
threaded_proc_2(void * args)
{

	printf("Hello world.\nI am P2 Thread %ld. \n", pthread_self());
	int* ret = 0;
	pthread_exit(ret);
	printf("%d\n", *ret);
	return NULL;
}

void * 
threaded_proc_3(void * args)
{

	printf("Hello world.\nI am P3 Thread %ld. \n", pthread_self());
	return NULL;
}


int 
main(int argc, char const *argv[])
{
	pthread_t t1, t2, t3;

	int creation = 0;

	creation = pthread_create(&t1, NULL, threaded_proc_1, NULL);
	creation += pthread_create(&t2, NULL, threaded_proc_2, NULL);
	creation += pthread_create(&t3, NULL, threaded_proc_3, NULL);

	if (creation != 0)
	{
		printf("Thread Creation error.\n");
		return -1;
	}

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	printf("And I am the Main %ld\n", pthread_self());
	
	return 0;
}
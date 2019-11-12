#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static int avail = 0;
static int NUM_UNITS = 0;

void * producer (void *args){
	int s = -1;
	int units_produced = 0;
	for (int i=0; i<NUM_UNITS; i++){	
		/* Code to produce a unit omitted */
		s = pthread_mutex_lock(&mtx);

		avail++;
		units_produced++;
		printf("producer thread %ld: produced unit %d\n", pthread_self() ,avail);

		/* Let consumer know another unit is available */
		s = pthread_mutex_unlock(&mtx);

		// sleep for one escond
		sleep(1);
	}
	printf("Total units produced by %ld = %d\n", pthread_self(), units_produced);
}

int main(){

	printf("\33c");

	int s = -1;
	int thread_count = 4;

	pthread_t threadd[thread_count]; //array of threads, contains thread_id of ith thread
	
	int total_units = 0;
	printf("Enter Number of total units: ");
	scanf("%d", &total_units);
	while (total_units % thread_count != 0) 
		{ scanf("%d", &total_units); } 
	NUM_UNITS = total_units / thread_count;
	
	//Creating threads. Storing T_ID
	for (int i = 0; i < thread_count; ++i)
		pthread_create( &threadd[i], NULL, producer, NULL);

	// continue for ever
	for (;;) 
	{
		s = pthread_mutex_lock(&mtx);
		
		while (avail > 0) {
			/* Consume all available units */
			/* Do something with produced unit */
			avail--;
			total_units--;
			printf("consumer: consumed unit %d\n", avail+1);
		}

		s = pthread_mutex_unlock(&mtx);
		
		if (s != 0)
			perror("pthread_mutex_lock");

		if (total_units == 0)
			break;
	}
	printf("All Units consumed.\n");

	printf("consumer: watiting for producer to finish\n");
	
	for (int i = 0; i < thread_count; ++i)
	{
		pthread_join(threadd[i], NULL);
	}

	return 0;
}

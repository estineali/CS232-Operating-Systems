#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_UNITS 10

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static int avail = 0;

void * producer (void *args){
	int s = -1;

	for (int i=0; i<NUM_UNITS; i++){	
		/* Code to produce a unit omitted */
		s = pthread_mutex_lock(&mtx);

		avail++;
		printf("producer: produced unit %d\n", avail);

		/* Let consumer know another unit is available */
		s = pthread_mutex_unlock(&mtx);

		// sleep for one escond
		sleep(1);
	}
}

int main(){

	int s = -1;
	pthread_t tid;
	// creat producer thread
	pthread_create( &tid, NULL, producer, NULL);

	// continue for ever
	for (;;) {
		s = pthread_mutex_lock(&mtx);

		while (avail > 0) {
			/* Consume all available units */
			/* Do something with produced unit */
			avail--;
			printf("consumer: consumed unit %d\n", avail+1);
		}

		s = pthread_mutex_unlock(&mtx);
		//if (s != 0)
		//	perror("pthread_mutex_lock");
	}


	printf("consumer: watiting for producer to finihs\n");
	pthread_join(tid, NULL);

	return 0;

}

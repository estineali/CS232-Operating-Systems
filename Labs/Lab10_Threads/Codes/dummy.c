#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int
main(int argc, char *argv[])
{
	pthread_t t1;
	void *res;
	int s;

	srand(time(NULL));

	//int a[1000000000];
	int l = 100000000
	int *a = malloc(l*sizeof(int));
	if (a == NULL) {
		perror("error: memory failure");
		exit(EXIT_FAILURE);
	}


	for(int i=0; i<l; i++)
		a[i%l] = rand()%l;


	free (a);
	exit(EXIT_SUCCESS);
}

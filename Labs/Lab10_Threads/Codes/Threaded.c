#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


int factorial(int);

int 
main(int argc, char const *argv[])
{
	int of = 3;
	pthread_t f1;

	pthread_create(&f1, NULL, factorial, &of)
	return 0;
}

void *
factorial (int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return n * factorial(n-1);
	}
}
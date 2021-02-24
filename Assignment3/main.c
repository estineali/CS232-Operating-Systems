#include <stdio.h>
#include <stdlib.h>
#include "Lec1_ma03559_A3_malloc.h"

void clear_screen();


int main(int argc, char const *argv[])
{
	clear_screen();

	my_init();
	printf("Initialized.\n");

	my_showfreelist();

	int* a = NULL;

	a = my_realloc(a, 100);
	my_showfreelist();

	long int d = (long int) &a;

	my_realloc(a, 0);
	my_showfreelist();

	int* num = my_calloc(12, sizeof(int));
	printf("Called Calloc 12 objects. Each an int.\n");
	
	my_showfreelist();

	*num = 256 * 256 * 256;
	
	my_free(num);
	printf("Freed the calloc object.\n");

	my_showfreelist();

	int* new_num = my_malloc(10);
	printf("my_malloc called. 10 bytes memory allocation  \n");

	my_showfreelist();

	my_free(new_num);
	printf("Freed the malloc memory.\n");
	
	my_showfreelist();
	
	my_uninit();
	printf("Uninitialized memory.\n");
	
	return 0;
}

void clear_screen()
{
	printf("\33c");
}

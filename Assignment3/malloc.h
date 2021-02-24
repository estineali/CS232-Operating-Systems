#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#ifndef Lec1_ma03559_A3_malloc

typedef struct Node
{	
	int size;
	struct Node_t *next;
} Node_t;

typedef struct LinkedList
{
	
	Node_t *head;
	size_t node_count; //Count of nodes.
} LinkedList_t;

typedef struct MemoryHeader
{
	int size;
	int magic_number; //Count of nodes.
} Header_t;

LinkedList_t heap; 

int my_init();
void *my_malloc(int size);
void my_free(void *what);
void *my_calloc(int num, int size);
void *my_realloc(void* what, int size);
void my_coalesce();
void my_showfreelist();
void my_uninit();
int get_magic(int password); //Helper_function
#endif

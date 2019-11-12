#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct
{	
	int val;
	struct Node_t *next;
	
} Node_t;

typedef struct 
{
	Node_t *head;
	Node_t *tail;
	int size;
} LinkedList_t;


int add_element(int value, LinkedList_t* l)
{
	
	Node_t* temp = malloc(sizeof(Node_t));
	temp->val = value; 
	temp->next = NULL;

	if (l->size == 0)
	{
		head->temp;

	}
	else if (l->size > 0)
	{

	}

	l->tail->next = temp;
	tail->temp;

	return 0;
}

int main(int argc, char const *argv[])
{
	LinkedList_t l;
	l.size = 0;
	l.head = NULL;
	l.tail = NULL;

	printf("%ld\n", sizeof(Node_t));
	printf("Hello World\n");
	return 0;
}
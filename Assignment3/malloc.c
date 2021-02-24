#include "Lec1_ma03559_A3_malloc.h"

//Helpers
int get_magic(int password)
{
	//Wrap magic number, hide it. 
	//Password to prevent user(s) from accessing it.

	return password != 1357924680 ? 0 : 97654321;
}

//Functions 
int my_init()
{
	size_t init_size = 1048576;  //1 MB 

	Node_t* head = mmap(NULL, init_size, 
							PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if ( (void*) head == (void*) -1)
	{
		printf("Failed to Allocate Memory!\n");
		return 0;
	}
	

	head->size = init_size - sizeof(Node_t); 
	head->next = NULL;

	heap.node_count = 1; //Number of free-space blocks
	heap.head = head;

	return 1;
}

void *my_malloc(int size) 
{ 

	Node_t* before_temp = heap.head;
	Node_t* temp = heap.head;

	int is_head = 1; //to check if node is also the head_node 
	
	while (temp != NULL)
	{
		if (temp->size >= size )
		{
			//Conserving old values of *temp
			int temp_size = temp->size;  
			Node_t* temp_next = (Node_t*) temp->next;

			Header_t* header =  (Header_t*) temp;
			header->size = size;
			header->magic_number = get_magic(1357924680);

			temp =  (void* ) temp + sizeof(Header_t);
			
			void* retval = (void* ) temp;

			temp = (void* ) temp + size;  
			temp->size = temp_size - size - sizeof(Header_t);
			temp->next = (void*) temp_next;
			
			if (is_head == 1)
			{
				heap.head = temp;
			}
			else
			{
				before_temp->next = (void*) temp;
			}
			
			return retval;
		}
		before_temp = temp;
		temp = (Node_t*) temp->next;
		is_head = 0;
	}
	if (temp == NULL)
	{
		printf("Not enough memory to allocate %d bytes. Exiting now... \n",size );
		return NULL;
	}
}


void *my_calloc(int num, int size) 
{ 
	if (num == 0 || size == 0)
	{
		return NULL;
	}

	int total_bytes = num*size;
	
	Node_t* before_temp = heap.head;
	Node_t* temp = heap.head;
	int is_head = 1; //to check if node is also the head_node 
	
	while (temp != NULL)
	{
		if (temp->size >= total_bytes )
		{

			//Conserving old values of *temp
			int temp_size = temp->size;  
			Node_t* temp_next = (Node_t*) temp->next;

			Header_t* header =  (Header_t*) temp;
			header->size = total_bytes;
			header->magic_number = get_magic(1357924680);

			temp =  (void* ) temp + sizeof(Header_t);
	
			void* retval = (void* ) temp; //address to be returned;

			char* temp_reset_ptr = retval;
			for (int i = 0; i < total_bytes; ++i)
			{
				*temp_reset_ptr = 0;
				temp_reset_ptr++; 
			}

			temp = (void* ) temp + total_bytes;  
			temp->size = temp_size - total_bytes - sizeof(Header_t);
			temp->next = (void*) temp_next;
			
			if (is_head == 1)
			{
				heap.head = temp;
			}
			else
			{
				before_temp->next = (void*) temp;
			}
			
			return retval;
		}
		before_temp = temp;
		temp = (Node_t*) temp->next;
		is_head = 0;
	}
	if (temp == NULL)
	{
		printf("Not enough memory to allocate %d bytes. Exiting now... \n",size );
		return NULL;
	}
}

void my_free(void *what) 
{
	//Error Handling 
	if (*((int*) what - 1) != get_magic(1357924680))
	{
		printf("Invalid Memory to Free. Exiting...\n");
		return;
	}

	int size = *((int*) what - 2); //size in Header_t of 
	void* current_heap_head = heap.head;

	Node_t* temp = (Node_t*) ((int*) what - 2);
	temp->size = size + (sizeof(int) * 2);
	temp->next =  current_heap_head;
	
	heap.head = temp;
	heap.node_count++;
}

void my_showfreelist() 
{
	Node_t* temp = heap.head; 
	
	printf("\nNode no. : Node Size : Node Address \n");
	for (int i = 0; i < heap.node_count; ++i)
	{
		printf("%d\t : %d : %p\n", i, temp->size, temp);
		temp = (void*) temp->next;	
	}
	printf("\n");
}

void my_uninit() 
{
	Node_t* temp = heap.head;
	int found = 0;

	long long int addr_pointed;
	
	while (temp != NULL)
	{
		addr_pointed = (long long int) temp;
		if (addr_pointed % 0x1 == 0)
		{
			found = 1;
			break;
		}
		temp = (Node_t*) temp->next;
	}
	if (found == 0)
	{
		printf("ERROR: Memory not free. Cannot uninitialize memory.\n");
		return;
	}

	int uninitialized = munmap(temp, 1024*1024);
	if (uninitialized != 0)
	{
		printf("my_uninit failed.\n");
	}
	return ;
}

void *my_realloc(void* what, int size) 
{
	if (what == NULL)
	{
		return my_malloc(size);
	}
	else if (size == 0)
	{
		my_free(what);
		return NULL;
	}
	else
	{
		int old_size = *((int*) what - 2); //size in Header_t 
		
		void* new = my_malloc(size); //Ability to access each byte

		int amount_to_copy = old_size >= size ? size : old_size;
		char *read_buff = (char*) what; 
		void *write_buff = new;

		for (int i = 0; i < amount_to_copy; ++i)
		{
			*((char*) write_buff) = *read_buff;
			read_buff++; 
			write_buff++;
		}
		my_free(what);
		return new;
	}
}

void my_coalesce() 
{
    
}

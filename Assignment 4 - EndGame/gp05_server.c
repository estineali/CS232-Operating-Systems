/*hello_server.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUF_SIZE 4096

//Structs
typedef struct server_class
{
	char* server_IP;
	short port;
	struct sockaddr_in saddr_in;
	socklen_t saddr_len;
	int server_sock;
	
} server_t;

typedef struct client_class
{
	struct sockaddr_in client_saddr_in;
	int client_sock;
	char response[BUF_SIZE];
	int n;
	char* identifier;
	
} client_t;

typedef struct Node
{	
	client_t* _client;
	struct Node_t *next;
} Node_t;

typedef struct LinkedList	
{
	Node_t *head_client;
	int client_count;
} LinkedList_t;



//Prototypes
void set_up_server(server_t* s, short argv_port);
void* connect_to_client(client_t* c, server_t* s);

LinkedList_t all_clients;

//Main
int main(int argc, char* argv[])
{
	if (argv[1] == NULL)
	{
		printf("No port mentioned. Exiting now...\n");
		exit(1);
	}

	all_clients.client_count = 0;
	all_clients.head_client = NULL;

	server_t main_server;
	set_up_server(&main_server, atoi(argv[1]));


	client_t client;
	connect_to_client(&client, &main_server);
		
	char message_to_send[BUF_SIZE];
	//read from client
	int read_count = 0;
	do
	{
		client.n = read(client.client_sock, client.response, BUF_SIZE-1);  //bytes read from client 
		if(client.n < 0)
		{
			perror("read");
			exit(1);
		}
		client.response[client.n] = '\0'; //NULL terminate string
		if (read_count == 0)
		{
			client.identifier = client.response;
		}
		read_count++;
		
		printf("\nRead from client: %s\n", client.response);

		snprintf(message_to_send, BUF_SIZE, "Hello %s:%d \nI am server. \nThis is the %dth response.\n",
		inet_ntoa(client.client_saddr_in.sin_addr), //address as dotted quad
		ntohs(client.client_saddr_in.sin_port), read_count); //the point main(int argc, char* argv[])

		printf("Sending: %s",message_to_send);

		if(write(client.client_sock, message_to_send, strlen(message_to_send)) < 0)
		{
			perror("write");
			exit(1);
		}

	} while (strncmp("\\quit", client.response, strlen("\\quit")));
	
	printf("Closing socket\n\n");
	
	//close sockets
	close(client.client_sock);
	close(main_server.server_sock);
	return 0; //success
}

void set_up_server(server_t* s, short argv_port)
{
	/*
		Function that sets up a server with all initial values. 
		- intializing the socket
		- binding the socket to the IP
		- start listening 

	*/

	//Setting Values
	s->server_IP = "127.0.0.1";
	s->port = argv_port;
	s->saddr_len = sizeof(struct sockaddr_in);

	s->saddr_in.sin_family = AF_INET;
	s->saddr_in.sin_addr.s_addr = INADDR_ANY;
	s->saddr_in.sin_port = htons(s->port);
	inet_aton(s->server_IP, &s->saddr_in.sin_addr);
	
	//initializing socket
	s->server_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(s->server_sock < 0)
	{
		perror("server socket");
		exit(1);
	}

	//binding socket to IP
	int bind_success = bind(s->server_sock, (const struct sockaddr *) &s->saddr_in, s->saddr_len);
	if(bind_success < 0)
	{
		perror("bind");
		exit(1);
	}

	//ready to listen, queue up to queue_size pending connectinos
	int queue_size = 5;
	if(listen(s->server_sock, queue_size) < 0)
	{
		perror("listen");
		exit(1);
	}

	printf("Listening On: %s:%d\n", 
		inet_ntoa(s->saddr_in.sin_addr), 
		ntohs(s->saddr_in.sin_port));
}

void* connect_to_client(client_t* c, server_t* s)
{
	c->client_sock = accept(s->server_sock, (struct sockaddr *) &c->client_saddr_in, &s->saddr_len);
	
	if(c->client_sock < 0)
	{
		perror("accept");
		exit(1);
	}
	
	printf("Connection From: %s:%d (%d)\n", 
		inet_ntoa(c->client_saddr_in.sin_addr), 
		ntohs(c->client_saddr_in.sin_port), 
		c->client_sock); 
		
		//printing:
			//address as dotted quad
			//the port in host order
			//the file descriptor number
}

// int add_client(client_t* c, char* identifier)
// {	
// 	//Check if already exists 
// 	Node_t* temp_c = all_clients.head_client; 
// 	for (int i = 0; i < all_clients.client_count; ++i)
// 	{
// 		if (strcmp(temp_c->client_identifier, identifier) == 0)
// 		{
// 			printf("ERROR: non-unique identifier. Can\'t add client.\n");
// 			return -1;
// 		}
// 		temp_c = temp_c->next;
// 	}

// 	return 0;

// }

// void* get_client(char* identifier)
// {

// }
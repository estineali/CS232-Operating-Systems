/*hello_server.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 4096

//Structs
typedef struct Node
{	
	char* client_identifier;
	short client_port;
	struct Node_t *next;
} Node_t;

typedef struct LinkedList	
{
	Node_t *head;
	int node_count; //Count of nodes.
} LinkedList_t;

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
	
} client_t;

//Prototypes
void set_up_server(server_t* s, short argv_port);
void* connect_to_client(client_t* c, server_t* s);


//Main
int main(int argc, char* argv[])
{
	if (argv[1] == NULL)
	{
		printf("No port mentioned. Exiting now...\n");
		exit(1);
	}

	server_t main_server;
	client_t client;

	set_up_server(&main_server, atoi(argv[1]));
	connect_to_client(&client, &main_server);
		
	//read from client
	char response[BUF_SIZE];
	int n = read(client.client_sock, response, BUF_SIZE-1);  //bytes read from client 
	if(n < 0)
	{
		perror("read");
		exit(1);
	}
	response[n] = '\0'; //NULL terminate string
	
	printf("Read from client: %s\n", response);
	
	//construct response
	snprintf(response, BUF_SIZE, "Hello %s:%d \nGo Navy! Beat Army\n",
		inet_ntoa(client.client_saddr_in.sin_addr), //address as dotted quad
		ntohs(client.client_saddr_in.sin_port)); //the point main(int argc, char* argv[])
	// int serv_socket = socket(AF_INET, SOCK_STREAM, 0);
	// rt in host order
	
	printf("Sending: %s",response);
	
	//send response
	if(write(client.client_sock, response, strlen(response)) < 0)
	{
		perror("write");
		exit(1);
	}
	
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
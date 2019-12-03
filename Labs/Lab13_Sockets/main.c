#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
	char* hostname = "localhost";

	struct addrinfo hints, *result;

	struct sockaddr_in *saddr;

	int s; //Error checking 

	memset(&hints, 0, sizeof(struct addrinfo));

	hints.ai_family = AF_INET; //restrict to IPv4

	if ((s = getaddrinfo(hostname, NULL, &hints, &result)) != 0)
	{
		printf("getaddrinfo error: %s\n", gai_strerror(s));
	}

	saddr = (struct sockaddr_in * ) result->ai_addr;

	saddr->sin_port = htons(80);

	printf("Hello %s\n", inet_ntoa(saddr->sin_addr));

	freeaddrinfo(result);

	return 0;
}



// int socket(int domain, int type, int protocol);
/*
	a socket is a file descriptor that happens to write to the network device rather than to a file on disc.
	
	domain is the addressing domain of socket, which for our purposes is an internet socket or AF_INET

	HTTP traffic is over TCP, so that would be SOCK_STREAM. If we wanted to open a UDP socket, the keyword would be SOCK_DGRAM
	
	All further socket operations, 	connect(), 	read(), 	write(), 	bind(), 	accept() and etc, require that integer file descriptor. 

	Sockets that share common communication properties, such as naming conventions and protocol address formats, are grouped into communication domains.

	The communication domain includes the following:
    	Rules for manipulating and interpreting names
    	Collection of related address formats that comprise an address family
    	Set of protocols, called the protocol family


*/
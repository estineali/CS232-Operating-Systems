#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	int fd_to_write;
	char* named_pipe_address = "./NOTAFILEAFIFO";

	int return_value = mkfifo(named_pipe_address, 0666);
	if (return_value == -1)
	{
		printf("FIFO not created.\n");
	}

	fd_to_write = open(named_pipe_address, O_WRONLY);
	
	if (fd_to_write == -1)
	{
		printf("File: %s not opened \n", named_pipe_address);
	}
	write(fd_to_write, "Hello World\0", 15);
	
	close(fd_to_write);

	return 0;
}
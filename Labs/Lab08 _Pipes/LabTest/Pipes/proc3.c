#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
	int fd_to_read;
	char* named_pipe_address = "./NOTAFILEAFIFO";

	fd_to_read = open(named_pipe_address, O_RDONLY);
	char read_data[20];
	// printf("%d\n", fd_to_read);

	if (fd_to_read == -1)
	{
		printf("Read FIFO not opened.\n");
	}

	int retval = read(fd_to_read, read_data, 20);
	fflush(stdin);
	write(1, read_data, retval);
	if (retval == -1)
	{
		printf("data not read\n");
	}
	close(fd_to_read);

	return 0;
}
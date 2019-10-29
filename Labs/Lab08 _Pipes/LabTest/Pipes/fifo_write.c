#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd, retval; //The file descriptor of the opened file; the return value from mkfifo
	char buffer[] = "TESTDATA"; //Data to write in the file
	
	fflush(stdin); //clear stdin file
	retval = mkfifo("/tmp/myfifo",0666); //make named pipe SHOULD HAVE CHECKED RETVAL
	fd = open("/tmp/myfifo",O_WRONLY); // open pipe SHOULD HAVE CHECKED RETURN VALUE BEFORE WRITING
	write(fd, buffer, sizeof(buffer)); //write to file, the data in buffer
	close(fd); //close file 
	return 0;
}

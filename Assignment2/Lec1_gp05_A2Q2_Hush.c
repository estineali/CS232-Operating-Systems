#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int string_length(char* );

int main(int argc, char const *argv[])
{
	int Exit = 0;

	printf("\033cGreetings Master\n");

	char* prompt = "Master@HUSh: Your wish is my command$ ";  
	
	int max_command_length = 255;

	while (!Exit)
	{
		printf("%s", prompt);
		
		char* command = malloc(max_command_length);
		command = fgets(command, max_command_length, stdin);

		if (command == NULL)
		{
			fprintf(stderr, "ERROR! With all due respect Master, what in the world are you on about?.\n");
		}

		else
		{
			if (strncmp("exit", command, 4) == 0 && string_length(command) == 4)
			{
				//Kill Running processes
				printf("So be it, Master. I will wait for your return.\n");
				Exit = 1;
			} 
			else if (strncmp("clear", command, 5) == 0 && string_length(command) == 5)
			{
				printf("\033c");
			} 
			else 
			{
				printf("\nI dont understand your Wish, master  %s \n\n", command);	
			}
			// else 
			// {
			// 	int new_proc = fork();

			// 	if (new_proc < 0) 
			// 	{
			// 		fprintf(stderr, "Invalid Fork master!\n");
			// 		exit(1);
			// 	} 

			// 	else if (new_proc == 0) 
			// 	{ // child (new process)
			// 		printf("hello, I am child (pid:%d)\n", (int) getpid());
			// 	} 
			// 	else 
			// 	{
			// 		// parent goes down this path (main)
			// 		int termed_proc = wait(NULL);
			// 		printf("Terminated Process: %d\n", termed_proc);
			// 		printf("hello, I am parent of %d (pid:%d)\n", new_proc, (int) getpid());
			// 	}
			// }

		}
		free(command);

	}
	return EXIT_SUCCESS;
}


int string_length(char* string)
{
	int i = 0;
	while (string[i])
	{
		i++;
	}
	return i-1;
}
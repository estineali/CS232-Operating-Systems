#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//Prototypes
int string_length(char* );
void print_string_array(char* const array[]);

struct process
{
	int pid;
	char* name;
	int status;
};

//Main
int main(int argc, char const *argv[])
{
	printf("\033cGreetings Master\n");
	
	//Setting Path variable data structure 
	char *VAR[16];
	int j = 0;
	VAR[j] = strtok(getenv("PATH"), ":");
	while (VAR[j] != NULL)
	{	
		j++;
		VAR[j] = strtok(NULL, ":");
	}
	VAR[j] = "./";
	j++;
	VAR[j] = NULL;


	int Exit = 0; 
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
				int new_proc = fork();

				if (new_proc < 0) 
				{
					fprintf(stderr, "Invalid Fork master!\n");
					free(command);
					exit(1);
				} 

				else if (new_proc == 0) 
				{ 	

					int no_of_arg = 100;
					char* child_argv[no_of_arg];
					int j = 0;

					child_argv[j] = strtok(command, " ");

					while (child_argv[j] != NULL)
					{	
						j++;
						child_argv[j] = strtok(NULL, " ");
					}
					child_argv[j-1] = strtok(child_argv[j-1], "\n");
					child_argv[j] = NULL; //END OF ARRAY 

					char buffer[255];
					int v = 0;
					
					//Check all directories in path to run input program 
					while (execvp(buffer, child_argv) == -1)
					{
						strcpy(buffer, VAR[v]);
						strcat(buffer, "/");
						strcat(buffer, child_argv[0]);
						// printf("%s\n", buffer);
						v++;
					}

					fprintf(stderr, "FAILED to load %s\n", child_argv[0]);
					printf("\nI dont understand your Wish, master...  %s \n\n", command);	
					free(command);
					exit(-1);
				} 
				else 
				{
					//PARENT
					int termed_proc = wait(NULL);
				}
			}

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

void print_string_array(char* const array[])
{
	int j = 0;
	while (array[j] != NULL)
	{
		printf("%s\n", array[j]);
		j++;
	}
}


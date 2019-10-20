/** 
Requirements: 
	1. Cool prompt to prompt the user for input 
	2. 

**/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	printf("\033c"); //Clear the terminal window

	// printf("Hey! Welcome to HUSh.\n"); // Welcome command 
	char inp_by_user[100]; //Contains user input 
	
	const char prompt[] = "Master! Your wish is my command $ "; //The cool prompt it shows everytime  
	

	while (!(strncmp("exit", inp_by_user, 4) == 0))
	{ // bug: if input is hello, program closes all the same 
		
		printf("%s", prompt);
		scanf("%s", inp_by_user);
		
		//Whaetevr you intend to do with the input 
		printf("\nYou said: %s \n\n", inp_by_user);
	}

	return 0;
}

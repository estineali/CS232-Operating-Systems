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

	printf("Greetings Master\n");
	// printf("Hey! Welcome to HUSh.\n"); // Welcome command 
	char inps_by_user[100] = ""; //Contains user input 

	const char prompt[] = "Master@HUSh: Your wish is my command$ "; //The cool prompt it shows everytime  
	
	//main Loop: run as long as not asked to exit 

	while (!(strncmp("exit", inps_by_user, 4) == 0))
	{
		printf("%s", prompt);
		scanf("%s", inps_by_user);
		
		//Whaetevr you intend to do with the input
		

		//Exit Protocol 
		if (strncmp("exit", inps_by_user, 4) == 0)
		{
			printf("So be it, Master. I will wait for your return.\n");
		} 
		else
		{
			printf("\nYou said: %s \n\n", inps_by_user);	
		}
		
	}
	return 0;

}

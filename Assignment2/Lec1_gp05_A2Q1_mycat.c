#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 1) //Just ./mycat
	{
		do 
		{
			char c = fgetc(stdin);

			if (feof(stdin))
			{
				break;
			}

			printf("%c", c);
		} while (1);
	}
	
	else if (argc >= 2)
	{
		if (strcmp(argv[1], "-n") != 0) //If there is -n
		{
			for (int i = 1; i < argc; i++)
			{
				FILE* fp;

				fp = fopen(argv[i], "r");
				if (fp == NULL)
				{
					fprintf(stderr, "mycat: %s: No such file or directory\n", argv[i]);
					exit(1);
				}
				
				do 
				{
					char c = fgetc(fp);

					if (feof(fp))
					{
						break;
					}

					printf("%c", c);
				} while (1);
				
				fclose(fp);	
			} 
		}
		else //If there is no -n
		{
			int ind = 1;

			for (int i = 2; i < argc; i++)
			{
				FILE* fp;

				fp = fopen(argv[i], "r");
				if (fp == NULL)
				{
					fprintf(stderr, "mycat: %s: No such file or directory\n", argv[i]);
					exit(1);
				}
				
				int filestrt = 1;

				do 
				{
					char c = fgetc(fp);

					if (feof(fp))
					{
						break;
					}

					if (filestrt == 1)
					{
						printf("%d\t", ind);
						filestrt = 0;
					}

					printf("%c", c);

					if (c == '\n')
					{
						ind++;
						printf("%d\t", ind);
					}
				} while (1);

				fclose(fp);	
			} 
		}	
	}
}
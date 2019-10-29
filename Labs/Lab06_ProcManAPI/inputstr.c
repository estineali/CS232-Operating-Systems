#include <stdio.h>

int main () {

	char str[20];
	printf("please enter a string:");
	scanf("%[^\n]s",str);
	printf("you entered: %s\n", str);
	

	return 0;
}

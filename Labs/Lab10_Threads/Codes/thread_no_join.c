/* hello_pthread_bad.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>


void * hello_fun(){

  printf("Hello World!\n");

  return NULL;
}

int main(int argc, char * argv[]){

  pthread_t thread;

  int ret = pthread_create(&thread, NULL, hello_fun, NULL);

  if (ret != 0)
  {
  	printf("Thread Creation Error.\n");
  	return -1;
  }

  pthread_join(thread, NULL);

  return 0;
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* gcc thread.c -Wall -g3 -oO -o thread -lptread 
 */
#define THREAD_NUM 30
int global_x = 10;


void * thread_main(void * _args) 
{
	int arg = *((int *) _args);
	free(_args);
	fprintf(stdout, "Inside thread main : %d \n", arg);
	return NULL;
}

int main ()
{
	pthread_t tid[THREAD_NUM];
	
	
	for (int i = 0; i < THREAD_NUM; ++i) {
		
		int * arg = (int *) malloc(1 * sizeof(char));
		* arg = i;
		
		if(pthread_create (&(tid[i]), NULL, &thread_main, arg) < 0 ) {
			fprintf(stderr, "Fail to create thread!\n");
			break;
		}
		
		for (int j = 0; j < i; ++j) {
			pthread_join (tid[j], NULL);
		} 
	}
	
	return 0;
}

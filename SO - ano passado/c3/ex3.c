#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];
int counter;
pthread_mutex_t mutex;

void * trythis(void* arg){
	unsigned long i = 0;
	pthread_mutex_lock(&mutex);
	counter += 1;
	printf("\nJob %d has started\n", counter);
	for(i = 0; i < (0xFFFFFFFF); i++);
	pthread_mutex_unlock(&mutex);
	printf("\n Job %d has finished\n", counter);
	return NULL;
}

int main(void){
	pthread_mutex_init(&mutex, NULL);
	int i = 0;
	int error;
	while(i < 2){
		error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		if(error != 0){
			printf("\nThread can't be created:[%s]", strerror(error));
		}
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define THREAD_NUM 2

sem_t semEmpty;	//counts the numbers of empty slots in the buffer
sem_t semFull;	//counts the number of occupied slots in the buffer

pthread_mutex_t mutexBuffer;

int buffer[10];
int count = 0;

void* producer(void* args){
	while(1){
		//Add to the buffer
		sem_wait(&semEmpty);
		pthread_mutex_lock(&mutexBuffer);
		int x = count;
		buffer[count] = count;
		count++;
		printf("Produced %d\n", x);
		pthread_mutex_unlock(&mutexBuffer);
		sem_post(&semFull);
		sleep(10);
	}
}

void* consumer(void* args){
	while(1){
		//Remove from the buffer
		sem_wait(&semFull);
		pthread_mutex_lock(&mutexBuffer);
		int y = buffer[count - 1];
		count--;
		printf("Consumed %d\n", y);
		pthread_mutex_unlock(&mutexBuffer);
		sem_post(&semEmpty);
		sleep(20);
	}
}

int main(int argc, char* argv[]){
	pthread_mutex_init(&mutexBuffer, NULL);
	pthread_t th[2];
	sem_init(&semEmpty, 0, 10);	//starts with 10 empty slots
	sem_init(&semFull, 0, 0);	//starts with 0 full slots
	int i;
	for(i = 0; i < THREAD_NUM; i++){
		if(i % 2 == 0){
			if(pthread_create(&th[i], NULL, &consumer, NULL) != 0){
				perror("Failed to create thread");
			}
		}
		else{
			if(pthread_create(&th[i], NULL, &producer, NULL) != 0){
				perror("Failed to create thread");
			}
		}
	}
	for(i = 0; i < THREAD_NUM; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join thread");
		}
	}
	sem_destroy(&semEmpty);
	sem_destroy(&semFull);
	pthread_mutex_destroy(&mutexBuffer);
	return 0;
}

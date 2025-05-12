#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

sem_t sem;

void* routine(void* args){
	int number = *(int*)args;
	if(number == 3){
		sem_wait(&sem);
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%d", number);
		}
		printf("\n");
	}
	sleep(1);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%d", number+1);
		}
		printf("\n");
	}
	sem_post(&sem);
}

int main(int argc, char* argv[]){
	pthread_t th0, th1;
	int i;
	sem_init(&sem, 0, 0);	//first semaphor starts 1
	
	int um = 1;
	int tres = 3;
	if(pthread_create(&th0, NULL, &routine, &um) != 0){
			perror("Failed to create thread");
	}
	if(pthread_create(&th1, NULL, &routine, &tres) != 0){
			perror("Failed to create thread");
	}

	if(pthread_join(th0, NULL) != 0){
		perror("Failed to join thread");
	}
	if(pthread_join(th1, NULL) != 0){
		perror("Failed to join thread");
	}
	
	
	sem_destroy(&sem);
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define THREAD_NUM 5	//number of philosophers

sem_t chopstick[5];	//let's call the forks chopstick so that it isn't mistaken for the fork() function

//the right handed philosopher will firstly pick up the right chopstick and then the left one
//the left handed philosopher will firstly pick up the left chopstick and then the right one
void* philosopher(void* args){
	int id = *(int*)args;
	while(1){
		printf("Philosopher %d is thinking\n", id);
		sleep(1);
		printf("Philosopher %d is hungry\n", id);
		//if the philosopher is right handed
		if(id % 2 == 0){
			sem_wait(&chopstick[id]);
			sem_wait(&chopstick[(id+1) % 5]);
		}
		else{
			sem_wait(&chopstick[(id+1) % 5]);
			sem_wait(&chopstick[id]);
		}
		printf("Philosopher %d is eating\n", id);
		sleep(2);
		printf("Philosopher %d stopped eating\n", id);
		sem_post(&chopstick[id]);
		sem_post(&chopstick[(id+1) % 5]);
	}
}

int main(int argc, char* argv[]){
	pthread_t th[THREAD_NUM];
	int i;
	//initialize all the chopsticks
	for(i = 0; i < 5; i++){
		sem_init(&chopstick[i], 0, 1);	//all chopsticks start with 1 because they are all available
	}
	
	//philosophers
	for(i = 0; i < THREAD_NUM; i++){
		int *id = malloc(sizeof(int));
		*id = i;
		if(pthread_create(&th[i], NULL, &philosopher, id) != 0){
			perror("Failed to create thread");
		}
	}
	
	for(i = 0; i < THREAD_NUM; i++){
		if(pthread_join(th[i], NULL) != 0){
			perror("Failed to join thread");
		}
	}
	
	//destroy all the chopsticks
	for(i = 0; i < 5; i++){
		sem_destroy(&chopstick[i]);
	}
	
	return 0;
}


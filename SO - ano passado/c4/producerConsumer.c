#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

sem_t semEmptyP1;	//conta o numero de vazios
sem_t semFullP1;	//conta o numero de nao vazios

sem_t semEmptyP2;	//conta o numero de vazios
sem_t semFullP2;	//conta o numero de nao vazios

sem_t semConsumer; //vai ser um semaforo binario para o consumidor para ser sempre c1 c2 c1 c2

pthread_mutex_t mutexBuffer1;
pthread_mutex_t mutexBuffer2;

int bufferP1[3];
int bufferP2[2];
int count1 = 0;
int count2 = 0;

void* producer(void* args){
	while(1){
		int np = *(int*)args;//para saber qual é o processo
		int x = rand() % 100;
		
		//se for 1 ele da wait no p1 senao da no p2 (so pode ser 1 ou 2)
		if(np == 1){
			sem_wait(&semEmptyP1);	//wait no p1
		}
		else{
			sem_wait(&semEmptyP2);	//wait no p2
		}
		//adiciona o numero aleatorio
		if(np == 1){
			pthread_mutex_lock(&mutexBuffer1);
			bufferP1[count1] = x;
			count1++;
			pthread_mutex_unlock(&mutexBuffer1);
		}
		else{
			pthread_mutex_lock(&mutexBuffer2);
			bufferP2[count2] = x;
			count2++;
			pthread_mutex_unlock(&mutexBuffer2);
		}
		//se for 1 ele da post no p1 senao da no p2
		if(np == 1){
			sem_post(&semFullP1);	//post no p1
		}
		else{
			sem_post(&semFullP2);	//post no p2
		}
	}
}

void* consumer(void* args){
	while(1){
		int np = *(int*)args;//para saber qual é o processo
		int y;
		//se for 1 ele da wait no p1 senao da no p2 (so pode ser 1 ou 2)
		
		if(np == 2){
			sem_wait(&semConsumer);	//semaforo dos consumidores para ir sempre 1, 2, 1, 2
		}
		
		if(np == 1){
			sem_wait(&semFullP1);	//wait no p1
		}
		else{
			sem_wait(&semFullP2);	//wait no p2
		}
		//retira do buffer que for preciso e decrementa o count
		if(np == 1){
			pthread_mutex_lock(&mutexBuffer1);
			y = bufferP1[count1 - 1];
			count1--;
			pthread_mutex_unlock(&mutexBuffer1);
		}
		else{
			pthread_mutex_lock(&mutexBuffer2);
			y = bufferP2[count2 - 1];
			count2--;
			pthread_mutex_unlock(&mutexBuffer2);
		}
		if(np == 1){
			sem_post(&semEmptyP1);	//post no p1
			sem_post(&semConsumer);	//post no semaforo dos consumidores para dizer ao c2 que pode ir agora
		}
		else{
			sem_post(&semEmptyP2);	//post p2
		}
		//Consume
		printf("c%d: ", np);
		printf("Got %d\n", y);
		sleep(1);
	}
}

int main(int argc, char* argv[]){
	srand(time(NULL));
	pthread_mutex_init(&mutexBuffer1, NULL);
	pthread_mutex_init(&mutexBuffer2, NULL);
	pthread_t th1;	//producer1
	pthread_t th2;	//producer2
	pthread_t th3;	//consumer1
	pthread_t th4;	//consumer2
	sem_init(&semEmptyP1, 0, 3);	//começa com 3 slots vazios
	sem_init(&semFullP1, 0, 0);	//começa com 0 slots preenchidos
	sem_init(&semEmptyP2, 0, 2);	//começa com 2 slots vazios
	sem_init(&semFullP2, 0, 0);	//começa com 0 slots preenchidos
	sem_init(&semConsumer, 0, 0);
	int p1 = 1;
	int p2 = 2;
	
	//p1
	if(pthread_create(&th1, NULL, &consumer, &p1) != 0){
		perror("Failed to create thread");
	}
	//p2
	if(pthread_create(&th2, NULL, &consumer, &p2) != 0){
		perror("Failed to create thread");
	}
	
	//c1
	if(pthread_create(&th1, NULL, &producer, &p1) != 0){
		perror("Failed to create thread");
	}
	//c2
	if(pthread_create(&th2, NULL, &producer, &p2) != 0){
		perror("Failed to create thread");
	}

	if(pthread_join(th1, NULL) != 0){
		perror("Failed to join thread");
	}
	if(pthread_join(th2, NULL) != 0){
		perror("Failed to join thread");
	}
	
	
	sem_destroy(&semEmptyP1);
	sem_destroy(&semFullP1);
	sem_destroy(&semEmptyP2);
	sem_destroy(&semFullP2);
	pthread_mutex_destroy(&mutexBuffer1);
	pthread_mutex_destroy(&mutexBuffer2);
	return 0;
}

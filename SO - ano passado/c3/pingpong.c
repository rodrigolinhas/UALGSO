#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int j;
int i = 0;
pthread_t tid[2];
pthread_mutex_t mutex;

void * trythis(void* arg){
	pthread_mutex_lock(&mutex);
	sleep(1);
	if(i == 2){
		return NULL;
	}
	if(j == 0){
		printf("ping\n");
	}
	else{
		printf("pong\n");
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void sighandler() {
	i++;
	if(i < 2){
		printf("\nnice try\n");
	}
	else{
		printf("\nyou got me this time\n");
	}
}

int main (int argc, char* argv[]){
	int k = 0;
	int error;
	pthread_mutex_init(&mutex, NULL);
	while(1){
		if(signal(SIGINT,&sighandler) == SIG_ERR ){
			printf ( "NO  signal\n" ) ;
		}
		if(i == 2){
			break;
		}
		j = k % 2; 
		error = pthread_create(&(tid[j]), NULL, &trythis, NULL);
		if(error != 0){
			printf("\nThread can't be created:[%s]", strerror(error));
		}
		k++;
		pthread_join(tid[j], NULL);
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}

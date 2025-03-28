#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

bool end = false;
char msg[30];

void *routine0(){
	printf("Thread 1: ");
	fflush(stdout);
	fgets(msg, sizeof(msg), stdin);
}

void *routine1(){
	if(msg[0] == 'E' && msg[1] == '\n'){
		end = true;
	}
	for(int i = 0; i < 30; i++){
		if(msg[i] == '\n')  break;
		printf("Thread 2: ");
		printf("%c\n", msg[i]);
	}
}

int main (int argc, char* argv[]){
	pthread_t th0, th1;
	while(true){
		if(pthread_create(&th0, NULL, &routine0, NULL) != 0){
            perror("Erro ao criar thread");
        	return 1;
    	}
    	if (pthread_join(th0, NULL) != 0){
        	perror("Erro ao juntar thread");
        	return 2;
    	}
    	if(pthread_create(&th1, NULL, &routine1, NULL) != 0){
            perror("Erro ao criar thread");
    	    return 1;
    	}
    	if (pthread_join(th1, NULL) != 0){
            perror("Erro ao juntar thread");
        	return 2;
    	}	
    	if(end){
    		break;
    	}
	}
	printf("Prog finished\n");	
	return 0;
}

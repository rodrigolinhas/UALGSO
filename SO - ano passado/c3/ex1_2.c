#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;
char msg[] = "mensagem da thread ";

void *routine(){
	for(int j = 0; j < 19; j++){
		printf("%c", msg[j]);
		fflush(stdout);
		sleep(1);
	}
	printf("%d\n", i);
	sleep(1);
}

int main (int argc, char* argv[]){
	pthread_t th[5];
	for(i = 0; i < 5; i++){
		if(pthread_create(th + i, NULL, &routine, NULL)){
        	return 1;
    	}
		if (pthread_join(th[i], NULL)){
        	return 2;
    	}
    }
	return 0 ;
}

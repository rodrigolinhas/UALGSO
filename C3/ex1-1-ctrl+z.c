#include <stdlib.h>
#include <stdio.h>
//#include <pthread.h>
#include <unistd.h>
#include <signal.h>

int i = 0;
int trys = 5;

void sighandler() {
	i++;
	if(i < 5)   printf("\nfalta %d tentativas\n", (trys-i));
	else        printf("\ndone\n");
}

int main (int argc, char* argv[]){
	while(1){
		if (signal(SIGINT,&sighandler) == SIG_ERR  || 
                signal(SIGTSTP, &sighandler) == SIG_ERR) printf("NO signal\n");
		if(i == 5)  break;
	}
	return 0;
}
 
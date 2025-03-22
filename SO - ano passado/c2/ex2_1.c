#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid > 0){
		for(int i = 0; i < 3; i++){
			printf("Eu sou o pai, a minha identificação é %ld\n", (long)getpid());
		}
	}
	else{
		sleep(1);
		for(int i = 0; i < 5; i++){
			printf("Eu sou o filho o meu pai é %ld\n", (long)getppid());
		}
	}
	wait(&pid);
	exit(0);
}

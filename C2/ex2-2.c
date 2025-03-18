#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	pid_t pid = fork();
	//cria 3 filhos
	pid_t pid1,pid2;
	if(pid > 0){
		pid1 = fork();
		if(pid1 > 0){
			pid1 = fork();
			if(pid1 > 0){
				pid1 = fork();
			}
		}
	}
	//cria 2 filhos do 1 filho
	else if(pid == 0){
		pid2 = fork();
		if(pid2 > 0){
			pid2 = fork();
		}
	}
	//se é pai ou 1o filho
	if(pid > 0 && pid1 > 0 || pid == 0 && pid2 > 0){
		//pai é impresso primeiro (sleep)
		if(pid == 0){
			sleep(1);
		}
		for(int i = 0; i < 3; i++){
			printf("Eu sou o pai, a minha identificação é %ld\n", (long)getpid());
		}
	}
	else{
		sleep(2);
		//filhos do pai são impressos (sleep)
		if(pid == 0){
			sleep(1);
		}
		for(int i = 0; i < 5; i++){
			printf("Eu sou o filho o meu pai é %ld\n", (long)getppid());
		}
	}
	wait(&pid);
	wait(&pid);
	wait(&pid);
	wait(&pid);
	exit(0);
}

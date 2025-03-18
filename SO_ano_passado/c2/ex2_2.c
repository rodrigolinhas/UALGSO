#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	//create 3 extra children to root
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
	//create 2 extra children to first child
	else if(pid == 0){
		pid2 = fork();
		if(pid2 > 0){
			pid2 = fork();
		}
	}
	//if its the root or the first children
	if(pid > 0 && pid1 > 0 || pid == 0 && pid2 > 0){
		//sleep so that root is printed first
		if(pid == 0){
			sleep(1);
		}
		for(int i = 0; i < 3; i++){
			printf("Eu sou o pai, a minha identificação é %ld\n", (long)getpid());
		}
	}
	else{
		sleep(2);
		//sleep so that sons of root are printed first
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

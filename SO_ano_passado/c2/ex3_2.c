#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t p1 = fork();
	if(p1 > 0){
		pid_t p2 = fork();
		if(p2 > 0){
			execlp("ls","ls","-l",NULL);	
		}
		else if(p2 == 0){
			execlp("ps","ps",NULL);
		}
	}
	else if(p1 == 0){
		execlp("who","who",NULL);
	}
	
	exit(0);
}

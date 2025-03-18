#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		pid = fork();
		if(pid == 0){
			pid = fork();
		}
	}
	if(pid > 0){
		wait(&pid);
	}
	//printf("%ld% ld\n", (long)getpid(), (long)getppid());
	system("ps");
	exit(0);
}

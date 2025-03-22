#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	if(fork() && (!fork())){
		if(fork() || fork()){
			fork();
		}
	}
	//wait(NULL);
	//wait(NULL);
	//wait(NULL);
	printf("%ld% ld\n", (long)getpid(), (long)getppid());
	exit(0);
}

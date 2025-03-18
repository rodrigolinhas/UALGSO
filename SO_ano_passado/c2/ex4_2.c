#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int fd[2];
    pipe(fd);
    pid_t id = fork();
    
    if (id == 0) {
        // Child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("echo", "echo", "Ola Hi", NULL);
        close(fd[1]);
    } else {
        // Parent process
        	close(fd[1]);
        	dup2(fd[0], STDIN_FILENO);
        	execlp("wc", "wc", NULL);
        	close(fd[0]);
    }
    exit(0);
}

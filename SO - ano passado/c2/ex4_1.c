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
        char * w = "Hello, it's me";
        close(fd[0]);
        if (write(fd[1], &w, sizeof(int)) == -1) {
            printf("An error ocurred with writing to the pipe\n");
            return 3;
        }
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        char * w;
        if (read(fd[0], &w, sizeof(int)) == -1) {
            printf("An error ocurred with reading from the pipe\n");
            return 4;
        }
        printf("%s\n", w);
        close(fd[0]);
    }
}

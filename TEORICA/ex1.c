#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/random.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
    int fd[2];
    int fd1[2];
    pipe(fd);
    pipe(fd1);
    pid_t pid = fork();
    int volta = 0;
    //pai
    if (pid != 0) {
        int random  = rand() % 10;
        close(fd[0]);
        write(fd[1], &random, sizeof(int));
        printf("rand x = %d", random);

        close(fd1[1]);
        volta = (int) rand * 4;
    }
    //filho
    else{
        printf("rect x = %d", volta);
    }
    return 0;
}

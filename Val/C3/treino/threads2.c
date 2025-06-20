/*
Demonstra fork(): o filho incrementa x, mas o pai mantém x = 2 (espaço de memória separado).
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    int x = 2;
    int pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        x++;
        //printf("PID: %d\n", getpid());
    }
    sleep(2);
    printf("Value of x: %d\n", x);
    
    if (pid != 0) {
       // printf("PID: %d\n", getpid());
        wait(NULL);
    }
    return 0;
}


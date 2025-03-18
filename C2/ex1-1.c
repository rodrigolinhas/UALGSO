#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t p1, p2;
    p1 = fork();
    p2 = fork();
    exit(0);
}
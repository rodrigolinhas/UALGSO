#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = (fork() && (fork() ||fork()));
    wait(&pid);
    system("ps");
    exit(0);
}
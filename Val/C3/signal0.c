/*
Cria um processo filho que imprime "Hello" indefinidamente. O pai envia SIGKILL após 1 segundo, terminando o filho.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


int main(int argc, char* argv[]) {

    pid_t pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        // Child process
        while(1){
        printf("Hello\n");
        usleep(20000);
        }
    } else {
        // Parent process 
        sleep(1);
        kill(pid, SIGKILL); 
        wait(NULL);
    }
    return 0;
 }

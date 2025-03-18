#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/wait.h>  

int main(void) {  
    pid_t pid;  
    int status;  

    pid = fork();  
    if (pid == 0) {  
        //filho  
        exit(0);  
    } else {  
        while (wait(&status) > 0); // Espera por todos os filhos  
    }  
    system("ps");  
    exit(0);  
}

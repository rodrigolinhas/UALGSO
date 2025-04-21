/*
O filho envia SIGUSR1 ao pai após 5 segundos.

O pai espera a resposta do usuário para uma pergunta matemática e exibe uma dica via handler
*/
#include <stdio.h>  
#include <signal.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/wait.h>

int x; // Variável global para acesso pelo handler  


void handle_sigusr(int sig) {  
    printf("\n(HINT) Remember that multiplication is repetitive addition!\n");  
}  

int main(int argc, char* argv[]) {  
    
    int pid = fork();  
    if (pid == -1) {  
        return 1;  
    }  

    if (pid == 0) {  
        // Child process  
        sleep(5);  
        kill(getppid(), SIGUSR1);  
    } else {  
        // Parent process  
        struct sigaction sa; 
        sa.sa_flags = SA_RESTART;  
        sa.sa_handler = &handle_sigusr;  
        sigaction(SIGUSR1, &sa, NULL);  

        printf("What is the result of 3 x 5?: ");  
        scanf("%d", &x); // Removido o \n  
        if (x == 15) {  
            printf("Right!\n");  
        } else {  
            printf("Wrong\n");  
        }  
        wait(NULL);  
    }  
    return 0;  
}  
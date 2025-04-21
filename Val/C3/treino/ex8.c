/*
Comunicação Bidirecional com Sinais

Descrição:
Crie um processo pai e filho. O pai envia SIGUSR1 ao filho, que responde com SIGUSR2. 
Ambos contam o número de sinais recebidos e terminam após 5 trocas.
*/
#include <stdio.h>  
#include <signal.h>  
#include <unistd.h>  
#include <sys/wait.h>  

volatile sig_atomic_t count = 0;  

void parent_handler(int sig) {  
    write(STDOUT_FILENO, "Pai recebeu SIGUSR2\n", 20);  
    count++;  
}  

void child_handler(int sig) {  
    write(STDOUT_FILENO, "Filho recebeu SIGUSR1\n", 21);  
    kill(getppid(), SIGUSR2); // Responde ao pai  
    count++;  
}  

int main() {  
    pid_t pid = fork();  
    if (pid == 0) {  
        // Filho  
        signal(SIGUSR1, child_handler);  
        while (count < 5) pause();  
    } else {  
        // Pai  
        signal(SIGUSR2, parent_handler);  
        sleep(1);  
        for (int i = 0; i < 5; i++) {  
            kill(pid, SIGUSR1);  
            pause();  
        }  
        wait(NULL);  
    }  
    return 0;  
}  
/*
Explicação:

    kill envia sinais entre processos.

    pause() espera por um sinal.
*/
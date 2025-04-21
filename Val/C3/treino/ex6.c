/*
Bloqueio de Sinais com sigprocmask

Descrição:
Crie um programa que bloqueia SIGINT durante uma operação crítica 
(ex: incrementar uma variável global 1.000.000 vezes). 
Use sigprocmask para bloquear o sinal durante a operação e desbloqueá-lo após.
*/
#include <stdio.h>  
#include <signal.h>  
#include <unistd.h>  

volatile sig_atomic_t counter = 0;  

void sigint_handler(int sig) {  
    write(STDOUT_FILENO, "SIGINT bloqueado durante operação!\n", 33);  
}  

int main() {  
    sigset_t mask;  
    sigemptyset(&mask);  
    sigaddset(&mask, SIGINT);  
    signal(SIGINT, sigint_handler);  

    // Bloqueia SIGINT  
    sigprocmask(SIG_BLOCK, &mask, NULL);  

    for (int i = 0; i < 1000000; i++) counter++;  

    // Desbloqueia SIGINT  
    sigprocmask(SIG_UNBLOCK, &mask, NULL);  

    printf("Counter: %d\n", counter);  
    while(1) sleep(1);  
    return 0;  
}  
/* 
Explicação:

    sigprocmask bloqueia SIGINT durante o incremento, evitando interrupções.

    Sinais bloqueados são "pendentes" e executados após o desbloqueio.
*/
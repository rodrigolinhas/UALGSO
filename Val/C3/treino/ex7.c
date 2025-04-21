/*
Sinais em Threads com pthread_sigmask

Descrição:
Crie duas threads. 
A Thread 1 bloqueia SIGUSR1 e fica em loop. 
A Thread 2 configura um handler para SIGUSR1. 
Use pthread_sigmask para direcionar o sinal à Thread 2.
*/

#include <pthread.h>  
#include <signal.h>  
#include <stdio.h>  
#include <unistd.h>  

void* thread1(void* arg) {  
    sigset_t mask;  
    sigemptyset(&mask);  
    sigaddset(&mask, SIGUSR1);  
    pthread_sigmask(SIG_BLOCK, &mask, NULL); // Bloqueia SIGUSR1  
    while (1) sleep(1);  
    return NULL;  
}  

void sigusr1_handler(int sig) {  
    write(STDOUT_FILENO, "Sinal SIGUSR1 recebido na Thread 2!\n", 37);  
}  

void* thread2(void* arg) {  
    struct sigaction sa = {0};  
    sa.sa_handler = sigusr1_handler;  
    sigaction(SIGUSR1, &sa, NULL);  
    while (1) sleep(1);  
    return NULL;  
}  

int main() {  
    pthread_t t1, t2;  
    pthread_create(&t1, NULL, thread1, NULL);  
    pthread_create(&t2, NULL, thread2, NULL);  
    sleep(1);  
    pthread_kill(t2, SIGUSR1); // Envia sinal para a Thread 2  
    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);  
    return 0;  
}  
/*
Explicação:

    pthread_sigmask bloqueia sinais em threads específicas.

    pthread_kill envia um sinal para uma thread específica.
*/
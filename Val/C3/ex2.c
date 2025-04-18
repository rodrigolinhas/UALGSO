/*
Sinais e Threads

Descrição:
Escreva um programa que cria três threads. Cada thread imprime o seu ID a cada 2 segundos.

    O programa deve terminar imediatamente quando o usuário pressionar Ctrl+C (SIGINT).

    Todas as threads devem ser canceladas de forma segura.
    a) Implemente o tratamento do sinal SIGINT para encerrar o programa.
    b) Explique por que pthread_cancel pode não ser seguro e como melhorar o código.
*/
#include <stdio.h>  
#include <pthread.h>  
#include <signal.h>  
#include <unistd.h>  

volatile sig_atomic_t flag = 0;  

void sigint_handler(int sig) {  
    flag = 1;  // Sinaliza para as threads pararem  
}  

void* print_id(void *arg) {  
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);  // Desativa cancelamento  
    while (!flag) {  
        printf("Thread %ld\n", (long)arg);  
        sleep(2);  
    }  
    pthread_exit(NULL);  
}  

int main() {  
    signal(SIGINT, sigint_handler);  
    pthread_t t1, t2, t3;  

    pthread_create(&t1, NULL, print_id, (void*)1);  
    pthread_create(&t2, NULL, print_id, (void*)2);  
    pthread_create(&t3, NULL, print_id, (void*)3);  

    while (!flag);  // Espera até SIGINT  

    pthread_cancel(t1);  // Cancela as threads  
    pthread_cancel(t2);  
    pthread_cancel(t3);  

    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);  
    pthread_join(t3, NULL);  
    printf("Programa encerrado\n");  
    return 0;  
}  

/*
Explicação:

    Parte (a): Usamos volatile sig_atomic_t para sinalização segura entre threads e o handler de sinal.

    Parte (b): pthread_cancel pode deixar recursos alocados (ex: memória não liberada). 
    A solução desativa o cancelamento durante operações críticas e usa flag para encerramento limpo.
*/
/*
Produtor-Consumidor com Variáveis de Condição

Descrição:
Implemente uma fila de tamanho 5 usando um array global.

    A Thread Produtora gera números aleatórios (1 a 100) e os insere na fila.

    A Thread Consumidora remove os números e exibe a soma acumulada.
    Use mutexes e variáveis de condição para sincronizar as threads.
    a) Garanta que o produtor não insira dados se a fila estiver cheia.
    b) Garanta que o consumidor não processe dados se a fila estiver vazia.
*/
#include <stdio.h>  
#include <stdlib.h>  
#include <pthread.h>  

#define MAX 5  
int queue[MAX];  
int count = 0;  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t cond_prod = PTHREAD_COND_INITIALIZER;  
pthread_cond_t cond_cons = PTHREAD_COND_INITIALIZER;  

void* producer(void *arg) {  
    for (int i = 0; i < 10; i++) {  
        pthread_mutex_lock(&mutex);  
        while (count == MAX) {  
            pthread_cond_wait(&cond_prod, &mutex);  // Espera se a fila estiver cheia  
        }  
        int num = rand() % 100 + 1;  
        queue[count++] = num;  
        printf("Produzido: %d\n", num);  
        pthread_cond_signal(&cond_cons);  // Notifica consumidor  
        pthread_mutex_unlock(&mutex);  
    }  
    return NULL;  
}  

void* consumer(void *arg) {  
    int sum = 0;  
    for (int i = 0; i < 10; i++) {  
        pthread_mutex_lock(&mutex);  
        while (count == 0) {  
            pthread_cond_wait(&cond_cons, &mutex);  // Espera se a fila estiver vazia  
        }  
        sum += queue[--count];  
        printf("Soma: %d\n", sum);  
        pthread_cond_signal(&cond_prod);  // Notifica produtor  
        pthread_mutex_unlock(&mutex);  
    }  
    return NULL;  
}  

int main() {  
    pthread_t t1, t2;  
    pthread_create(&t1, NULL, producer, NULL);  
    pthread_create(&t2, NULL, consumer, NULL);  
    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);  
    return 0;  
}  
/*
Explicação:

    Variáveis de condição (cond_prod, cond_cons) são usadas para evitar busy waiting.

    O produtor espera se a fila estiver cheia (count == MAX), e o consumidor espera se vazia (count == 0).
*/
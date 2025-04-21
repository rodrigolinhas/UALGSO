/*
Sincronização com Mutexes

Descrição:
Crie um programa com duas threads que compartilham um contador global (int counter = 0).

    A Thread A incrementa o contador 1.000.000 vezes.

    A Thread B decrementa o contador 1.000.000 vezes.
    Ao final, exiba o valor do contador.
    a) Execute o programa sem sincronização.
    b) Modifique o código usando mutexes para garantir que o resultado final seja 0.
    c) Explique por que o resultado da parte (a) é inconsistente
*/

#include <stdio.h>  
#include <pthread.h>  

int counter = 0;  
pthread_mutex_t lock;  

void* increment(void *arg) {  
    for (int i = 0; i < 1000000; i++) {  
        pthread_mutex_lock(&lock);  // Bloqueia o mutex  
        counter++;  
        pthread_mutex_unlock(&lock);  
    }  
    return NULL;  
}  

void* decrement(void *arg) {  
    for (int i = 0; i < 1000000; i++) {  
        pthread_mutex_lock(&lock);  
        counter--;  
        pthread_mutex_unlock(&lock);  
    }  
    return NULL;  
}  

int main() {  
    pthread_t t1, t2;  
    pthread_mutex_init(&lock, NULL);  

    pthread_create(&t1, NULL, increment, NULL);  
    pthread_create(&t2, NULL, decrement, NULL);  

    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);  

    printf("Counter: %d\n", counter);  
    pthread_mutex_destroy(&lock);  
    return 0;  
}  

/*
Explicação:

    Parte (a): Sem mutex, ocorrem race conditions, pois as threads acessam counter simultaneamente. O resultado final não será 0.

    Parte (b): O mutex garante que apenas uma thread modifique counter por vez, evitando race conditions.

    Parte (c): Incrementos/decrementos não são atômicos. Operações como counter++ envolvem múltiplas instruções 
    (leitura, modificação, escrita), que podem ser interrompidas.
*/
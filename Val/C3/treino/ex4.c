/*
Deadlock Artificial

Descrição:
Crie um programa que provoca um deadlock intencional usando dois mutexes (mutex1 e mutex2).

    A Thread 1 trava mutex1 e depois tenta travar mutex2.

    A Thread 2 trava mutex2 e depois tenta travar mutex1.
    a) Execute o código e observe o comportamento.
    b) Modifique o código para evitar o deadlock (ex: ordem consistente de travar mutexes).
*/
#include <stdio.h>  
#include <pthread.h>  

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;  
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;  

void* thread1(void *arg) {  
    pthread_mutex_lock(&mutex1);  
    sleep(1);  // Força o deadlock  
    pthread_mutex_lock(&mutex2);  // Espera por mutex2 travado pela Thread 2  
    printf("Thread 1\n");  
    pthread_mutex_unlock(&mutex2);  
    pthread_mutex_unlock(&mutex1);  
    return NULL;  
}  

void* thread2(void *arg) {  
    pthread_mutex_lock(&mutex2);  
    sleep(1);  
    pthread_mutex_lock(&mutex1);  // Espera por mutex1 travado pela Thread 1  
    printf("Thread 2\n");  
    pthread_mutex_unlock(&mutex1);  
    pthread_mutex_unlock(&mutex2);  
    return NULL;  
}  

// Solução (b): Travar mutexes na mesma ordem  
void* fixed_thread(void *arg) {  
    pthread_mutex_lock(&mutex1);  
    pthread_mutex_lock(&mutex2);  
    printf("Thread segura\n");  
    pthread_mutex_unlock(&mutex2);  
    pthread_mutex_unlock(&mutex1);  
    return NULL;  
}  

int main() {  
    pthread_t t1, t2;  
    pthread_create(&t1, NULL, thread1, NULL);  
    pthread_create(&t2, NULL, thread2, NULL);  
    pthread_join(t1, NULL);  
    pthread_join(t2, NULL);  
    return 0;  
}  
/*
Explicação:

    Parte (a): As threads travam mutexes em ordem inversa, causando deadlock.

    Parte (b): A solução trava mutex1 e mutex2 sempre na mesma ordem, eliminando o ciclo de espera.
*/
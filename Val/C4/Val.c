/*
Descrição: mudar uma condicao
supor que os filisofos usam a mao dieria
não podem usar a mao esquerda 
antes de ter acesso a mao direita
1a parte analisar
2a parte implementar
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];

void *philosopher(void *num) {
    int i = *(int *)num;
    while (1) {
        printf("Filósofo nº %d pensando\n", i+1);
        sleep(1);
        printf("Filósofo nº %d tem fome\n", i+1);
        
        // Pega primeiro o garfo da direita
        sem_wait(&forks[i]);
        // Depois pega o garfo da esquerda
        sem_wait(&forks[(i+1)%N]);
        
        printf("Filósofo nº %d comendo\n", i+1);
        sleep(1);
        
        // Devolve primeiro o garfo da esquerda
        sem_post(&forks[(i+1)%N]);
        // Depois devolve o garfo da direita
        sem_post(&forks[i]);
        
        printf("Filósofo nº %d parou de comer\n", i+1);
    }
}

int main(void) {
    pthread_t thread_id[N];
    int i;
    int phil[N] = {0,1,2,3,4};

    for (i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    // Nunca chega aqui lol
    for (i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }
    return 0;
}

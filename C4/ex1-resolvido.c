#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10

sem_t sem_empty, sem_full, sem_mutex;
int buffer[N];
int in = 0, out = 0;

void *producer() {
    int i = 0;
    while (1) {
        sem_wait(&sem_empty);
        sem_wait(&sem_mutex);
        buffer[in] = i;
        printf("Produção: %d no buffer[%d]\n", i, in);
        in = (in + 1) % N;
        i++;
        sem_post(&sem_mutex);
        sem_post(&sem_full);
        sleep(1);
    }
}

void *consumer() {
    int item;
    while (1) {
        sem_wait(&sem_full);
        sem_wait(&sem_mutex);
        item = buffer[out];
        printf("Consumo: %d do buffer[%d]\n", item, out);
        out = (out + 1) % N;
        sem_post(&sem_mutex);
        sem_post(&sem_empty);
        sleep(2);
    }
    return NULL;
}

int main(void) {
    pthread_t prod, cons;
    sem_init(&sem_empty, 0, N);
    sem_init(&sem_full, 0, 0);
    sem_init(&sem_mutex, 0, 1);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    sem_destroy(&sem_empty);
    sem_destroy(&sem_full);
    sem_destroy(&sem_mutex);
    return 0;
}

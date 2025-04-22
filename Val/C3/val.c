/*
O nome amine como constante
2 threads
cada thread vai imprimir letras da palvra amine, até acabar a palavra
thread 1: a
thread 2: m
thread 1: i
thread 2: n
thread 1: e
mutex para não haver race condition
*/

#include <stdio.h>
#include <stdlib.h>  
#include <pthread.h>  
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

char *str = "amine";
int current_index = 0;
int len = 5;

pthread_mutex_t mutex;

void *thread1_func() {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (current_index >= len) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        if (current_index % 2 == 0) {
            printf("thread 1: %c\n", str[current_index]);
            current_index++;
sleep(1);
        }
        pthread_mutex_unlock(&mutex);
    }
}

void *thread2_func() {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (current_index >= len) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        if (current_index % 2 == 1) {
            printf("thread 2: %c\n", str[current_index]);
            current_index++;
sleep(1);
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void* fuel_filling(void* arg){
    for (int i = 0; i < 5; i++){
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("Filled fuel ... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

void* car(void*){
    pthread_mutex_unlock(&mutexFuel);
    while (fuel < 40){
        printf("No fuel, waiting ...\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel, driving ...");
    pthread_mutex_unlock(&mutexFuel);
}
 
//REVIEW
int main(int argc, char const *argv[])
{
    pthread_t thread[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    return 0;
}

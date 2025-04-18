/*
Duas threads manipulam uma variável global x.
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void* task1() {
    x += 5;
    sleep(2);
    printf("Value of x: %d\n", x);
   // printf("PID: %d\n", getpid());
}

void* task2() {
    sleep(2);
    printf("Value of x: %d\n", x);
  //  printf("PID: %d\n", getpid());
}

int main(int argc, char* argv[]) {
    pthread_t t[2];
    if (pthread_create(&t[0], NULL, &task1, NULL)) {
        return 1;
    }
    if (pthread_create(&t[1], NULL, &task2, NULL)) {
        return 2;
    }
    if (pthread_join(task1, NULL)) {
        return 3;
    }
    if (pthread_join(task2, NULL)) {
        return 3;
    }
    return 0;
}

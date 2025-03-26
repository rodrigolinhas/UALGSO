/**
 * @file  thread.c
 * @brief Criar 2 threads, 1 altera a variável x e imprime o valor de x e o PID.
 *        A outra thread imprime o valor de x e o PID.
 *        O programa principal cria as threads e espera que elas terminem.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int x = 2;

void* task1(){
    x = x + 5;
    //sleep(2);
    printf("x = %d\n", x);
    printf("PID: %d\n", getpid());
}

void* task2(){
    printf("x = %d\n", x);
    printf("PID: %d\n", getpid());
}

int main(int argc, char const *argv[]){
    pthread_t thread1, thread2;

    if (pthread_create(&thread1, NULL, &task1, NULL)){
        printf("Erro ao criar a thread 1\n");
        return 1;
    }
    if (pthread_create(&thread2, NULL, &task2, NULL)){
        printf("Erro ao criar a thread 2\n");
        return 1;
    }
    if (pthread_join(thread1, NULL)){
        printf("Erro ao esperar a thread 1\n");
        return 3;
    }
    if (pthread_join(thread2, NULL)){
        printf("Erro ao esperar a thread 2\n");
        return 4;
    }
    
    return 0;
}

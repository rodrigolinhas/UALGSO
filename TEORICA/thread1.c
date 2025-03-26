/**
 * @file thread1.c
 * @brief Criar 4 threads, 1 altera a variável x e imprime o valor de x.
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
    //printf("PID: %d\n", getpid());
}

int main(int argc, char const *argv[]){
    pthread_t thread[4];

    for (int i = 0; i < 4; i++){
        if (pthread_create(&thread[i], NULL, &task1, NULL) != 0){
            perror("Erro ao criar a thread");
        }
        printf("Thread: %d\n", i);
    }
    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(thread[i], NULL) != 0){
            perror("Erro ao juntar a thread");
        }
    }
    
    return 0;
}

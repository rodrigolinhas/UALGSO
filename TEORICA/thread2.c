
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg){
    int index = *(int*)arg;
    int sum = 0;
    for (int j = 0; j < 5; j++){
        sum += prime[index + j];
    }
    printf("Local sum: %d\n", sum);
    *(int*)arg = sum;
    return arg;
}
 
 int main(int argc, char const *argv[]){
     pthread_t thread[2];
 
     for (int i = 0; i < 2; i++){
        int* a = malloc(sizeof(int));
        *a = i * 5;
         if (pthread_create(&thread[i], NULL, &routine, a) != 0){
             perror("Erro ao criar a thread");
         }
         printf("Thread: %d\n", i);
     }
     for (int i = 0; i < 2; i++){
         if (pthread_join(thread[i], NULL) != 0){
             perror("Erro ao juntar a thread");
         }
     }
     
     return 0;
 }
 
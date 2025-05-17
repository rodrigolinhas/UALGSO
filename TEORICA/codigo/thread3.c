
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg){
    sleep(1);
    int index = *(int*)arg;
    printf("%d\n", prime[index]);
    free(arg);
}
 
int main(int argc, char const *argv[]){
    pthread_t thread[10];
    for (int i = 0; i < 10; i++){
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&thread[i], NULL, &routine, a) != 0){
            perror("Erro ao criar a thread");
        }
        //printf("Thread: %d\n", i);
    }
    for (int i = 0; i < 10; i++){
        if (pthread_join(thread[i], NULL) != 0){
            perror("Erro ao juntar a thread");
        }
    } 
    return 0;
 }
 
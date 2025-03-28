#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

const char* msg = "Mensagem da thread ";


void* thread_task(void* arg) {

    int thread_id = *(int*)arg;  // ID único da thread

    pthread_mutex_lock(&mutex);  // Bloqueia o mutex para imprimir sem interrupção
       
    for (int i = 0; msg[i] != '\0'; i++) {
        putchar(msg[i]);  // Imprime a mensagem letra por letra
        fflush(stdout);  // Garante que a saída seja impressa imediatamente
        sleep(1);
    }
    
    printf("%d\n", thread_id);      // Finaliza com o ID
    pthread_mutex_unlock(&mutex);  // Libera o mutex

    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Cria todas as threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if(pthread_create(&threads[i], NULL, thread_task, &thread_ids[i])!= 0)  {
            perror("Erro ao criar thread");
            return 1;
        }
    }

    // Aguarda todas as threads terminarem
    for (int i = 0; i < NUM_THREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            perror("Erro ao juntar thread");
            return 2;
        }
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void forkexample() {
    pid_t p;
    p = fork(); // Cria processo filho
    //error handler
    if(p < 0) {
        perror("fork fail");
        exit(1);
    }
    // Processo Filho
    else if ( p == 0) {
        sleep(10); // Dorme por 10 segundos
        printf("Hello from Child!\n"); // Imprime após acordar
    }
    // Processo Pai
    wait (NULL); // Espera o filho terminar
}

int main(void) {
    forkexample();
    return 0;
}
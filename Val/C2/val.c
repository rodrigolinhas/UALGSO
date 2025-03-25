/**
 * Criar 2 filhos a partir do pai
 * cada filho gera um numero random e manda ao pai
 * o pai faz a soma dos 2 numeros
 * imprime no ecrã o resultado
*/

#include <stdio.h> //printf
#include <stdlib.h> // malloc, exit
#include <string.h> // strlen
#include <errno.h> // erro handler
#include <sys/types.h> // pid_t
#include <sys/wait.h> // waitpid
#include <unistd.h> // fork, pipe, read, write, close
#include <fcntl.h>  //open
#include <time.h> //srand(time) (para gerar varias seeds no random)
#define R 0 //read pipe
#define W 1 //write pipe

int main(void) {
    int pipe1[2], pipe2[2];
    pid_t filho1, filho2;
    int numero1, numero2;
    pipe(pipe1);
    pipe(pipe2);

    filho1 = fork();
    if (filho1 == 0) {
        close(pipe1[R]);
        srand(time(NULL));
        int num = rand();
        write(pipe1[W], &num, sizeof(num));
        close(pipe1[W]);
        exit(0);
    }else{
        filho2 = fork();
        if (filho2 > 0) {
            close(pipe2[R]);
            srand(time(NULL));
            int num = rand();
            write(pipe2[W], &num, sizeof(num));
            close(pipe2[W]);
            exit(0);
        }

    }
    
    close(pipe1[W]);
    close(pipe2[W]);
    read(pipe1[R], &numero1, sizeof(numero1));
    printf("numero1: %d\n", numero1);
    read(pipe2[R], &numero2, sizeof(numero2));
    printf("numero2: %d\n", numero2);
    close(pipe1[R]);
    close(pipe2[R]);
    wait(filho1);
    wait(filho2);
    printf("Soma: %d\n", numero1 + numero2);
    return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main(void){
    pid_t p1, p2;
    p1 = fork();          // Primeiro fork: cria 2 processos
    printf("Hello\n");   // Ambos os processos (pai e p1) imprimem
    p2 = fork();        // Segundo fork: cada um dos 2 processos anteriores cria outro, totalizando 4
    printf("Hello\n"); // Todos os 4 processos imprimem
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t p = fork();    // Primeiro fork: cria 1 filho (total de 2 processos)
    if (p != 0) {       // Se for o pai
        fork();        // Cria outro filho (total de 3 processos)
    }
    printf("Hello world\n"); // Executado por todos os 3 processos
    return 0;
}
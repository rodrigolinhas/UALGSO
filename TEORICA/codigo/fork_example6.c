#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t p1 = fork(); // Primeiro fork: 2 processos
    pid_t p2 = fork(); // Segundo fork: 4 processos
    // Identifica cada processo baseado nos valores de p1 e p2:
    if (p1 == 0) { // Processos criados pelo primeiro fork (filhos)
        if (p2 == 0)    printf("process y\n"); // Neto (filho do filho)
        else            printf("process x\n"); // Filho direto
    } else { // Processo pai original
        if (p2 == 0)    printf("process z\n"); // Segundo filho do pai
        else            printf("am the parent process\n"); // Processo pai original
    }
    // Espera todos os processos filhos terminarem
    while (wait(NULL) != -1 || errno != ECHILD) {
       printf("Waited for a child to finish\n");
    }
    return 0;
}
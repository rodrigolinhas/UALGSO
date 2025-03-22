#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    //fork() cria 2^n processos
    fork();               // Primeiro fork: 2 processos
    fork();              // Segundo fork: 4 processos
    fork();             // Terceiro fork: 8 processos
    printf("hello\n"); // Todos os 8 processos executam esta linha
    return 0;
}
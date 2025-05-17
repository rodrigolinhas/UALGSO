#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t id = fork(); // Cria processo filho
    int n;
    
    // Processo Filho
    if (id == 0)    n = 1; // Imprimirá 1-5
    
    // Processo Pai
    else            n = 6; // Imprimirá 6-10
    
    // Apenas o pai espera
    if (id != 0)    wait(NULL); // Garante que o filho termine primeiro
    
    // Ambos os processos executam este loop:
    for (int i = n; i < n + 5; i++) {
        printf("%d ", i); // Saída ordenada: filho (1-5) primeiro, depois pai (6-10)
    }
    return 0;
}
/*
 * Objetivo: Demonstrar o uso de fork(), wait(), 
 * e a relação entre processos pai e filho, 
 * incluindo a espera por processos filhos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int id = fork(); // Cria um processo filho
    
    // Filho dorme por 1 segundo
    if (id == 0)    sleep(1); 
    
    // Ambos os processos imprimem seus IDs
    printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
    
    int res = wait(NULL); // Apenas o pai espera (filho não tem filhos)
    
    // Verifica se há processos filhos para esperar
    if (res == -1)  printf("No children to wait for\n"); // Filho imprime isto (pois wait falha)
    else            printf("%d finished execution\n", res); // Pai imprime o PID do filho
    return 0;
}
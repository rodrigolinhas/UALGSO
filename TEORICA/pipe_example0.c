/*Comunicação básica entre pai e filho via pipe, com entrada de dados.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int fd[2];
    if (pipe(fd) == -1) { // Cria pipe
        printf("Pipe error\n");
        return 1;
    }
    int id = fork(); // Cria filho
    if (id == -1) return 2;
    
    // Filho
    if (id == 0) {
        close(fd[0]); // Fecha leitura
        int x;
        printf("Input a number: ");
        scanf("%d", &x); // Lê entrada do usuário
        write(fd[1], &x, sizeof(int)); // Envia para o pai
        close(fd[1]);
    } else { // Pai
        close(fd[1]); // Fecha escrita
        int y;
        read(fd[0], &y, sizeof(int)); // Recebe do filho
        printf("Got from child: %d\n", y);
        printf("Result: %d\n", y * 3); // Processa dado
        close(fd[0]);
    }
    return 0;
}
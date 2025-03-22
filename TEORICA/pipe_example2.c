/*Enviar uma mensagem do filho para o pai via pipe.*/

#include <unistd.h> // fork, pipe, read, write, close
#include <stdio.h>
#include <string.h> // strlen
#define R 0
#define W 1

int main() {
    int fd[2];
    char message[100];
    pipe(fd); // Cria pipe
    
    if (fork() == 0) { // Filho
        close(fd[R]); // Fecha leitura
        write(fd[W], "msg sent to father from child", strlen("msg...")+1); // Escreve
        close(fd[W]);
    } else { // Pai
        close(fd[W]); // Fecha escrita
        int n = read(fd[R], message, 100); // Lê mensagem
        printf("Read %d octets: %s\n", n, message);
        close(fd[R]);
    }
    return 0;
}
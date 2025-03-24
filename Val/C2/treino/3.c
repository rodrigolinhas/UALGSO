/*
 * Crie um pipe. O processo pai envia a mensagem "Olá, filho!" 
 * para o filho via pipe. O filho lê a mensagem e a imprime.
 */

#include <stdio.h> //printf
#include <stdlib.h> // malloc, exit
#include <string.h> // strlen
#include <errno.h> // erro handler
#include <sys/types.h> // pid_t
#include <sys/wait.h> // waitpid
#include <unistd.h> // fork, pipe, read, write, close
#include <fcntl.h>  //open
//#include <time.h> //srand(time) (para gerar varias seeds no random)
#define R 0 //read pipe
#define W 1 //write pipe

int main(void) {
    int fd[2];
    char buffer[50];
    pid_t pid;

    // 1. Cria o pipe ANTES do fork()
    if (pipe(fd) == -1) {
        perror("Erro ao criar pipe");
        exit(EXIT_FAILURE);
    }

    // 2. Cria o processo filho
    pid = fork();

    if (pid == -1) { // Verifica erro no fork
        perror("Erro no fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Código do filho
        close(fd[W]); // Fecha extremo de escrita (não utilizado)
        
        // Lê do pipe e verifica erro
        ssize_t bytes_lidos = read(fd[R], buffer, sizeof(buffer));
        if (bytes_lidos == -1) {
            perror("Erro na leitura");
            exit(EXIT_FAILURE);
        }
        printf("Filho recebeu: %s\n", buffer);
        close(fd[R]); // Fecha extremo de leitura após uso
    } 
    else { // Código do pai
        close(fd[R]); // Fecha extremo de leitura (não utilizado)
        
        // Escreve no pipe e verifica erro
        const char *mensagem = "Olá, filho!";
        ssize_t bytes_escritos = write(fd[W], mensagem, strlen(mensagem) + 1); // +1 para incluir '\0'
        if (bytes_escritos == -1) {
            perror("Erro na escrita");
            exit(EXIT_FAILURE);
        }
        close(fd[W]); // Fecha extremo de escrita após uso
        
        // Espera o filho terminar e verifica erro
        if (wait(NULL) == -1) {
            perror("Erro no wait");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
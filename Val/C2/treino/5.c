/* Use pipe e fork para simular o comando ls | wc -l. 
 * O filho executa ls, redirecionando sua saída para o pipe. 
 * O pai lê do pipe e executa wc -l. */

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
#define W 1 //write pipeđ

int main(void) {
    int fd[2];
    pid_t pid;

    // Cria o pipe e verifica erro
    if (pipe(fd) == -1) {
        perror("Erro no pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("Erro no fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Filho (ls)
        close(fd[R]);          // Fecha leitura (não utilizado)
        dup2(fd[W], STDOUT_FILENO); // Redireciona stdout para o pipe (escrita)
        close(fd[W]);          // Fecha o descritor original após duplicação

        execlp("ls", "ls", NULL); 
        perror("Erro no execlp"); // Executa apenas se houver erro
        exit(EXIT_FAILURE);
    } 
    else { // Pai (wc -l)
        close(fd[W]);          // Fecha escrita (não utilizado)
        dup2(fd[R], STDIN_FILENO);  // Redireciona stdin para o pipe (leitura)
        close(fd[R]);          // Fecha o descritor original após duplicação

        wait(NULL);            // Espera o filho terminar (evita zombies)

        execlp("wc", "wc", "-l", NULL);
        perror("Erro no execlp");
        exit(EXIT_FAILURE);
    }

    return 0; // Nunca alcançado
}
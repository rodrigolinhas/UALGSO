#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#define READ 0
#define WRITE 1

int main(void) {
    int pipe_pai_filho[2];  // Pipe 1: pai -> filho (envia número)
    int pipe_filho_pai[2];  // Pipe 2: filho -> pai (envia resultado)
    
    // Criar os dois pipes
    if (pipe(pipe_pai_filho) == -1 || pipe(pipe_filho_pai) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    srand(time(NULL));  // Inicializa seed para números aleatórios

    // Processo Pai
    if (pid > 0) { 
        close(pipe_pai_filho[READ]);  // Fecha leitura do Pipe 1
        close(pipe_filho_pai[WRITE]);  // Fecha escrita do Pipe 2

        int numero = rand() % 11;  // Gera número entre 0-10
        
        // Envia número para o filho via Pipe 1
        write(pipe_pai_filho[WRITE], &numero, sizeof(numero));
        printf("Pai enviou: %d\n", numero);

        int resultado;
        // Recebe resultado do filho via Pipe 2
        read(pipe_filho_pai[READ], &resultado, sizeof(resultado));
        printf("Pai recebeu: %d\n", resultado);

        close(pipe_pai_filho[WRITE]);  // Fecha pipes restantes
        close(pipe_filho_pai[READ]);
    } 
    
    // Processo Filho
    else if (pid == 0) { 
        close(pipe_pai_filho[WRITE]);  // Fecha escrita do Pipe 1
        close(pipe_filho_pai[READ]);  // Fecha leitura do Pipe 2

        int recebido;
        // Lê número do pai via Pipe 1
        read(pipe_pai_filho[READ], &recebido, sizeof(recebido));
        printf("Filho recebeu: %d\n", recebido);

        int calculo = recebido * 4;  // Multiplica por 4
        
        // Envia resultado para o pai via Pipe 2
        write(pipe_filho_pai[WRITE], &calculo, sizeof(calculo));
        printf("Filho enviou: %d\n", calculo);

        close(pipe_pai_filho[READ]);  // Fecha pipes restantes
        close(pipe_filho_pai[WRITE]);
    } 
    // Erro no fork
    else { 
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
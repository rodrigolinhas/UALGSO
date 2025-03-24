/* Crie dois programas separados (server.c e client.c). 
 * Use FIFOs (named pipes) para comunicação:O servidor aguarda números no FIFO input_fifo.
 * Ao receber um número, multiplica-o por 10 e envia o resultado pelo FIFO output_fifo.
 * O cliente envia um número pelo input_fifo e imprime a resposta do output_fifo. 
 */

/////////////////////////server////////////////////////
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void) {
    mkfifo("input_fifo", 0666);
    mkfifo("output_fifo", 0666);

    int input_fd = open("input_fifo", O_RDONLY);
    int output_fd = open("output_fifo", O_WRONLY);

    int numero;
    while (1) {
        read(input_fd, &numero, sizeof(numero));
        printf("Servidor recebeu: %d\n", numero);
        int resultado = numero * 10;
        write(output_fd, &resultado, sizeof(resultado));
    }

    close(input_fd);
    close(output_fd);
    return 0;
}

/////////////////////client////////////////////////////
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
    int input_fd = open("input_fifo", O_WRONLY);
    int output_fd = open("output_fifo", O_RDONLY);

    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    write(input_fd, &numero, sizeof(numero));
    printf("Cliente enviou: %d\n", numero);

    int resultado;
    read(output_fd, &resultado, sizeof(resultado));
    printf("Resultado: %d\n", resultado);

    close(input_fd);
    close(output_fd);
    return 0;
}
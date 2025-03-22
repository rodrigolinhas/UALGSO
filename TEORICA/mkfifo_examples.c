/*Demonstrar comunicação via FIFO (pipe nomeado) entre processos.*/

////////////////////////////////////writer ///////////////////////
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main (void) {
    int fd;
    char message[26];
    sprintf(message, "Hello from writer [%d]\n", getpid()); // Formata mensagem
    fd = open("mytube", O_WRONLY); // Abre FIFO para escrita
    printf("here writer [%d] \n", getpid());
    if (fd != -1) {
        write(fd, message, strlen(message)); // Escreve no FIFO
    } else printf("Sorry not available\n");
    close(fd);
    system("ps"); // Mostra processos em execução
    return 0;
}

///////////// reader //////////////////////////////
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(void) {
    int fd, n;
    char input;
    fd = open("mytube", O_RDONLY); // Abre FIFO para leitura
    printf("Here reader [%d] \n", getpid());
    if(fd != -1) {
        printf("Received by reader :\n");
        while ((n = read(fd, &input, 1)) > 0) { // Lê byte a byte
            printf("%c ", input);
        }
        printf("Reader finish !\n");
    } else printf("Sorry not available\n");
    close(fd);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
// fd[0] -> usado para ler
// fd[1] -> usado para escrever
// Posso dar fflush(stdout) para garantir que a msg é exibida antes do wait

#define FIFO_CLIENT "fifo_client"
#define FIFO_SERVER "fifo_server"


int main(int argc, char* argv[])
{
    int num;
    int fdServer;
    int fdClient;
    mkfifo(FIFO_SERVER, 0666);
    mkfifo(FIFO_CLIENT, 0666);

    while(1)
    {
        printf("SERVER À ESPERA DE UM NUMERO...\n");
        fdServer = open(FIFO_SERVER, O_RDONLY);
        read(fdServer, &num, sizeof(num));
        close(fdServer);

        num*=10;
        printf("Servidor: enviando %d\n", num);
        fdClient = open(FIFO_CLIENT, O_WRONLY);
        write(fdClient, &num, sizeof(int));
        close(fdClient);
    }
    return 0;
}
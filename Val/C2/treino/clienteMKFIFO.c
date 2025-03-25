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

    if(access(FIFO_SERVER, F_OK) == -1)
    {
        printf("ERRO.\n");
        exit(1);
    }

    printf("PUT A NUMBER: ");
    scanf(" %d", &num);

    fdServer = open(FIFO_SERVER, O_WRONLY);
    write(fdServer, &num, sizeof(int));
    close(fdServer);

    fdClient = open(FIFO_CLIENT, O_RDONLY);
    read(fdClient, &num, sizeof(int));
    close(fdClient);

    printf("cliente: recebi %d\n", num);
    return 0;
}
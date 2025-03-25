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


int main(int argc, char* argv[])
{
    int fd[2];
    pipe(fd);
    char msg[] = "Fui escrito pelo processo pai\n";
    char buffer[50];
    pid_t pid = fork(); //SITIO ONDE SE FAZ O FORK IMPORTA

    
    
    if(pid == 0)  //se prof nao disser nada usar o filho para esrever no pipe
    {
        close(fd[0]); //fechar lado de leitura
        write(fd[1], msg, sizeof(msg)); //escrever
        printf("✅ MSG LIDA NO PIPE COM SUCESSO!\n"); // Imprimir sucesso antes de esperar
        close(fd[1]); //fechar lado de escrita
        wait(NULL);
    }
    else
    {
        close(fd[1]); //fechar lado de escrita
        read(fd[0], buffer, sizeof(buffer)); //ler
        close(fd[0]); //fechar lado de leitura
        printf("%s", buffer);
    }


    return 0;
}
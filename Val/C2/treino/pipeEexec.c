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
    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[0]); //fechar lado de leitura
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execlp("wc", "wc", "-l", NULL);
        //wait(NULL);
    }
    
    return 0;
}
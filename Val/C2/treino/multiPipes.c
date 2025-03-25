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
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (fork() == 0)
    {
        close(fd1[0]);
        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[1]);
        execlp("ls", "ls", NULL);
        exit(1);
    }

    if (fork() == 0)
    {
        close(fd1[1]);
        dup2(fd1[0], STDIN_FILENO);
        close(fd1[0]);
        close(fd2[0]);
        dup2(fd2[1], STDOUT_FILENO);
        close(fd2[1]);
        execlp("grep", "grep", ".c", NULL);
        exit(1);
    }

    close(fd1[0]);
    close(fd1[1]);
    close(fd2[1]);
    dup2(fd2[0], STDIN_FILENO);
    close(fd2[0]);
    execlp("cat", "cat", NULL);
    exit(1);
}
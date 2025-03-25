#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        printf("Ola, sou o son process\n");
    }
    else
    {
        wait(NULL);
        printf("Sou o processo pai e vou terminar o programa\n");
    }
    return 0;
}

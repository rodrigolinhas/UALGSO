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
    pid_t pid = fork();

    if (pid == 0)
    {
        execlp("ls", "ls", "-l", NULL);
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Processo pai a terminar tudo.\n");
    }

    return 0;
}
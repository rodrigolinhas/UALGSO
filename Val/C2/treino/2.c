#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid = fork();

    if (pid == 0)
    {
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        perror("erro execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
        printf("COMANDO EXECUTADO!\n");
    }

    return 0;
}
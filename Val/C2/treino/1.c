#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t id = fork();

    if (id == 0)
    {
        printf("PROCESSO FILHO, %d\n", getppid());
    }
    else
    {
        wait(NULL);
        printf("PROCESSO PAI, %d\n", id);
    }
    return 0;    
}
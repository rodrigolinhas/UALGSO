#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void forkexample()
{
    pid_t p;
    p = fork();
    if(p<0)
    {
      perror("fork fail");
      exit(1);
    }
    // child process because return value zero
    else if ( p == 0) {
        sleep (10);
        printf("Hello from Child!\n");
        }
        
 wait (NULL);
    // parent process because return value non-zero.
   // else
   //     printf("Hello from Parent!\n");
}
int main()
{
    forkexample();
    return 0;
}

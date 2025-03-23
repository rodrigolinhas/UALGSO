/* Crie um programa onde o processo pai gera um filho. 
 * O filho imprime "Processo filho" e seu PID. 
 * O pai imprime "Processo pai" e o PID do filho, aguardando seu término.
 */

#include <stdio.h> //printf
#include <stdlib.h> // malloc, exit
#include <string.h> // strlen
#include <errno.h> // erro handler
#include <sys/types.h> // pid_t
#include <sys/wait.h> // waitpid
#include <unistd.h> // fork, pipe, read, write, close
#include <fcntl.h>  //open
//#include <time.h> //srand(time) (para gerar varias seeds no random)
#define R 0 //read pipe
#define W 1 //write pipe

int main(void)
{
    pid_t pid = fork();
    if (pid == 0) printf("Processo filho <%d>\n",getpid());
    else{
        wait(NULL);
        printf("Processo Pai <%d>\n", pid);
    }
    return 0;
}

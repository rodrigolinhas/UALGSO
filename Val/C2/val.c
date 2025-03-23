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


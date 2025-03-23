#include <stdio.h> //printf
#include <stdlib.h> // mallor, exit
#include <string.h> // strlen
#include <errno.h> // erro handler
#include <sys/types.h> // pid_t
#include <sys/wait.h> // waitpid
#include <unistd.h> // fork, pipe, read, write, close
#include <fcntl.h>  //open, close
//#include <time.h>
#define R 0 //read pipe
#define W 1 //wirte pipe

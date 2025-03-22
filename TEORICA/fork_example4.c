#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int p1 = fork();
    int p2 = fork();
   printf("Hello world!, process_id(pid) = %d \n",getpid());
    return 0;
}

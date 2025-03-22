#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int p1 = fork(); // Primeiro fork: 2 processos
    int p2 = fork(); // Segundo fork: 4 processos
    printf("Hello world!, process_id(pid) = %d \n",getpid()); // Todos os 4 processos imprimem seu PID
    return 0;
}
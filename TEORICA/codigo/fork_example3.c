#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
void forkexample() {
    int x = 1;         // Variável local (cada processo terá sua cópia)
    pid_t p = fork(); // Cria processo filho
    //error handler
    if(p < 0) {
        perror("fork fail");
        exit(1);
    }
    // Processo Filho
    else if (p == 0)
        printf("Child has x = %d\n", ++x); // Incrementa x (x = 2)
    // Processo Pai
    else 
        printf("Parent has x = %d\n", --x); // Decrementa x (x = 0)
}

int main(void) {
    forkexample();
    return 0;
}
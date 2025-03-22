/*
 * Versão modularizada do exemplo anterior, separando exec1.c e exec2.c.
 * Funcionamento:
 * exec1.c: Programa simples que imprime uma mensagem.
 * exec2.c: Cria um filho, que executa exec1.c via execvp().
 */

///////////////exec1.c/////////////////////////////
#include<stdio.h>
#include<unistd.h>
 
int main() {
    printf("I am exec1.c called by execvp() \n");
    return 0;
}

/////////////////exec2.c///////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main() {
    pid_t p = fork(); 
    if (p == 0) { // Filho
        printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
        char *args[] = {"./exec1", NULL}; 
        execvp(args[0], args); // Substitui o processo por exec1
        printf("Esta linha NUNCA será executada!\n"); 
    }
    return 0;
}
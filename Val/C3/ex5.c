/*
Handler para SIGINT e SIGTERM

Descrição:
Escreva um programa que registra handlers para SIGINT (Ctrl+C) e SIGTERM.

    O handler de SIGINT imprime "Interrupção recebida" e termina o programa.

    O handler de SIGTERM imprime "Terminação solicitada" e termina o programa.
    O programa deve executar um loop infinito (while(1) sleep(1);).
*/
#include <stdio.h>  
#include <stdlib.h>  
#include <signal.h>  
#include <unistd.h>  

void sigint_handler(int sig) {  
    write(STDOUT_FILENO, "Interrupção recebida\n", 21);  
    exit(0);  
}  

void sigterm_handler(int sig) {  
    write(STDOUT_FILENO, "Terminação solicitada\n", 22);  
    exit(0);  
}  

int main() {  
    struct sigaction sa_int = {0}, sa_term = {0};  
    sa_int.sa_handler = sigint_handler;  
    sa_term.sa_handler = sigterm_handler;  

    sigaction(SIGINT, &sa_int, NULL);  
    sigaction(SIGTERM, &sa_term, NULL);  

    while (1) sleep(1);  
    return 0;  
}  
/*
Explicação:

    sigaction é usado para registrar os handlers.

    write é uma função async-signal-safe, adequada para handlers.

    O loop infinito mantém o programa em execução até receber um sinal.
*/
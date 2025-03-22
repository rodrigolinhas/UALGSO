/*
 * Objetivo: Criar uma hierarquia complexa 
 * de processos usando operadores lógicos e fork().
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    // Cria processos condicionalmente:
    // - Primeiro fork(): se for pai (retorno ≠ 0), executa segundo fork().
    // - Segundo fork(): apenas se o primeiro fork() retornar 0 (filho).
    if(fork() && (!fork())){
        // Dentro deste bloco: apenas processos que passaram nas condições anteriores
        if(fork() || fork()){ 
            fork(); // Cria mais um processo
        }
    }
	//wait(NULL);
	//wait(NULL);
	//wait(NULL);
    // Imprime PID e PPID (processo atual e pai)
    printf("%ld %ld\n", (long)getpid(), (long)getppid());
    exit(0);
}
// Saída: Vários PIDs, dependendo da hierarquia criada.
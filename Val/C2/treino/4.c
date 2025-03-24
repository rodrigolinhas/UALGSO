/* Crie três processos (pai → filho → neto). 
 * Cada um imprime seu PID e o PID do pai. 
 * Use wait para sincronizar a execução. 
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

int main(void){
    pid_t pid1 = fork();

    if (pid1 < 0) {
        perror("Erro no fork");
        return 1;
    } else if (pid1 == 0) { // Filho
        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("Erro no fork");
            return 1;
        } else if (pid2 == 0) { // Neto
            printf("Neto (PID: %d, PPID: %d)\n", getpid(), getppid());
        } else {
            wait(NULL);
            printf("Filho (PID: %d, PPID: %d)\n", getpid(), getppid());
        }
    } else { // Pai
        wait(NULL);
        printf("Pai (PID: %d)\n", getpid());
    }

    return 0;
}
#include <stdio.h>  
#include <unistd.h>  
#include <sys/wait.h>  

int main() {  
    pid_t pid = fork();  

    if (pid > 0) { // Pai  
        for (int i = 0; i < 3; i++)  
            printf("Eu sou o pai, minha identificação é %d\n", getpid());  
        wait(NULL);  
    } else if (pid == 0) { // Filho  
        for (int i = 0; i < 5; i++)  
            printf("Eu sou o filho, meu pai é %d\n", getppid());  
    }  
    return 0;  
}

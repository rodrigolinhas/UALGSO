#include <stdio.h>  
#include <unistd.h>  
#include <sys/wait.h>  

int main(void) {  
    int fd[2];  
    pipe(fd);  
    pid_t pid = fork();
    if (pid  == 0) {  
        dup2(fd[1], STDOUT_FILENO);  
        close(fd[0]);  
        execlp("echo", "echo", "Ola Hi", NULL);  
    } else {  
        dup2(fd[0], STDIN_FILENO);  
        close(fd[1]);  
        execlp("wc", "wc", NULL);  
    }  
    return 0;  
}  
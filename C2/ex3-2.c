#include <stdio.h>
#include <unistd.h>  
#include <sys/wait.h>  

int main() {  
    if (fork() == 0) execlp("who", "who", NULL);  
    if (fork() == 0) execlp("ps", "ps", NULL);  
    if (fork() == 0) execlp("ls", "ls", "-l", NULL);  
    while (wait(NULL) > 0);  
    return 0;  
}  
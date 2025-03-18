#include <stdio.h>  
#include <unistd.h>  
#include <string.h>  

int main(void) {  
    int fd[2];  
    pipe(fd);  
    char msg[] = "Hello, it’s me";  

    write(fd[1], msg, strlen(msg)+1);  
    close(fd[1]);  

    char buf[50];  
    read(fd[0], buf, sizeof(buf));  
    printf("String lida: %s\n", buf);  
    return 0;  
}

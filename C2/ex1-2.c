#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int a = 5;
    pid_t pid;
    
    //Pai
    if(pid = fork()){
        wait(&pid); //Vai esperar que o filho acabe SEM ALTERAÇÕES NOS DADOS
        printf("Valor de a = %d\n",a);
        printf("a = %p\n",&a);
    }
    else{
        //Filho
        a = 10;
        printf("Valor de a = %d\n",a);
        printf(" a = %p\n",&a);
    }
    exit(0); 
}
/*
 * Demonstrar a substituição de um processo filho por outro programa usando fork() e execvp().
 * Funcionamento:
 * O processo filho é criado com fork().
 * O filho imprime seus IDs de processo e pai.
 * execvp() substitui o código do filho pelo programa ./exec1 (que imprime uma mensagem fixa).
 * O printf() após execvp() nunca é executado, pois o processo foi substituído.
 */

#include<stdio.h>
#include<unistd.h>
 
int main(void)
{
    int i;
     
    printf("I am exec1.c called by execvp() ");
    printf("\n");
     
    return 0;
}
//////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main(void){
        //A null terminated array of character 
        //pointers
        pid_t p=fork(); // Cria processo filho
        if (p == 0){    // Código do filho
        printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
        printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
        char *args[]={"./exec1",NULL}; // Argumentos para execvp()
        execvp(args[0],args); // Substitui o processo pelo exec1
        // As linhas abaixo NUNCA são executadas:
        printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
         }
       
     
        /*All statements are ignored after execvp() call as this whole 
        process(execDemo.c) is replaced by another process (EXEC.c)
        */
    return 0;
}

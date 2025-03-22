/*Exemplo básico de fork*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(void){
    pid_t p1, p2;
    p1 = fork(); // Primeiro fork: 2 processos
    printf("Hello\n"); // Executado por ambos
    p2 = fork(); // Segundo fork: 4 processos
    printf("Hello\n"); // Executado por todos
}
// Saída: 4 "Hello" no total.

/////////////////////////////////////////////
/*Três forks (8 processos)*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
    fork(); // 2 processos
    fork(); // 4 processos
    fork(); // 8 processos
    printf("hello\n"); // Todos imprimem
    return 0;
}
/////////////////////////////////////////////
/*Sincronização com wait*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void forkexample() {
    pid_t p = fork();
    if(p < 0) exit(1);
    else if (p == 0) {
        sleep(10); // Filho dorme 10s
        printf("Hello from Child!\n");
    }
    else wait(NULL); // Pai espera o filho
}
int main(void) {
    forkexample();
    return 0;
}
/////////////////////////////////////////////
/*Variáveis independentes entre processos*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample() {
    int x = 1;
    pid_t p = fork();
    if(p < 0) exit(1);
    else if (p == 0)    printf("Child x = %d\n", ++x); // x = 2
    else                printf("Parent x = %d\n", --x); // x = 0
}
int main(void) {
    forkexample();
    return 0;
}
/////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int p1 = fork();
    int p2 = fork();
   printf("Hello world!, process_id(pid) = %d \n",getpid());
    return 0;
}
/////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t p = fork();
    if (p != 0) {
        fork();
    }
    
    printf("Hello world\n");
    
    return 0;
}
/////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t p1 = fork();
    pid_t p2 = fork();
    if (p1 == 0) {
        if (p2 == 0) {
            printf("process y\n");
        } else {
            printf("process x\n");
        }
    } else {
        if (p2 == 0) {
            printf("process z\n");
        } else {
            printf("am the parent process\n");
        }
    }
    while (wait(NULL) != -1 || errno != ECHILD) {
       printf("Waited for a child to finish\n");
    }

    return 0;
}
/////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    pid_t id = fork();
    int n;
    if (id == 0) {
        n = 1;
    } else {
        n = 6;
    }
    
    if (id != 0){
        wait(NULL);
    }
    int i;
    for (i = n; i < n + 5; i++) {
        printf("%d ", i);
    }
  
    return 0;
}
/////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int id = fork();
    if (id == 0) {
        sleep(1);
    }
    printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
    
    int res = wait(NULL);
    
    if (res == -1) {
        printf("No children to wait for\n");
    } else {
        printf("%d finished execution\n", res);
    }
    return 0;
}

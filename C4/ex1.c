#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void) {
    int pid;
    int i=0;
    pid = fork();
    switch(pid) {
        case -1: printf("Error fork()\n"); 
            return -1; 
        case 0: printf("Proc P.\n");
            while(1) {
                printf("Production .%d\n", i);
                i++;
                printf("Object to buffer.\n");
                sleep(10);
            }
            break;
        default: printf("Proc. C.\n");
            while(1) {printf("Object from buffer.\n");
                printf("Cons. objet.%d\n", i);
                i--;
                sleep(20);
                }
            break;
    }
    return 0;
}
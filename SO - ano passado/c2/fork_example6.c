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

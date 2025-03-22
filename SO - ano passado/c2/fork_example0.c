#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(){
pid_t p1, p2;
p1 = fork();
printf("Hello\n");
p2 = fork();
printf("Hello\n");
}

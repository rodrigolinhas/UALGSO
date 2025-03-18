#include <unistd.h> // fork, pipe, read, write, close
#include <stdio.h>
#include <string.h> // strlen
#define R 0
#define W 1
int main ()
{
int fd [2];
char message [100]; 
int nboctets;
char *msg = "msg sent to father from child";
pipe (fd); 
if (fork() == 0) 
{
close (fd[R]);
write (fd[W], msg, strlen(msg)+1);
close (fd[W]);
}
else
{
close (fd[W]) ;

nboctets=read(fd[R], message, 100);
printf("Read %d octets :%s\n", nboctets, message);
close (fd[R]);
}
return 0;
}


////////////////////////////////////writer ///////////////////////
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int main (void)
{
int fd;
char message [26];
printf (message,"Hello from writer [%d]\n",getpid());
fd=open( "mytube",O_WRONLY);
printf("here writer [%d] \n",getpid());
if (fd!=-1) {
write(fd, message,strlen(message));
}
else
printf("Sorry not available\n");
close (fd);
system("ps");
return 0;
}
///////////// reader //////////////////////////////
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main ( )
{
int fd,n;
char input;
fd=open("mytube",O_RDONLY);
printf("Here reader [%d] \n" ,getpid());
if(fd !=-1 ) {
printf ("Received by reader :\n");
while ((n=read(fd,&input,1))>0) {
printf("%c ",input);
}
printf("Reader finish !\n",n);
}
else
printf("Sorry not available\n");
close(fd);
return 0;
}


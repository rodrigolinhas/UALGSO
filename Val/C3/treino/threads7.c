/*
Cria threads sequencialmente (com pthread_join dentro do loop), perdendo paralelismo.
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5
void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
  //pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    pthread_join(threads[t], NULL);
     if (rc){
printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
       }
     }
   /* Last thing that main() should do */
   //pthread_exit(NULL);
   return 0;
}
//gcc -Wall thread-ex.c -DNUM_THREADS=10 -o hello -pthread

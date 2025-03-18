#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS	6
void *Printa(void *threadid)
{
   int a=5;
   a++;
   printf("Valor de a = %d\n",a);
   long tid;
   tid = (long)threadid;
   printf("It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}
void *Printaa(void *threadid)
{
  int a;
  a--;
  printf("Valor de a = %d\n",a);
  long tid;
  tid = (long)threadid;
  printf("It's me, thread #%ld!\n", tid);
  pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int a=5;
   printf("Valor de a = %d\n",a);
   int rc;
   long t;
   for(t=0;t<3;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, Printa, (void *)t);
     pthread_join(threads[t], NULL);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }
     for(t=3;t<6;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, Printaa, (void *)t);
     pthread_join(threads[t], NULL);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
       }
     }
   
      pthread_exit(NULL);
   return 0;
   
}

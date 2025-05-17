#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task() {
    printf("Hello from threads\n");
    sleep(3);
    printf("Ending thread\n");
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2;
    if (pthread_create(&p1, NULL, &task, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &task, NULL) != 0) {
        return 2;
    }
    //if (pthread_join(p1, NULL) != 0) {
        //return 3;
    //}
    //if (pthread_join(p2, NULL) != 0) {
      // return 4;
   //}
    return 0;
}
/////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task() {
    printf("Hello from threads\n");
    sleep(3);
    printf("Ending thread\n");
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2;
    if (pthread_create(&p1, NULL, &task, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &task, NULL) != 0) {
        return 2;
    }
    //if (pthread_join(p1, NULL) != 0) {
        //return 3;
    //}
    //if (pthread_join(p2, NULL) != 0) {
      // return 4;
   //}
    return 0;
}
/////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void* task1() {
    x += 5;
    sleep(2);
    printf("Value of x: %d\n", x);
    //printf("PID: %d\n", getpid());
}
int main(int argc, char* argv[]) {
    pthread_t th[4];
    for (int i = 0; i < 4; i++) {
            if (pthread_create(&th[i], NULL, &task1, NULL) != 0) {
                perror("Failed to create thread");
            }
           
    printf("Th: %d\n", i);
}
    for (int i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
        }
    return 0;
}
////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void* routine(void* arg) {
    sleep(1);
    int index = *(int*)arg;
    printf("%d ", primes[index]);
    free(arg);
}

int main(int argc, char* argv[]) {
    pthread_t th[10];
    int i;
    for (i = 0; i < 10; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to created thread");
        }
    }
    for (i = 0; i < 10; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    
    return 0;
}
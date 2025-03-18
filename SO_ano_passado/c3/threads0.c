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
    if (pthread_join(p1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(p2, NULL) != 0) {
       return 4;
   }
    return 0;
}

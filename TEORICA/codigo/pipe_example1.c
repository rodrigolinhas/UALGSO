/*Calcular a soma de um array em paralelo usando dois processos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
    int arrSize = sizeof(arr)/sizeof(int);
    int start, end;
    int fd[2];
    if (pipe(fd) == -1) return 1;
    
    int id = fork(); // Divide o trabalho
    if (id == 0) { start = 0; end = arrSize/2; } // Filho: primeira metade
    else { start = arrSize/2; end = arrSize; } // Pai: segunda metade
    
    int sum = 0;
    for (int i = start; i < end; i++) sum += arr[i];
    printf("Partial sum: %d\n", sum);
    
    if (id == 0) { // Filho envia soma ao pai
        close(fd[0]);
        write(fd[1], &sum, sizeof(int));
        close(fd[1]);
    } else { // Pai recebe e calcula total
        int sumFromChild;
        close(fd[1]);
        read(fd[0], &sumFromChild, sizeof(int));
        printf("Total sum: %d\n", sum + sumFromChild);
        wait(NULL);
    }
    return 0;
}
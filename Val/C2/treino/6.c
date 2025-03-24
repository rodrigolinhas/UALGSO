/* Crie dois pipes. 
 * O pai envia uma mensagem para o filho, que responde com "Recebido!". 
 * Ambos os processos imprimem as mensagens trocadas. 
 */

 #include <stdio.h> //printf
 #include <stdlib.h> // malloc, exit
 #include <string.h> // strlen
 #include <errno.h> // erro handler
 #include <sys/types.h> // pid_t
 #include <sys/wait.h> // waitpid
 #include <unistd.h> // fork, pipe, read, write, close
 #include <fcntl.h>  //open
//#include <time.h> //srand(time) (para gerar varias seeds no random)
 #define R 0 //read pipe
 #define W 1 //write pipeđ
 
 int main(void) {
   int parent_to_child[2], child_to_parent[2];
   pipe(parent_to_child);
   pipe(child_to_parent);
 
   pid_t pid = fork();
 
   if (pid == 0) { // Filho
     close(parent_to_child[W]); // Fecha escrita do pai → filho
     close(child_to_parent[R]); // Fecha leitura do filho → pai
 
     char buffer[50];
     read(parent_to_child[R], buffer, sizeof(buffer));
     printf("Filho leu: %s\n", buffer);
 
     write(child_to_parent[W], "Recebido!", 10);
     close(parent_to_child[R]);
     close(child_to_parent[W]);
   } else { // Pai
     close(parent_to_child[R]); // Fecha leitura do pai → filho
     close(child_to_parent[W]); // Fecha escrita do filho → pai
 
     write(parent_to_child[W], "Mensagem do pai", 16);
     wait(NULL);
 
     char buffer[50];
     read(child_to_parent[R], buffer, sizeof(buffer));
     printf("Pai leu: %s\n", buffer);
 
     close(parent_to_child[W]);
     close(child_to_parent[R]);
   }
 
   return 0;
 }
#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
  
int main(void) 
{ 
    // open() returns a file descriptor file_desc to a  
    // the file "dup.txt" here" 
    // Abre o arquivo "dup1.txt" em modo de escrita e append (adiciona ao final)
    int file_desc = open("dup1.txt", O_WRONLY | O_APPEND); 
    
    //error handler
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
      
    // dup() will create the copy of file_desc as the copy_desc 
    // then both can be used interchangeably. 
    // Duplica o descritor de arquivo: copy_desc e file_desc referenciam o mesmo arquivo
    int copy_desc = dup(file_desc); 
          
    // write() will write the given string into the file 
    // referred by the file descriptors 
    // Escreve no arquivo usando o descritor duplicado (copy_desc)
    write(copy_desc,"This will be output to the file named dup.txt\n", 46);       
    
    // Escreve novamente usando o descritor original (file_desc) 
    write(file_desc,"This will also be output to the file named dup.txt\n", 51); 
      
    return 0; 
}
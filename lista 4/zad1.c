#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PIPESIZE 16

int main() {     

    char text[PIPESIZE];
    int p[2]; 

  
    if (pipe(p) < 0) {
        printf("blad pipe");
        exit(1); 
        }
    if (fork() == 0) {
        printf("Child\n"); 
        while(read(p[0], text, PIPESIZE) != 0){
            write(1, text, PIPESIZE);
        }
        }
        else{
        int file;
        
        file = open("tekst.txt", O_RDONLY);
        printf("Parent\n");
        while(read(file, text, PIPESIZE) != 0){
            write(p[1],text , PIPESIZE); 
        }close(file);
        }
    return 0; 
} 


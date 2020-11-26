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
        int picture;
        
        picture = open("display.png", O_CREAT | O_RDWR);
        printf("Child\n"); 
        while(read(p[0], text, PIPESIZE) != 0){
            write(picture, text , PIPESIZE); 
        }
        
        close(picture);

        }
    else{
        int file;
        
        file = open("obraz.png", O_RDONLY);
        printf("Parent\n");
        while(read(file, text, PIPESIZE) != 0){
            write(p[1],text , PIPESIZE); 
        }close(file);
        }
        
        if(chmod("display.png", S_IRWXU) != 0)
        printf("blad zamianyuprawnien");
        execl("/bin/display", "/bin/display", "display.png",  NULL);
        
        
    return 0; 
} 

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int menu=1, fileread, filewrite;
  struct stat filestat;
  void *wsk=NULL;
  char file[10]; // do zadania uzylem plikow o nazwach 1.txt 2.txt 3.txt plikiem zmapowanym byl plik map.txt

  while(menu != 0){
    printf("podaj nazwe pliku, 0 zakancza prace programu\n");
    scanf("%s" , file);
    if(file[0] == '0'){
      menu=0;
    }else{
      if((fileread = open(file, O_RDONLY)) == -1)
        printf("bledna nazwa pliku\n");
      else{
        stat(file, &filestat);
        filewrite = open("map.txt", O_RDWR);
        truncate("map.txt", filestat.st_size);
        wsk = mmap(0, filestat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, filewrite, 0);
        read(fileread, wsk, filestat.st_size);
        close(fileread);
        close(filewrite);
        munmap(wsk, filestat.st_size);
      }
    }
  }

  return 0;
}

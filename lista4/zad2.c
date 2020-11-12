#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <time.h>
#include <ucontext.h>

void handle_sigalrm(int sig){
    printf("SIGALRM exit \n");
    exit(0);
}

void handle_sigterm(int sig){
    printf("SIGTERM return \n");
}

void handle_sigusr1(int sig){
    printf("SIGUSR1 ignore \n");
    
}



int main(){
    //int issig=0;
    //int counter = 0;
    
    signal(SIGALRM, handle_sigalrm);
    signal(SIGTERM, handle_sigterm);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, SIG_IGN);
    while(1){
        printf("dsfrgtdg \n");
    
        sleep(1);
    }
    return 0;
}


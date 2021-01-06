#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#define NTHREADS	8

void *Hello(void *threadid)
{
   printf("Hello SCR. Written by thread %ld\n", threadid);
   pthread_exit(NULL);
}

int main()
{
pthread_t threads[NTHREADS];
int rc;
long t;
for(t=0;t<NTHREADS;t++){
  rc = pthread_create(&threads[t], NULL, Hello, (void *)t);
  if (rc){
    printf("ERROR: return code from pthread_create() is %d\n", rc);
    printf("Code %d= %s\n",rc,strerror(rc));
    exit(-1);
    }
   }
pthread_exit(NULL);
}

#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
 void *shared_memory;
 char buff[100];
 int shmid;
 shmid=shmget((key_t)1222,1024,066);
 printf("Key of the shared memory is %d",shmid);
 shared_memory=shmat(shmid,NULL,0);
 printf("\nProcess attached at %p",shared_memory);
 printf("\nData read from shared memory is \n %s",(char *)shared_memory);
 return 0;
}

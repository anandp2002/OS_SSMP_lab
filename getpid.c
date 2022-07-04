#include <stdio.h>
#include<unistd.h>
int main()
{
 int getpid();
 int pid ;
 pid = getpid();
 printf("Process id is %d \n",pid);
 pid=getppid();
 printf("Parent Process id is %d \n",pid);
}

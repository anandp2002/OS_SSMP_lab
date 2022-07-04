#include<stdio.h>
#include<sys/stat.h>
int main()
{
   struct stat sfile;
   stat("getpid.c",&sfile);
   printf("    File mode    = %d",sfile.st_mode);
   printf("\n    File user id = %d",sfile.st_uid);
   printf("\n    File size    = %ld",sfile.st_size);
   printf("\nLast access time = %ld",sfile.st_atime);
   printf("\n      Block size = %ld",sfile.st_blocks);
   printf("\n     No of links = %ld\n",sfile.st_nlink);
   return 0;
}


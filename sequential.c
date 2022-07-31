#include<stdio.h>
#include<string.h>

int main()
{
  int n,i,j,flag=0,fsize[20],bsize[20],sblock[20],nb[20];
  char name[20][20],s[20],s2[20];
  printf("Enter the no of files : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\nEnter the name of file %d : ",i+1);
    scanf("%s",name[i]);
    printf("\nEnter the size(in kb) of file %d : ",i+1);
    scanf("%d",&fsize[i]);
    printf("\nEnter the block size(in bytes) of file %d : ",i+1);
    scanf("%d",&bsize[i]);
    printf("\nEnter the starting block of file %d : ",i+1);
    scanf("%d",&sblock[i]);
    nb[i]=(fsize[i]*1024)/bsize[i];
  }
  while(flag==0)
  {
  printf("\nEnter the file name to be allocated : ");
  scanf("%s",s);
  for(i=0;i<n;i++)
  {
    if(strcmp(s,name[i])==0)
    break;
  }
  printf("\nFile Name\tS.Block\tNo.Blocks\tBlocks\n");
  printf("\n%s\t%d\t%d\t",name[i],sblock[i],nb[i]);
  for(j=0;j<nb[i];j++)
  {
   printf("%d->",sblock[i]+j);
  }
  printf("Do you want to Continue:\n(y/n)");
  scanf("%s",s2);
  if((strcmp(s2,"n")==0))
  {
   flag=1;
  }
  }
}

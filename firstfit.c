#include<stdio.h>
int main()
{
  int bsize[50],psize[50],j,i,bn,pn,allocation[50];
  for(i=0;i<50;i++)
  {
    allocation[i]=-1;
  }
  printf("Enter the no of blocks : ");
  scanf("%d",&bn);
  printf("Enter the block size of \n");
  for(i=0;i<bn;i++)
  {
    printf("\tBlock %d : ",i);
    scanf("%d",&bsize[i]);
  }
  printf("Enter the no of processes : ");
  scanf("%d",&pn);
  printf("Enter the process size of \n");
  for(i=0;i<pn;i++)
  {
    printf("\tProcess %d : ",i);
    scanf("%d",&psize[i]);
  }
  for(i=0;i<pn;i++)
  {
    for(j=0;j<bn;j++)
    {
      if(bsize[j]>=psize[i])
      {
        allocation[i]=j;
        bsize[j]-=psize[i];
        break;
      }
     }
    }
  
  printf("\nP.No\tP.size\tB.No\n");
  for(i=0;i<pn;i++)
  {
    printf("%d\t%d\t",i,psize[i]);
    if(allocation[i]!=-1)
     printf("%d\n",allocation[i]);
    else
     printf("Not allocated\n");
  }
}

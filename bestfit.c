#include<stdio.h>
int main()
{
  int bsize[50],psize[50],n1[20],j,i,bn,pn,allocation[50],temp,temp1,no[50],blockno[23];
  for(i=0;i<50;i++)
  {
    n1[i]=-1;
  }
  printf("Enter the no of blocks : ");
  scanf("%d",&bn);
  for(i=0;i<bn;i++)
  {
    no[i]=i;
    
  }
  printf("Enter the block size of \n");
  for(i=0;i<bn;i++)
  {
    printf("\tBlock %d : ",i);
    scanf("%d",&bsize[i]);
  }
  for(i=0;i<bn-1;i++)
  {
    for(j=0;j<bn-i-1;j++)
    {
      if(bsize[j]>bsize[j+1])
      {
        temp=bsize[j];
        bsize[j]=bsize[j+1];
        bsize[j+1]=temp;
        
        temp1=no[j];
        no[j]=no[j+1];
        no[j+1]=temp1;
      }
    }
  }
  printf("Blocks in sorted order is : ");
  for(i=0;i<bn;i++)
  {
    printf("%d ",bsize[i]);
    
  }
  printf("\n");
  printf("Block no in sortd order : ");
  for(i=0;i<bn;i++)
  {
    printf("%d ",no[i]);
  }
  printf("\nEnter the no of processes : ");
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
      if(psize[i]<=bsize[j])
      {if(bsize[j]!=-1){
        n1[i]=no[j];
        bsize[j]=-1;
        break;
      }}
    }
  }
  printf("\n\tBEST FIT");
  printf("\nP.NO\tP.SIZE\tB.NO\n");
  for(i=0;i<pn;i++)
  {
  if(n1[i]!=-1)
   printf("%d\t%d\t%d\n",i,psize[i],n1[i]);
  else
   printf("%d\t%d\tNot allocated\n",i,psize[i]);
  } 
}

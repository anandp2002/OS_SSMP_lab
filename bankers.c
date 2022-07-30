#include<stdio.h>
int main()
{
  int r,i,k,inst[50],n,alloc[10][10],j,max[10][10],count=0,need[10][10],total=0,avail[10],finish[10],flag,safe[10];
  printf("Enter the no of resources : ");
  scanf("%d",&r);
  printf("\nEnter the max instance of each resources\n");
  for(i=0;i<r;i++)
  {
    printf("\t%c = ",(i+97));
    scanf("%d",&inst[i]);
    total+=i;
  }
  printf("Enter the no of processes : ");
  scanf("%d",&n);
  printf("Enter the allocation matrix \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&alloc[i][j]);
    }
  }
  printf("Enter the max matrix \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&max[i][j]);
    }
  }
  printf("The need matrix is \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<r;j++)
    {
      need[i][j]=max[i][j]-alloc[i][j];
      printf("%d\t",need[i][j]);
    }
    printf("\n");
  }
  printf("First row of available matrix = ");
  //work = First row of available matrix
  for(i=0;i<r;i++)
  {
   avail[i]=inst[i];
   for(j=0;j<n;j++)
   {
    avail[i]=avail[i]-alloc[j][i];
   }
   printf("%d ",avail[i]);
  }
  for(i=0;i<n;i++)
  {
   finish[i]=-1;
  }
  
  //SAFETY ALGORITHM
  
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    flag=0;
    if(finish[j]==-1)
    {
      for(k=0;k<r;k++)
      {
       if(need[j][k]>avail[k])
       {
        flag=1;
        break;
       }
      }
      if(flag==0)
      {
       for(k=0;k<r;k++)
       {
        avail[k]=avail[k]+alloc[j][k];
       }
       safe[count]=j;
       count++;
       finish[j]=0;
      }
    }
   }
  }
  printf("\nThe safe sequence is  <  ");
   for(i=0;i<n;i++)
   {
    printf("p[%d]  ",safe[i]);
   }
   printf(">");   
}






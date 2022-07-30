#include<stdio.h>
int main()
{
  int n,i,rs[10],flag,f,frame[10],fi=0,k,hit=0,pf=0,j;
  printf("Enter the length of reference string : ");
  scanf("%d",&n);
  printf("Enter the reference string : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&rs[i]);
  }
  printf("Enter the no of frames : ");
  scanf("%d",&f);
  for(i=0;i<f;i++)
  {
    frame[i]=-1;
  }
  printf("\nRef.Frame\tPage frames\n");
  for(i=0;i<n;i++)
  {
    flag=0;
    for(j=0;j<f;j++)
    {
      if(rs[i]==frame[j])
      {
        hit++;
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
      frame[fi]=rs[i];
      fi=(fi+1)%f;
      pf++;
    }
    printf("    %d    \t",rs[i]);
    for(j=0;j<f;j++)
    {
      printf(" %d  ",frame[j]);
    }
    printf("\n");
  }
  printf("Page Hit   = %d\n",hit);
  printf("Page fault = %d",pf);
 }






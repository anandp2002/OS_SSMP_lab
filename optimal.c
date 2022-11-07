#include<stdio.h>
void main()
{
 int n,i,j,rs[30],f,frame[30],hit=0,k,miss=0,temp3,flag,flag2,temp2,pos[30];
 printf("enter the length of reference string\n");
 scanf("%d",&n);
 printf("Enter the reference string\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&rs[i]);
 }
 printf("Enter the no of frames\n");
 scanf("%d",&f);
 int temp[f];
 for(i=0;i<f;i++)
 {
  frame[i]=-1;
  temp[i]=100;
  pos[i]=i;
 }
 printf("ref string\tframe\n");
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
   flag2=0;
   for(j=0;j<f;j++)
   {
    if(frame[j]==-1)
    {
     frame[j]=rs[i];
     flag2=1;
     break;
    }
   }
   if(flag2==0)
   {
    for(j=0;j<f;j++)
    {
     temp[j]=100;
    }
    for(j=0;j<f;j++)
    {
     for(k=i+1;k<n;k++)
     {
      if(frame[j]==rs[k])
      {
       temp[j]=k;
       break;
      }
     }
    }
    for(j=0;j<f;j++)
    {
     pos[j]=j;
    }
    for(j=0;j<f-1;j++)
    {
     for(k=0;k<f-j-1;k++)
     {
      if(temp[k]>temp[k+1])
      {
       temp2=temp[k];
       temp[k]=temp[k+1];
       temp[k+1]=temp2;
       
       temp3=pos[k];
       pos[k]=pos[k+1];
       pos[k+1]=temp3;
      }
     }     
    }
    frame[pos[f-1]]=rs[i];
   }
   miss++;
  }
  printf("  %d ",rs[i]);
  for(j=0;j<f;j++)
  {
   printf(" %d ",frame[j]);
  }
  printf("\n");
  
 }
 printf("Hit = %d\n",hit);
 printf("Miss = %d\n",miss);
}

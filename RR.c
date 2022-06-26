#include<stdio.h>
int main()
{
 int n,b[50],i,q,bs=0,t=0,tat[50],wt[50],b2[50],tt=0;
 printf("Enter the no of processes :\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the burst time for process %d : ",i);
  scanf("%d",&b[i]);
  b2[i]=b[i];
  bs+=b[i];
  tat[i]=0;
 }
 printf("Enter the quantum time : \n");
 scanf("%d",&q);
 i=0;
 while(tt<bs)
 {
  if(b2[i]==0)
  {
   i=(i+1)%n; 
  }
  else if(b2[i]>q)
  {
   tat[i]=tt+q;
   tt=tat[i];
   b2[i]=b2[i]-q;
   i=(i+1)%n;
  }
  else
  {
   tat[i]=tt+b2[i];
   tt=tat[i];
   b2[i]=0;
   i=(i+1)%n;
  }
 }
 for(i=0;i<n;i++)
 {
  wt[i]=tat[i]-b[i];
 }
 printf("\nprocess\t\tburst time\t\tTurn around time\t\tWaitng time\n");
 for(i=0;i<n;i++)
 {
  printf("   %d   \t\t     %d    \t\t      %d        \t\t     %d    \n",i,b[i],tat[i],wt[i]);
 }
 int avgtat=0,avgwt=0;
 for(i=0;i<n;i++)
 {
  avgtat=avgtat+(tat[i]);
  avgwt=avgwt+(wt[i]);
 }
 printf("Average tat =%d",avgtat/n);
 printf("Average wt=%d",avgwt/n);
}

#include<stdio.h>
int main()
{
 int n,b[50],i;
 printf("Enter the no of processes :\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the burst time for process %d : ",i);
  scanf("%d",&b[i]);
 }
 int t=0,tat[50],ct[50],wt[50];
 for(i=0;i<n;i++)
 {
   ct[i]=t+b[i];
   t=t+b[i];
   tat[i]=ct[i];
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

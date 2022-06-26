#include<stdio.h>
int main()
{
 int n,b[50],i,j,temp,p[50],pr[50],temp1,temp2;
 printf("Enter the no of processes :\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)                                                        
 {
  printf("Enter the burst time and priority for process %d : ",i);
  scanf("%d %d",&b[i],&pr[i]);
  p[i]=i;
 }
 for(i=0;i<n-1;i++)
 {
   for(j=0;j<n-i-1;j++)
   {
     if(pr[j]>pr[j+1])
     {
       temp = pr[j];
       pr[j]=pr[j+1];
       pr[j+1]=temp;
       
       temp1 = b[j];
       b[j]=b[j+1];
       b[j+1]=temp1;
       
       temp2=p[j];
       p[j]=p[j+1];
       p[j+1]=temp2;
     }
   }
 }
 
 int t=0,tat[50],ct[50],wt[50];
 i=0;
for(i=0;i<n;i++)
 {
   ct[i]=t+b[i];
   t=t+b[i];
   tat[i]=ct[i];
   wt[i]=tat[i]-b[i];
 }
 printf("\nprocess\t\tburst time\t\tpriority\t\tTurn around time\t\tWaitng time\n");
 for(i=0;i<n;i++)
 {
  printf("   %d   \t\t     %d    \t\t  %d    \t\t      %d        \t\t     %d    \n",p[i],b[i],pr[i],tat[i],wt[i]);
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

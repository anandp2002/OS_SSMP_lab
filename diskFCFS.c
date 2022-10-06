#include<stdio.h>
#include<stdlib.h>
void main()
{
 int n,rq[20],i,initial,thmt;//thmt=totalheadmovement
 printf("Enter the no of requests\n");
 scanf("%d",&n);
 printf("Enter the request sequence\n");
 for(i=0;i<n;i++)
 scanf("%d",&rq[i]);
 printf("Enter the initial head position\n");
 scanf("%d",&initial);
 for(i=0;i<n;i++)
 {
  thmt+=abs(rq[i]-initial);
  initial=rq[i];
 }
 printf("Total Head Movement = %d\n",thmt);
}

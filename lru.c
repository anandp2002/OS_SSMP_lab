#include<stdio.h>
int main()
{
  int n,i,k,l,rs[10],flag,f,frame[10],fi=0,hit=0,pf=0,j,pnt[50],point=0,flag2,temp,pos[50];
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
    pnt[i]=0;
    frame[i]=-1;
    pos[i]=i;
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
        point++;
        pnt[j]=point;
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
      for(j=0;j<f;j++)
      { flag2=0;
        if(frame[j]==-1)
        {
          frame[j]=rs[i];
          point++;
          pnt[j]=point;
          flag2=1;
          break;
        }
      }
      if(flag2==0)
      {
       for(k=0;k<f-1;k++)
       {
	for(l=0;l<f-k-1;l++)
	{
	 if(pnt[l]>pnt[l+1])
	 {
	  temp=pnt[l];
	  pnt[l]=pnt[l+1];
	  pnt[l+1]=temp;
	  
	  temp=pos[l];
	  pos[l]=pos[l+1];
	  pos[l+1]=temp;
	 }
	}   
       }
       frame[pos[0]]=rs[i];
       point++;
       pnt[0]=point;
      }
      
      pf++;
    }
    printf("    %d    \t",rs[i]);
    for(j=0;j<f;j++)
    {
      printf(" %d  ",frame[j]);
    }
    if(flag==0)
    {
     printf("\tmiss");
    }
    else
    {
     printf("\thit");
    }
    printf("\n");
  }
  printf("Page Hit   = %d\n",hit);
  printf("Page fault = %d",pf);
}

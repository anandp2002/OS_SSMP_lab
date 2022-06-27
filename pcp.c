#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty,item=0,s;
int main()
{
  int n;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  printf("Enter the size of the buffer : ");
  scanf("%d",&s);
  empty=s;
  printf("\n1.Producer\n2.Consumer\n3.Exit\n");
  while(1)
  {
    printf("\nEnter your choice : ");
    scanf("%d",&n);
    switch(n)
    {
      case 1 : if((mutex==1)&&(empty!=0))
      producer();
      else
      printf("\nBuffer full !\n");
      break;
      
      case 2 : if((mutex==1)&&(full!=0))
      consumer();
      else
      printf("\nBuffer empty \n");
      break;
      
      case 3 : printf("Operation Finished !\n");
      exit(0);
      break;
    }
  }
  return 0;
}

int wait(int s)
{
  return(--s);
}

int signal(int s)
{
  return(++s);
}

void producer()
{
  mutex=wait(mutex);
  full=signal(full);
  empty=wait(empty);
  item++;
  printf("Producer produces the item %d",item);
  mutex=signal(mutex);                                
}

void consumer()
{
  mutex=wait(mutex);
  full=wait(full);
  empty=signal(empty);
  item--;
  printf("Consumer consumes the item %d",item);
  mutex=signal(mutex);
}

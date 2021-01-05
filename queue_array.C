/* Queue implementation using array */
#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1;
int rear=-1;

void insert(int val)
{
   if(rear==-1)
   {
      front=rear=0;
	  queue[rear]=val;
   }
   else 
   {
      if(rear==size-1)
	  {
	     printf("\n\t!!Oueue Full!!\n\t!!Can't Insert!!\n");
	  }
	  else 
	  {
	     rear=rear+1;
		 queue[rear]=val;
	  }
   }
}

void delete()
{
   if(front==-1)
   {
       printf("\n\t!!Queue Empty!!\n\t!!Can't Delete!!\n");
   }
   else 
   {
       printf("\nItem removed is %d\n",queue[front]);
	   if(front==rear)
	   {
	      front=-1;
		  rear=-1;
	   }
	   else 
	   {
	      front=front+1;
	   }
   }
}

void peep()
{
   int val;
   if(front==-1)
   {
      printf("\n\t!!Queue Empty!!\n");
   }
   else 
   {
      printf("\nElement at the front=%d\n",queue[front]);
   }
}

void display()
{
   int i;
   if(front==-1)
   {
      printf("\n\t!!Queue Empty!!\n");
   }
   else 
   {
      printf("\nQueue Elements:\n");
	  for(i=front;i<=rear;i++)
	  {
	     printf(" %d ",queue[i]);
	  }
	  printf("\n");
   }
}

int main()
{
  int choice;
  int val;
  while(1)
  {
      printf("\n\tMENU \n 1.Insert \n 2.Delete \n 3.Peep \n 4.Display \n 5.Exit \n");
	  printf("Enter your choice:");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	      case 1: printf("Enter value:");
		          scanf("%d",&val);
				  insert(val);
				  break;
		  case 2: delete();
		          break;
		  case 3: peep();
		          break;
		  case 4: display();
		          break;
		  case 5: exit(0);
	  }
  } 
}


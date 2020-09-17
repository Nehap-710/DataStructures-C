/*circular queue implementation*/
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
      if((front==0 && rear==size-1) || (front==(rear+1)))
	  {
	      printf("\n\t!!Queue Full!!\n\t!!Can't Insert!!");
	  }
	  else 
	  {
	      if(rear==size-1 && front!=0)
		  {
		     rear=0;
		  }
		  else 
		  {
		     rear=rear+1;
		  }
		  queue[rear]=val;
	  }
   }
}

void delete()
{
   if(front==-1)
   {
      printf("\n\t!!Queue Empty!!\n\tCan't Delete\n");
   }
   else 
   {
      printf("Item removed is %d",queue[front]);
	  if(front==rear)
	  {
	      front=-1;
		  rear=-1;
	  }
	  else 
	  {
	      if(front==size-1)
		  {
		    front=0;
		  }
		  else 
		  {
		    front=front+1;
		  }
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
	    printf("Element at the front is %d",queue[front]);
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
	    printf("\nQueue elements:\n");
		if(front<=rear)
		{
		    for(i=front;i<=rear;i++)
			{
			    printf(" %d ",queue[i]);
			}
		}
		else 
		{
		    for(i=front;i<=size-1;i++)
			{
			    printf(" %d ",queue[i]);
			}
			for(i=0;i<=rear;i++)
			{
			    printf(" %d ",queue[i]);
			}
		}
	}
}

int main()
{
    int choice;
	int val;
	while(1)
	{
	    printf("\n\tMENU \n 1.Insert \n 2.Delete \n 3.Peep \n 4.Display \n 5.Exit");
		printf("\nEnter your choice:");
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


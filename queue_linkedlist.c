/* Queue in form of linked list */
#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node * next;
};

void insert(int val);
void delete();
void peep();
void display();
struct node * front=NULL;
struct node * rear=NULL;

int main()
{
  while(1)
  {
     int choice, val;
	 printf("\n\tMENU\n 1.Insert \n 2.Delete \n 3.Peep \n 4.Display \n 5.Exit\n");
	 printf("Enter your choice:");
	 scanf("%d", &choice);
	 switch(choice)
	 {
	   case 1: printf("Enter Data:");
	           scanf("%d", &val);
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

void insert(int val)
{
   struct node * newnode;
   newnode = (struct node *)malloc(sizeof(struct node *));
   newnode->data=val;
   newnode->next=NULL;
   if(rear!=NULL)
   {
      rear->next=newnode;
	  rear=newnode;
   }
   else 
   {
      rear=front=newnode;
   }
}

void delete()
{
   struct node * ptr;
   ptr=front;
   if(front==NULL)
   {
      printf("\n\t!!Queue is Empty!!\n");
   }
   else 
   {
      printf("Value deleted from queue=%d", front->data);
	  if(front==rear)
	  {
	     front=rear=NULL;
	  }
	  else 
	  {
	     front=front->next;
	  }
	  free(ptr);
   }
}

void peep()
{
   if(front==NULL)
   {
      printf("\n\t!!Queue is Empty!!\n");
   }
   else 
   {
      printf("The front element of the queue is:%d",front->data);
   }
}

void display()
{
   struct node * ptr;
   ptr=front;
   if(ptr==NULL)
   {
      printf("\n\t!!Queue is Empty!!\n");
   }
   else 
   {
      printf("The Queue elements are \n");
	  while(ptr!=NULL)
	  {
	     printf(" %d ",ptr->data);
		 ptr=ptr->next;
	  }
   }
}


/*Stack as a linked list 2*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;


struct node * top=NULL;
void display();
void push(int val);
int pop();
void peep();

int main()
{
  int ch,val;
  while(1)
  {
    printf("\n\tMENU\n 1.Push\n 2.Pop\n 3.Peep\n 4.Display\n 5.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	  case 1: printf("Enter data:");
	          scanf("%d",&val);
			  push(val);
	          break;
	  case 2: val=pop();
	          if(val!=-1)
			  {
			      printf("Element popped=%d",val);
			  }
	          break;
	  case 3: peep();
	          break;
	  case 4: display();
	          break;
	  case 5: exit(0);
	}
  }
}

void display()
{
  node * ptr;
  ptr=top;
  if(ptr==NULL)
  {
    printf("!!Stack Empty!!");
	return;
  }
  printf("\nElements of the stack are \n");
  while(ptr!=NULL)
  {
    printf(" %d ",ptr->data);
	ptr=ptr->next; 
  }
}

void push(int val)
{
  node *newnode=malloc(sizeof(node));
  newnode->data=val;
  newnode->next=top;
  top=newnode;
}

int pop()
{
  int val=-1;
  node *ptr;
  if(top==NULL)
  {
    printf("\n\t!!List Empty!!\n\t!!Can't Delete!!\n");
  }
  else 
  {
    ptr=top;
	val=top->data;
	top=top->next;
	free(ptr);
  }
  return val;
}

void peep()
{
  if(top==NULL)
  {
    printf("\n\t!!Stack Empty!!\n");
  }
  else 
  {
    printf("Element at top=%d",top->data);
  }
}


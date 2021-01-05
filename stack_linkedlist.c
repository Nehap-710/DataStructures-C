/* stack in form of linked list */
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

void display(node *);
node * push(node *);
node * pop(node *);
void peep(node *);

int main()
{
  struct node * top=NULL;
  int ch;
  while(1)
  {
    printf("\n\tMENU\n 1.Push\n 2.Pop\n 3.Peep\n 4.Display\n 5.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	  case 1: top=push(top);
	          break;
	  case 2: top=pop(top);
	          break;
	  case 3: peep(top);
	          break;
	  case 4: display(top);
	          break;
	  case 5: exit(0);
	}
  }
}

void display(node * top)
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

node * push(node * start)
{
  node *newnode=malloc(sizeof(node));
  printf("Enter Data:");
  scanf("%d",&newnode->data);
  newnode->next=start;
  start=newnode;
  return start;
}

node * pop(node *top)
{
  node *ptr;
  if(top==NULL)
  {
    printf("\n\t!!List Empty!!\n\t!!Can't Delete!!\n");
  }
  else 
  {
    ptr=top;
	top=top->next;
	printf("Element popped=%d",ptr->data);
	free(ptr);
  }
  return top;
}

void peep(node * top)
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


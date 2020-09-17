/* Circular linked list implementation*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   int data;
   struct node *next;
}node;

void display(node *);
node * insert_beg(node *);
node * insert_end(node *);
node * delete_beg(node *);
node * delete_end(node *);

int main()
{
   struct node * start=NULL;
   int ch;
   while(1)
   {
      printf("\n\tMENU\n 1.Insert at beginning \n 2.Insert at end \n 3.Delete at beginning \n 4.Delete at end \n 5.Display \n 6.Exit \n");
	  printf("Enter your choice:");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	      case 1: start=insert_beg(start);
		          break;
		  case 2: start=insert_end(start);
		          break;
		  case 3: start=delete_beg(start);
		          break;
		  case 4: start=delete_end(start);
		          break;
		  case 5: display(start);
		          break;
		  case 6: exit(0);
	  }
   }
}

void display(node * start)
{
   node * ptr;
   ptr=start;
   if(ptr==NULL)
   {
      printf("\n\t!!Empty List!!\n");
	  return;
   }
   printf("\nElements of the list:\n");
   while(ptr->next!=start)
   {
      printf(" %d ",ptr->data);
	  ptr=ptr->next;
   }
   printf(" %d ",ptr->data);
}

node * insert_beg(node * start)
{
   node *ptr;
   node *newnode=malloc(sizeof(node));
   printf("Enter Data:");
   scanf("%d",&newnode->data);
   
   ptr=start;
   if(start==NULL)
   {
      start=newnode;
	  newnode->next=start;
	  return start;
   }
   
   while(ptr->next!=start)
   {
      ptr=ptr->next;
   }
   ptr->next=newnode;
   newnode->next=start;
   start=newnode;
   
   return start;
}

node * insert_end(node * start)
{
   node * ptr;
   node *newnode=(node *)malloc(sizeof(node));
   printf("Enter data:");
   scanf("%d",&newnode->data);
   
   if(start==NULL)
   {
      start=newnode;
   }
   else 
   {
      ptr=start;
	  while(ptr->next!=start)
	  {
	     ptr=ptr->next;
	  }
	  ptr->next=newnode;
   }
   newnode->next=start;
   return start;
}

node * delete_beg(node * start)
{
   node *ptr;
   if(start==NULL)
   {
      printf("\n\t!!List Empty!!\n\t!!Can't Delete!!\n");
   }
   else 
   {
      ptr=start;
	  while(ptr->next!=start)
	  {
	     ptr=ptr->next;
	  }
	  if(ptr=start)
	  {
	     start=NULL;
	  }
	  else 
	  {
	     ptr->next=start->next;
		 ptr=start;
		 start=start->next;
	  }
	  free(ptr);
   }
   return start;
}

node * delete_end(node * start)
{
   node *ptr, *preptr;
   if(start==NULL)
   {
      printf("\n\t!!List Empty!!\n\t!!Can't Delete!!\n");
   }
   else 
   {
      ptr=start;
	  while(ptr->next!=start)
	  {
	     preptr=ptr;
		 ptr=ptr->next;
	  }
	  if(ptr==start)
	  {
	     start=NULL;
	  }
	  else 
	  {
	     preptr->next=start;
	  }
	  free(ptr);
   }
   return start;
}


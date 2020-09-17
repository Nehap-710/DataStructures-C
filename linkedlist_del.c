/* Linked list deletions */
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

void display(node *);
node * insert_end(node *);
node * delete_beg(node *);
node * delete_end(node *);
node * delete_at(node *);
node * delete_before(node *);
node * delete_after(node *);

int main()
{
  int i,n;
  struct node * start=NULL;
  int ch;
  printf("Enter the number of elements in the list:");
  scanf("%d",&n);
  if(n!=0)
  {
     printf("Enter the values of nodes\n");
     for(i=0;i<n;i++)
     {
       start=insert_end(start);
     }
  }
  while(1)
  {
    printf("\n\tMENU \n 1.Insert more elements at the end.  \n 2.Display. \n 3.Delete in beginning. \n 4.Delete at the end. \n 5.Delete at a particular position. \n 6.Delete Before a node. \n 7.Delete after a node. \n 8.Exit. ");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	  case 1: start=insert_end(start);
	          break;
	  case 2: display(start);
	          break;
	  case 3: start=delete_beg(start);
	          break;
	  case 4: start=delete_end(start);
	          break;
	  case 5: start=delete_at(start);
	          break;
	  case 6: start=delete_before(start);
	          break;
	  case 7: start=delete_after(start);
	          break;
	  case 8: exit(0);
	  	     	   	        	   	          	        
	}
  }
}

void display(node * start)
{
  node * ptr; 
  ptr=start;
  if(ptr==NULL)
  { 
    printf("!!Empty List!!");
  }
  else 
  {
    printf("\nElements of the List are:\n");
    while(ptr!=NULL)
    {
      printf(" %d ",ptr->data);
	  ptr=ptr->next;
    }
  }
}

node * insert_end(node * start)
{
  node *ptr;
  node *newnode=(node *)malloc(sizeof(node));
  printf("Enter Data:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(start==NULL)
  {
    start=newnode;
  }
  else 
  {
    ptr=start;
	while(ptr->next!=NULL)
	{
	  ptr=ptr->next;
	}
	ptr->next=newnode;
  }
  return start;
}

node * delete_beg(node * start)
{
  node *ptr;
  if(start==NULL)
  {
    printf("\n\t!!List Empty!!\n\t!!Can't Delete!!");
  }
  else 
  { 
    ptr=start;
	start=start->next;
	free(ptr);
  }
  return start;
}

node * delete_end(node * start)
{
  node *ptr;
  if(start==NULL)
  {
    printf("\n\t!!List Empty!!\n\t!!Can't Delete!!");
  }
  else 
  {
    ptr=start;
	
	while(ptr->next->next!=NULL)
	{
	  ptr=ptr->next;
	}
	
	free(ptr->next);
	ptr->next=NULL;
	
  }
  
  return start;
}

node * delete_at(node * start)
{
  node *ptr1, *ptr2;
  int pos, count=1;
  if(start==NULL)
  {
    printf("\n\t!!List Empty!!\n\t!!Can't Delete");
  }
  else 
  {
    printf("Enter the position from which you want to delete the element:");
    scanf("%d",&pos);
    if(pos==1)
    {
      ptr1=start;
 	  start=start->next;
	  free(ptr1);
    }
    else 
    {
       ptr1=start;
	   ptr2=start;
	   while(ptr2!=NULL && count<pos)
	   {
	     count=count++;
	     ptr1=ptr2;
	     ptr2=ptr2->next;
	   }
	   if(count==pos)
	   {
	     ptr1->next=ptr2->next;
	     free(ptr2);
	   }
	   else 
	   {
	     printf("\n\t!!Position Doesn't Exists!!\n\t!!Can't Delete!!");
	   }
    }
  }
  return start;
}

node *delete_after(node *start)
{
  node *ptr1, *ptr2;
  int val;
  ptr1 = start;
  ptr2 = ptr1;
  if(start==NULL)
  {
    printf("\n\t!!List Empty!!\n!!Can't Delete!!\n");
  }
  else 
  {
      printf("Enter the value after which the node has to deleted:");
      scanf("%d", &val);
      while(ptr2->data!=val)
      {
         ptr2 = ptr1;
         ptr1 = ptr1->next;
      }
      if(ptr1->next==NULL)
      {
         printf("\n!!Last value Nothing to delete after it!!\n");
	     return start;
      }
      ptr2->next=ptr1->next;
      free(ptr1);
  }
  return start;
}

node * delete_before(node *start)
{
  node *ptr1, *ptr2;
  int val;
  if(start==NULL)
  {
    printf("\n\t!!List Empty!!\n!!Cant Delete!!\n");
  }
  else 
  { 
    printf("Enter the value of node before which you want to delete:");
    scanf("%d",&val);
    ptr1=ptr2=start;
	if(ptr2->data==val)
	{
	  printf("\n!!First Node!!\nNothing to delete before it!!");
	}
	else 
	{
	  while(ptr2->next->data!=val && ptr2->next!=NULL)
	  {
	    ptr1=ptr2;
		ptr2=ptr2->next;
	  }
	  if(ptr2==start)
	  {
	    start=ptr2->next;
		free(ptr2);
	  }
	  if(ptr2==NULL)
	  {
	     printf("\n\t!!Value not found!!\n\t!!Can't Delete!!\n");
		 return start;
	  }
	  else 
	  { 
	     ptr1->next=ptr2->next;
	     free(ptr2);
	  }
	}
  }
  return start;
}


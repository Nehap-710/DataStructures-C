/* Linked list insertions */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void display(node *);
node * insert_beg(node *);
node * insert_end(node *);
node * insert_at(node *);
node * insert_before(node *);
node * insert_after(node *);

int main()
{
    struct node * start = NULL;
    int ch;
    while(1)
    {
        printf("\n\tMENU\n 1. Display List Items \n 2. Insert at the beginning \n 3. Insert at the end \n 4. Insert at a particular position \n 5. Insert before an element \n 6. Insert after an element \n 7. Exit ");
        printf("\n Enter Your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: display(start);
                    break;
            case 2: start = insert_beg(start);
                    break;
            case 3: start = insert_end(start);
                    break;
            case 4: start = insert_at(start);
                    break;
            case 5: start = insert_before(start);
                    break;
            case 6: start = insert_after(start);
                    break;
            case 7: exit(0);
        }
    }
    return 0;
}

void display(node* start)
{
    node * ptr;
    ptr = start;
    if(ptr==NULL)
    {
        printf("\n Empty List \n");
    }
    printf("\n Elements of the List: \n");
    while(ptr!=NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr -> next;
    }
}

node * insert_beg(node * start)
{
    node *newnode=malloc(sizeof(node));
    printf("\n Enter Data:");
    scanf("%d",&newnode->data);
    newnode->next = start;
    start = newnode;
    return start;
}

node * insert_end(node * start)
{
    node *ptr;
    node *newnode = (node *)malloc(sizeof(node));
    printf("\n Enter Data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    return start;
}

node * insert_after(node * start)
{
    node *ptr;
    int val;
    node *newnode = (node *)malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter the value of node element after which data is to be inserted:");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("!!List Empty!!");
    }
    else
    {
        ptr = start;
        while(ptr!=NULL && ptr->data!=val)
        {
            ptr=ptr->next;
        }
        if(ptr!=NULL)
        {
            newnode->next=ptr->next;
            ptr->next=newnode;
        }
        else
        {
            printf("!!Value Not Found!!\n!!Can't Insert!!");
        }
    }
    return start;
}

node * insert_before(node *start)
{
    node *ptr1, *ptr2;
    int val;
    node *newnode=(node *)malloc(sizeof(node));
    printf("\n Enter Data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter the value of node element before which data is to be inserted: ");
    scanf("%d",&val);
    if(start==NULL)
    {
        printf("!!List Empty!!\n!!Can't Insert!!");
    }
    else
    {
        ptr1=ptr2=start;
        while(ptr2!=NULL && ptr2->data!=val)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        if(ptr2==NULL)
        {
            printf("!!Value not found!!\nCan't Insert!!");
        }
        else
        {
            newnode->next=ptr2;
            if(ptr1==ptr2)
            {
                start=newnode;
            }
            else
            {
                ptr1->next=newnode;
            }
        }
    }
    return start;
}

node * insert_at(node *start)
{
  node *ptr1, *ptr2;
  int pos, count=1;
  node *newnode=(node *)malloc(sizeof(node));
  printf("\n Enter the data:");
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  printf("Enter the position at which the element is to be inserted:");
  scanf("%d",&pos);
  if(start==NULL)
  {
    printf("List empty"); 
  }
  if(pos==1)
  {
    newnode->next=start;
	start=newnode;
  }
  else 
  {
    ptr1=ptr2=start;
	while(count<pos && ptr2!=NULL)
	{ 
	  count++;
	  ptr1=ptr2;
	  ptr2=ptr2->next;
	}
	if(count==pos)
	{
	  newnode->next =ptr2;
	  ptr1->next=newnode;
	}
	else 
	{
	  printf("Can't Insert at position %d",pos);
	}
  }
  return start;
}





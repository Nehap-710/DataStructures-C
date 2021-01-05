/*Stack as an array*/
#include<stdio.h>
#include<stdlib.h>
#define size 50
int stack[size];
int top=-1;

void push(int val)
{
    if(top==size-1)
	{
	    printf("\n\t!!Stack Full!!\n");
	}
	else 
	{
	    top++;
		stack[top]=val;
	}
}

void pop()
{
    if(top==-1)
	{
	    printf("\n\t!!Stack Empty!!\n");
	}
	else 
	{
	    printf("Element removed=%d",stack[top]);
		top--;
	}
}

void peep()
{
   int val;
   if(top==-1)
   {
       printf("\n\t!!Stack Empty!!\n");
   }
   else 
   {
       printf("Element at top=%d",stack[top]);
   }
}

void display()
{
    int i;
	if(top==-1)
	{
	   printf("\n\t!!Stack Empty!!\n");
	}
	else 
	{
	   printf("\nStack elements:\n");
	   for(i=top;i>=0;i--)
	   {
	       printf(" %d ",stack[i]);
	   }
	}
}

int main()
{
   int choice;
   int val;
   while(1)
   {
       printf("\n\tMENU\n 1.Push \n 2.Pop \n 3.Peep \n 4.Display \n 5.Exit \n");
	   printf("Enter your choice:");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	       case 1: printf("Enter value");
		           scanf("%d",&val);
				   push(val);
				   break;
		   case 2: pop();
		           break;
		   case 3: peep();
		           break;
		   case 4: display();
		           break;
		   case 5: exit(0);
	   }
   }
}


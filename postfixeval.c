/*Postfix evaluation*/
#include<stdio.h>
#include<string.h>
#define size 50
float stack[size];

int top=-1;

float evaluate(char *);

void push(float val)
{
    if(top==size-1)
	{
	    printf("\n\t!!Stack Full!!");
	}
	else 
	{
	    top++;
		stack[top]=val;
	}
}

float pop()
{
    if(top==-1)
	{
	    printf("\n\t!!Stack Empty!!");
		return -1;
	}
	else 
	{
	    return(stack[top--]);
	}
}

float peep()
{
    if(top==-1)
	{
	    return -1;
	}
	else 
	{
	    return stack[top];
	}
}

void display()
{
    int i;
	if(top==-1)
	{
	    printf("\n\t!!Stack Empty!!");
	}
	else 
	{
	    printf("\nStack Elements are:\n");
		for(i=top;i>=0;i--)
		{
		     printf("%0.2f  ",stack[i]);
		}
	}
}

int main()
{
    float ans;
	char postfix[50];
	printf("Enter the postfix expression:");
	gets(postfix);
	printf("\n\nThe Postfix Expression is:%s\n",postfix);
	ans=evaluate(postfix);
	printf("\n\nAnswer after evaluation is %0.2f",ans);
}

float evaluate(char postfix[50])
{
    int i=0;
	float val;
	float a,b;
	while(postfix[i]!='\0')
	{
	    if(isalpha(postfix[i]))
		{
		    printf("\nEnter the value of %c:",postfix[i]);
			scanf("%f",&val);
			push(val);
		}
		else 
		{
		    b=pop();
			a=pop();
			
			switch(postfix[i])
			{
			    case '+': val = (a+b);
				          break;
				case '-': val = (a-b);
				          break;
				case '*': val = (a*b);
				          break;
				case '/': val = (a/b);
				          break;
			}
			push(val);
		}
		i++;
	}
	return pop();
}


/* infix to postfix*/
#include<stdio.h>
#include<string.h>
#include"charstack.h"

void infixtopostfix(char *, char *);
int getprecedence(char c);

int main()
{
   char infix[50];
   char postfix[50];
   int len=0;
   printf("Enter the infix expression:\n");
   gets(infix);
   infixtopostfix(infix,postfix);
   
   printf("\nThe Postfix Expression=%s",postfix);
}

void infixtopostfix(char infix[50], char postfix[50])
{
   int i=0; 
   int j=0; 
   int len=0;
   int x;
   len=strlen(infix);
   infix[len]= ')';
   infix[len+1]='\0';
   push('(');
   
   while(infix[i]!='\0')
   {
       if(infix[i]=='(')
	   {
	      push(infix[i]);
	   }
	   else if(isalpha(infix[i]) || isdigit(infix[i]))
	   {
	      postfix[j++]=infix[i];
	   }
	   else if(infix[i]==')')
	   {
	      while(peep()!='(') 
		  {
		     x=pop();
			 postfix[j++]=x;
		  }
		  pop(); 
	   }
	   else 
	   {
	      while( getprecedence(infix[i])<=getprecedence(peep()))
		  {
		     x=pop();
			 postfix[j++]=x;
		  }
		  push(infix[i]);
	   }
	   i++;
   }
   postfix[j]='\0';
}

int getprecedence(char c)
{
   if( c=='%' || c=='*' || c=='/' )
   {
      return 2;
   }
   if( c=='+' || c=='-' )
   {
      return 1;
   }
   else 
   {
      return 0;
   }
}


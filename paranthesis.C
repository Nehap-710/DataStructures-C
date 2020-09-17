/*Stack Implementation using array paranthesis*/
#include<stdio.h>
#include<stdlib.h>
#include"charstack.h"

int main()
{
   int choice;
   char expr[50];
   char val;
   int i=0;
   printf("Enter an algebraic expression with paranthesis:\n");
   gets(expr);
   printf("Exp=%s",expr);
   while(expr[i]!='\0')
   {
      if(expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
	  {
	      push(expr[i]);
	  }
	  if(expr[i]==')' || expr[i]=='}' || expr[i]==']')
	  {
	      val=pop();
		  if(expr[i]==')' && val!='(')
		  {
		      printf("\n!!Not Well Formed!!\n");
			  exit(0);
		  }
		  if(expr[i]=='}' && val!='{')
		  {
		      printf("\n!!Not Well Formed!!\n");
			  exit(0);
		  }
		  if(expr[i]==']' && val!='[')
		  {
		      printf("\n!!Not Well Formed!!\n");
			  exit(0);
		  }
	  }
	  i++;
   }
   if(!is_stack_empty())
   {
      printf("\nExpression is not well formed!!\n");
   }
   else 
   {
      printf("\nExpression is well formed\n");
   }
}


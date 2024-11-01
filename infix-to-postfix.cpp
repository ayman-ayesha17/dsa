#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char stac[20];
int tos=-1;
float stack[20];
int top=-1;
void ipush(char s)
{
	stac[++tos]=s;
}
int ipop()
{
	return(stac[tos--]);
}
int precd(char s)
{
	switch(s)
	{
		case'^':return 4;
		case'*'	:
		case'%':
		case'/':return 3;
		case'+':
		case'-':return 2;
		case'(':
		case')':
		case'#':return 1;
	}
          return 0;
}
void convertip(char infix[20],char postfix[20])
{
	int i,j=0;
	char symbol;
	ipush('#');
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		switch(symbol)
		{
			case'(': ipush(symbol);
			        break;
			case')':while(stac[tos]!='(')
			         postfix[j++]=ipop();
			         ipop();
			         break;  
			case'^':
			case'*':
			case'/':
			case'%':
			case'+':
			case'-':while(precd(symbol)<=precd(stac[tos]))
			         postfix[j++]=ipop();
			         ipush(symbol);
			         break;
			default:postfix[j++]=symbol;
		}
	}
	while(stac[tos]!='#')
	   postfix[j++]=ipop();
	postfix[j]='\0';
}
void push(float ele)
{
	stack[++top]=ele;
}
float pop()
{
	return(stack[top--]);
}
void evaluate(char postfix[50])
{
	int i;
	char symb;
	float op1,op2,res,x;
	for(i=0;i<strlen(postfix);i++)
	{
		symb=postfix[i];
        if (isalpha(symb))
		{
			printf("enter the val for %c",symb);
			scanf("d",&x);
			push(x);
		}
		else
			op2=pop();
			op1=pop();
			switch(symb)
			{
				case'+':push(op1+op2);
				        break;
				case'-':push(op1-op2);
				        break;   
				case'*':push(op1*op2);
				        break;	
				case'/':push(op1/op2);
				        break;		
				case'%':push((int)op1%(int)op2);
				        break;		
				case'^':push(pow(op1,op2));
				        break;		
				default:printf("invalid");
					    exit(0);
			}
	}
	
}

int main()
{
	char infix[20];
	char postfix[20];
	printf("enter infix exp");
	gets(infix);
	convertip(infix,postfix);
	printf("postfix exp is %s",postfix);
	evaluate(postfix);
	  return 0;
}

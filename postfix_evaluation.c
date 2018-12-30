#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1,n,k,x,s1[50];
char c,s[50],s2[50];
void push(char c)
{
	top=top+1;
	s1[top]=c;
}
void push1(int c)
{
	top=top+1;
	s1[top]=c;
}
int pop()
{
	k=s1[top];
	top=top-1;
	return k;
}
int isp(char x)
{
	switch(x)
	{
	case '^':return 3;
		break;
	case '*':return 2;
		break;
	case '/':return 2;
		break;
	case '+':return 1;
		break;
	case '-':return 1;
		break;
	case '(':return 0;
		break;
	}
}
int icp(char x)
{
	switch(x)
	{
	case '^':return 4;
		break;
	case '*':return 2;
		break;
	case '/':return 2;
		break;
	case '+':return 1;
		break;
	case '-':return 1;
		break;
	case '(':return 4;
		break;
	}
}
void main()
{
	int item,i=0,j=0,l,k=0,op,x,y,t,value,flag;
	printf("Enter the expression\n");
	setbuf(stdin,NULL);
	gets(s);
	l=strlen(s);
	s[l]=')';
	s[l+1]='\0';
	push('(');
	while(top>-1)
	{
		item=s[i];
		i++;
		x=pop();
		if(isdigit(item)!=0)
		{
			push(x);
			s2[j]=item;
			j++;
		}
		i=0;
		else if(item==')')
		{
			while(x!='(')
			{
				s2[j]=x;
				j++;
				x=pop();
			}
		}
		else if(isp(x)>=icp(item))
		{
			while(isp(x)>=icp(item))
			{
				s2[j]=x;
				j++;
				x=pop();
			}
			push(x);
			push(item);
		}
		else
		{
			push(x);
			push(item);
		}
	}
	s2[j]='\0';
	printf("The postfix expression is-");
	puts(s2);
	l=strlen(s2);
	item=s2[k];
	k++;
	while(item!='\0')
	{
		if(isdigit(item)!=0)
		{
			push1(item-'0');
		}
		else
		{
			op=item;
			x=pop();
			y=pop();
			switch(op)
			{
				case '+':t=x+y;
					break;
				case '-':t=y-x;
					break;
				case '*':t=y*x;
					break;
				case '/':t=y/x;
					break;
				case'^':t=y^x;
					break;
			}
			push1(t);
		}
		item=s2[k];
		k++;
	}
	value=pop();
	printf("The result is %d\n",value);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define m 100
int top=-1;
int stack[m];
void push(char data)
{
if(top==m-1)
{
printf("Overflow\n");
}
else
{
top=top+1;
stack[top]=data;
}
}

char pop()
{
char a;
if(top==-1)
{
printf("Empty\n");
}
else
{
a=stack[top];
top=top-1;
}
}

int isp(char y)
{
switch(y)
{
case '^':return 3;
case '*':return 2;
case '/':return 2;
case '+':return 1;
case '-':return 1;
case '(':return 0;
}
}

int icp(char y)
{
switch(y)
{
case '^':return 4;
case '*':return 2;
case '/':return 2;
case '+':return 1;
case '-':return 1;
case '(':return 4;
}
}


void main()
{
char s1[m],s2[m],item,x;
int i,j=0,l;
printf("Enter the infix expression\n");
scanf("%s",s1);
l=strlen(s1);
s1[l]=')';
s1[l+1]='\0';
push('(');
while(top>-1)
{
for(i=0;i<l;i++)
{
item=s1[i];
x=pop();
if(isalpha(item)!=0)
{
push(x);
s2[j]=item;
j=j+1;
}
else if(item==')')
{
while(x!='(')
{
s2[j]=x;
j=j+1;
x=pop();
}
}
else if(isp(x)>=icp(item))
{
while(isp(x)>=icp(item))
{
s2[j]=x;
j=j+1;
x=pop();
}
push(x);
push(item);
}
else if(isp(x)<icp(item))
{
push(x);
push(item);
}
else
{
printf("Invalid expression\n");
}
}
}
//printf("Postfix expression is -> %s\n",s2);
puts(s2);
}




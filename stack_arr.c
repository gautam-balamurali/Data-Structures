#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int top=-1;
int stack[100];
int data;
void push()
{
if(top==max_size-1)
{
printf("Overflow\n");
}
else
{
printf("Enter the data\n");
scanf("%d",&data);
top=top+1;
stack[top]=data;
}
}

void pop()
{
if(top==-1)
{
printf("Empty\n");
}
else
{

top=top-1;
}
}

void display()
{
int i;
if(top==-1)
{
printf("Empty\n");
}
else
{
i=top;
while(i>=0)
{
printf("%d\n",stack[i]);
i=i-1;
}
}
}

void main()
{
int ch;
do
{
printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();break;
case 2: pop();break;
case 3: display();break;
case 4: exit(0);
}
}while(ch!=4);
}


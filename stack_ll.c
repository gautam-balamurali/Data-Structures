#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top=NULL,*p,*temp;
int item;
void push()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the item\n");
scanf("%d",&item);
p->data=item;
p->next=top;
top=p;
}

void pop()
{
if(top==NULL)
printf("Stack is empty\n");
else{temp=top;
printf("%d\n",temp->data);
top=top->next;
free(temp);
}
}
void display()
{
if(top==NULL)
printf("Stack is empty\n");
else
{
printf("hello");
temp=top;
while(temp!=NULL)
{printf("%d\n",temp->data);
temp=temp->next;
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


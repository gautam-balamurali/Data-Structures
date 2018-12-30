#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *front=NULL,*p,*rear=NULL,*temp;
int item;

void enqueue()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the item\n");
scanf("%d",&item);
p->data=item;
p->next=NULL;
if(front==NULL && rear==NULL)
{
front=p;
rear=p;
}
else
{
rear->next=p;
rear=p;
}
}

void dequeue()
{
if(front==NULL && rear==NULL)
{
printf("Queue is empty\n");
}
else if(front==rear)
{
temp=front;
printf("%d\n",temp->data);
front=NULL;
rear=NULL;
free(temp);
}
else
{
temp=front;
printf("%d\n",temp->data);
front=front->next;
free(temp);
}
}

void display()
{
if(front==NULL && rear==NULL)
{
printf("Queue is empty\n");
}
else
{
temp=front;
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
}

void main()
{
int ch;
do
{
printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: enqueue();break;
case 2: dequeue();break;
case 3: display();break;
case 4: exit(0);
}
}while(ch!=4);
}


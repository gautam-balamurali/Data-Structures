#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *start=NULL,*temp,*p,*a,*b;
int pos,i;
void insert_begin()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the data\n");
scanf("%d",&p->data);
if(start==NULL)
{
p->next=NULL;
start=p;
}
else
{
p->next=start;
start=p;
}
}

void insert_last()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the data\n");
scanf("%d",&p->data);
p->next=NULL;
if(start==NULL)
{start=p;}
else
{
temp=start;
while(temp->next!=NULL)
{temp=temp->next;}
temp->next=p;
}
}

void insert_sp()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the data\n");
scanf("%d",&p->data);
printf("Enter the position\n");
scanf("%d",&pos);
if(pos==1)
{
p->next=start;
start=p;
}
else
{
temp=start;
for(i=1;i<pos-1;i++)
{temp=temp->next;}
p->next=temp->next;
temp->next=p;
}
}

void delete_begin()
{
if(start==NULL)
{
printf("List is empty\n");
}
else
{
temp=start;
printf("%d\n",temp->data);
start=temp->next;
free(temp);
}
}

void delete_last()
{
if(start==NULL)
{
printf("List is empty\n");
}
else if(start->next==NULL)
{
temp=start;
printf("%d\n",temp->data);
start=NULL;
free(temp);
}
else
{
a=start;
b=a->next;
while(b->next!=NULL)
{
a=a->next;
b=b->next;
}
a->next=NULL;
printf("%d\n",b->data);
free(b);
}
}

void delete_sp()
{
if(start==NULL)
{
printf("List is empty\n");
}
printf("Enter the position\n");
scanf("%d",&pos);
if(pos==1)
{
temp=start;
printf("%d\n",temp->data);
start=temp->next;
free(temp);
}
else
{
a=start;
b=a->next;
for(i=1;i<pos-1;i++)
{
a=a->next;
b=b->next;
}
a->next=b->next;
printf("%d\n",b->data);
free(b);
}
}

void display()
{
if(start==NULL)
{printf("List is empty\n");}
else
{
temp=start;
while(temp!=NULL)
{
printf("%d-->",temp->data);
temp=temp->next;
}
printf("\n");
}
}

void main()
{
int ch;
do
{
printf("Menu\n");
printf("1.Insert_Begin\n2.Insert_Special_Position\n3.Insert_Last\n4.Delete_Begin\n5.Delete_Special_Position\n6.Delete_Last\n7.Display\n8.Exit\n");
printf("Enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert_begin();break;
case 2: insert_sp();break;
case 3: insert_last();break;
case 4: delete_begin();break;
case 5: delete_sp();break;
case 6: delete_last();break;
case 7: display();break;
case 8: exit(0);
}
}while(ch!=8);
}




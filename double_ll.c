#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
struct node *head=NULL,*tail=NULL,*p,*a,*b,*temp;
int pos,i,c=0;
void insert_begin()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the data\n");
scanf("%d",&p->data);
if(head==NULL)
{
p->prev=NULL;
p->next=NULL;
head=p;
tail=p;
}
else
{
p->prev=NULL;
p->next=head;
head->prev=p;
head=p;
}
c++;
}
void insert_end()
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the data\n");
scanf("%d",&p->data);
if(head==NULL)
{
p->prev=NULL;
p->next=NULL;
head=p;
tail=p;
}
else
{
p->next=NULL;
tail->next=p;
p->prev=tail;
tail=p;
}
c++;
}

void insert_sp()
{
p=(struct node*)malloc(sizeof(struct node));

printf("Enter the position\n");
scanf("%d",&pos);
if(pos>c+1)
{
printf("Invalid position\n");
}
else if(pos==c+1)
{
insert_end();
}
else
{
if(head==NULL)
insert_begin();
else if(pos==1)
{
printf("Enter the data\n");
scanf("%d",&p->data);
p->next=head;
head->prev=p;
p->prev=NULL;
head=p;
}
else
{
printf("Enter the data\n");
scanf("%d",&p->data);
a=head;
b=a->next;
for(i=1;i<pos-1;i++)
{
a=a->next;
b=b->next;
}
a->next=p;
p->prev=a;
p->next=b;
b->prev=p;
}
}
c++;
}


void delete_begin()
{
if(head==NULL)
{
printf("List is empty\n");
}
else if(head==tail)
{
temp=head;
printf("%d\n",temp->data);
head=NULL;
tail=NULL;
free(temp);
}
else
{
temp=head;
printf("%d\n",temp->data);
head=temp->next;
head->prev=NULL;
free(temp);
}
c--;
}

void delete_last()
{
if(head==NULL)
{
printf("List is empty\n");
}
else if(head==tail)
{
temp=head;
printf("%d\n",temp->data);
head=NULL;
tail=NULL;
free(temp);
}
else
{
temp=tail;
printf("%d\n",temp->data);
tail=temp->prev;
tail->next=NULL;
free(temp);
}
c--;
}

void delete_sp()
{
printf("Enter the position\n");
scanf("%d",&pos);
if(pos>c+1)
{
printf("Invalid position\n");
}
else
{
if(pos==c+1)
{
delete_last();
}
else if(pos==1)
{
temp=head;
printf("%d\n",temp->data);
head=temp->next;
head->prev=NULL;
free(temp);
}
else
{
a=head;
b=a->next;
for(i=1;i<pos-1;i++)
{a=a->next;
b=b->next;
}
a->next=b->next;
(b->next)->prev=a;
printf("%d\n",b->data);
free(b);
}
}
c--;
}

void display()
{
if(head==NULL)
{printf("List is empty\n");}
else
{
temp=head;
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
case 3: insert_end();break;
case 4: delete_begin();break;
case 5: delete_sp();break;
case 6: delete_last();break;
case 7: display();break;
case 8: exit(0);
}
}while(ch!=8);
}




#include <stdio.h>
#include <stdlib.h>

struct node
{
int coeff,expo;
struct node *next;
};
struct node *startr=NULL,*temp1,*temp2,*temp3,*p,*a=NULL,*b=NULL,*d=NULL,*temp4=NULL,*tempr=NULL;

struct node *createpoly()
{
struct node *start=NULL,*temp;
int i,n,exp,co;
printf("Enter the no. of elements\n");
scanf("%d",&n);
i=1;
while(i<=n)
{
p=(struct node*)malloc(sizeof(struct node));
printf("Enter the coefficient\n");
scanf("%d",&co);
printf("Enter the exponent\n");
scanf("%d",&exp);
p->coeff=co;
p->expo=exp;
p->next=NULL;
if(start==NULL)
{
start=p;
temp=p;
}
else
{
temp->next=p;
temp=p;
}
i=i+1;
}
return(start);
}

void result(int c, int e)
{
int f=0;
tempr=startr;
while(tempr!=NULL)
{
if(tempr->expo==e)
{
tempr->coeff = tempr->coeff+c;
f=1;
break;
}
else
{
tempr=tempr->next;
}
}
if(f==0)
{
p=(struct node*)malloc(sizeof(struct node));
p->coeff=c;
p->expo=e;
p->next=NULL;
if(startr==NULL)
{
temp4=p;
startr=p;
}
else
{
temp4->next=p;
temp4=p;
}
}
}

struct node *multiply(struct node *a, struct node *b)
{
int c,e;
struct node *tempb;
while(a!=NULL)
{
tempb=b;
while(tempb!=NULL)
{
c=(a->coeff)*(tempb->coeff);
e=(a->expo)+(tempb->expo);
result(c,e);
tempb=tempb->next;
}
a=a->next;
}
return(startr);
}

void display()
{
if(a==NULL || b==NULL)
{
printf("Create the two polynomials\n");
}
else
{
temp1=a;
while(temp1->next!=NULL)
{
printf("%dx^%d +  ",temp1->coeff,temp1->expo);
temp1=temp1->next;
}
printf("%dx^%d   ",temp1->coeff,temp1->expo);
printf("\n");

temp2=b;
while(temp2->next!=NULL)
{
printf("%dx^%d +  ",temp2->coeff,temp2->expo);
temp2=temp2->next;
}
printf("%dx^%d   ",temp2->coeff,temp2->expo);
printf("\n");

temp3=d;
while(temp3->next!=NULL)
{
printf("%dx^%d +  ",temp3->coeff,temp3->expo);
temp3=temp3->next;
}
printf("%dx^%d   ",temp3->coeff,temp3->expo);
printf("\n");
}
}

void main()
{
a=createpoly();
printf("\n");
b=createpoly();
printf("\n");
d=multiply(a,b);
display();
}

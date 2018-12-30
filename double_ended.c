#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1,size,q[100],item,k;

void insertion()
{
printf("Enter the item\n");
scanf("%d",&item);
if(f==r)
{
printf("Queue is full\n");
}
else if(f==-1)
{
f=0;
r=0;
q[r]=item;
}
else
{
if(f==0)
{
f=size-1;
}
else
{
f=f-1;
q[f]=item;
}
}
}

void deletion()
{
if(f==-1 && r==-1)
{
printf("Queue is empty\n");
}
else if(f==r)
{
k=q[r];
f=-1;
r=-1;
}
else if(r==0)
{
k=q[r];
r=size-1;
}
else
{
k=q[r];
r=r-1;
}
}

void display()
{




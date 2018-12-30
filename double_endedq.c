#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int queue[SIZE];
int F = -1;
int R = -1;

void insert_r(int x)
{
if(F == (R+1)%SIZE)
{
printf("\nQueue Overflow");
}
else if(R == -1)
{
F = 0;
R = 0;
queue[R] = x;
}
else
{
R = (R+1) %SIZE;
queue[R] = x;
}
}

void insert_f(int x)
{
if(F == (R+1)%SIZE)
{
printf("\nQueue Overflow");
}
else if(R == -1)
{
F = 0;
R = 0;
queue[R] = x;
}
else
{
F = (F+SIZE-1) %SIZE;
queue[F] = x;
}
}

int delete_r()
{
int x;
if(F == -1)
{
printf("\nQueue Underflow");
}
else if(F == R)
{
x = queue[F];
F = -1;
R = -1;
}
else
{
x = queue[R];
R = (R+SIZE-1)%SIZE;
}
return x;
}

int delete_f()
{
int x;
if(F == -1)
{
printf("\nQueue Underflow");
}
else if(F == R)
{
x = queue[F];
F = -1;
R = -1;
}
else
{
x = queue[F];
F = (F+1)%SIZE;
}
return x;
}

void main()
{
int choice;
int x;
while(1)
{
printf("1: Insert From Front\n");
printf("2: Insert From Rear\n");
printf("3: Delete From Front\n");
printf("4: Delete From Rear\n");
printf("5: Exit Program\n");
printf("Enter Your Choice:");
scanf("%d",&choice);
switch(choice)
{
case '1':
printf("\nEnter Integer Data :");
scanf("%d",&x);
insert_f(x);
break;
case '2':
printf("\nEnter Integer Data :");
scanf("%d",&x);
insert_r(x);
break;
case '3':
printf("\nDeleted Data From Front End: %d",delete_f());
break;
case '4':
printf("\nDeleted Data From Back End: %d",delete_r());
break;
case '5':
exit(0);
break;
}
}
}




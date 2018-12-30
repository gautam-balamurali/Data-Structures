#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[MAX],topA=-1,topB=MAX;
void pushA(int val)
{
if(topA==topB-1)
printf("\nOVERFLOW");

else
{
topA+=1;
stack[topA]=val;
}
}
int popA()
{
int val;
if(topA==-1)
{
printf("UNDERFLOW");
val=-999;
}
else{
val=stack[topA];
topA--;
}
return val;
}
void display_stackA()
{
int i;
if(topA==-1)
printf("Stack A is empty");

else{
for(i=topA;i>=0;i--)
printf("\t%d",stack[i]);
}
}
void pushB(int val)
{
if(topB-1==topA)
printf("OVERFLOW");
else
{
topB-=1;
stack[topB]=val;
}
}

 


int popB()
{

int val;
if(topB==MAX)
{
printf("underflow");
val=-999;

}
else{
val=stack[topB];
topB++;
}
return val;
}

void display_stackB()
{
int i;
if(topB==MAX)
printf("StackB is empty");
else{
for(i=topB;i<MAX;i++)
printf("%d",stack[i]);

}


}
void main()
{
int option,val;
do{
printf("\n1.PUSH IN STACK A");
printf("\n2.PUSH IN STACK B");
printf("\n3.POP FROM STACK A");
printf("\n4.POP FROM STACK B");
printf("\n5.DISPLAY STACK A");
printf("\n6.DISPLAY STACK B");
printf("\n7.EXIT");
printf("Enter your option");
scanf("%d",&option);

switch(option)
{
case 1:
printf("enter the value to push on stack A:");
scan("%d",&val);
pushA(val);
break;
case 2:
printf("enter the value to push on stack B:");
scan("%d",&val);
pushB(val);
break;
case 3:
val=popA();
if(val!=999)
printf("the value popped out of stack A is %d",val);
break;
case 4:
val=popB();
if(val!=999)
printf("the value popped out of stack B is %d",val);
break;
case 5:
printf("The elements of Stack A are");
display_stackA();
break;
case 6:
printf("The elements of Stack B are");
display_stackB();
break;
}
}while(option!=7);
getch();
}




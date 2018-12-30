#include<stdio.h>
#include<stdlib.h>
int maxsize;
int front=-1,rear=-1,i,queue[50];
void enqueue()
{
	int item;
	if(rear==(maxsize-1))
	{
		printf(" queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		printf("enter element\n");
		scanf("%d",&item);
		queue[rear]=item;
	}
	else
	{
		rear=rear+1;
		printf("enter element\n");
		scanf("%d",&item);
		queue[rear]=item;
	}
}
void dequeue()
{
	int k;
	if(front==-1&&rear==-1)
	{
		printf("queue is empty\n");
	}
	else if(front==rear)
	{
		k=queue[front];
		printf("deleted element is%d\n",k);
		front=-1;
		rear=-1;
	}
	else
	{
		k=queue[front];
		printf("%d\n",k);
		front=front+1;
	}
}
		
void display()
{
	if(front==-1&&rear==-1)
	{
		printf("queue is full\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}
void main()
{
	int d,m;
	printf("enter maxsize\n");
	scanf("%d",&maxsize);
	do
	{
	
		printf("\nMENU\n");
		printf("1.enqueue 2.dequeue 3.display 4.exit\n");
		printf("enter choice\n");
		scanf("%d",&d);
		switch(d)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:exit(0);
		}
	}
	while(d!=4);
}
		




#include<stdio.h>
#include<stdlib.h>
int a[100],size=0;
int builttree(int i)
{		
	char ch,temp;
	if(i!=-1)
	{
		int item;
		a[i]=item;
		printf("Whether node I requires left subtree?(y/n)\n");
		scanf("%c",&ch);
		printf("Enter the item\n");
		scanf("%d",&item);
		if(ch=='y')
		{
			builttree(2*i+1);
			size++;
		}
		else
		{
			builttree(-1);
		}
		printf("Whether node I requires right subtree?(y/n)\n");
		scanf("%c",&ch);
		if(ch=='y')
		{
			builttree(2*i+2);
			size++;
		}
		else
		{
			builttree(-1);
		}
	}
}

void search(int i,int key)
{
	int x;
	if(a[i]==key)
		return;
	if(2*i+1 <= size)
		x=search(2*i+1,key);
	else
		return -1;
	if(x==-1 && (2*i+2) <= size)
		x=search(2*i+2,key);
	return x;
}

void insert_begin()
{
	int l;
	l=search(0,key);
	if(l==-1)
	{
		printf("Search unsuccessful\n");
		exit();
	}
	if(a[2*l+1]==0 || a[2*l+2]==0)
	{
		printf("Enter option L/R\n");
		scanf("%c",&op);
		if(op=='L')
		{
			if(a[2*l+1]==0)
				a[2*l+1]=item;
				size++;
			else
				printf("Left child exists\n");
		}
		else if(op=='R')
		{
			if(a[2*l+2]==0)
				a[2*l+2]=item;
				size++;
			else
				printf("Right child exists\n");
		}
	}
	else
		printf("Operation cannot be performed\n");
}

void deletion()
{
	int l;
	l=search(0,key);
	if(l==-1)
	{
		printf("Unsuccessful\n");
		exit();
	}
	if(a[2*l+1]==0 && a[2*l+2]==0)
		a[l]=0;
	else
		printf("Node is not a leaf node\n");
}

void display()
{
	int i;
	for(i=0;i<=size;i++)
		printf("\t",a[i]);
	printf("\n");
}

void main()
{
int ch,item;
do
{
printf("1.Built Tree\n2.Search\n3.Insert at Beginning\n4.Deletion\n5.Display\n6.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:builttree(0);break;
case 2: search();break;
case 3: insert_begin();break;
case 4: deletion();break;
case 5: display();break;
case 6: exit(0);
}
}while(ch!=6);
}

	

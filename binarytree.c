#include<stdio.h>
#include<stdlib.h>
int a[50],n=0,j=0,key;
void builttree(int i,int item)
{
	int ch;
	if(i!=-1)
	{
		a[i]=item;
		n=n+1;
		printf("Whether node %d requires Left subtree??0/1:\n",a[i]);
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the item:\n");
			scanf("%d",&item);
			builttree(2*i+1,item);
		}
		else
		{	
			builttree(-1,0);
		}
		n=n+1;
		printf("Whether node %d requires Right subtree??0/1:\n",a[i]);
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the item:\n");
			scanf("%d",&item);
			builttree(2*i+2,item);
		}
		else
		{
			builttree(-1,0);
		}
	}
}
void display()
{
	for(j=0;j<n;j++)
	{	if(a[j]!=-1){
		printf("%d \t",a[j]);}
	}
printf("\n");
}
/*void display()
{
	for(j=0;j<50;j++)
	{
		if(a[j]!=-1){
		printf("%d \t",a[j]);}
	}
}*/
int search(int item)
{
	int h;
	for(h=0;h<n;h++)
	{
		if(a[h]==item)
		{
			return h;
		}
	}
	return -1;
}
void delete(int item)
{
	int m;
	m=search(item);
	if(m==-1)
	{
		printf("Item not found\n");
	}
	if(a[2*m+1]==-1 && a[2*m+2]==-1)
	{
		a[m]=-1;
	}
	else
	{
		printf("Node is not a leaf node\n");
	}
}
void insert(int key,int item)
{
	int m;
	int ch;
	m=search(key);
	if(m==-1)
	{
		printf("Search unsuccessful\n");
	}
	else
	{
		if(a[2*m+1]==-1 || a[2*m+2]==-1)
		{
			printf("Enter left or right child??(1/0):\n");
			scanf("%d",&ch);
			if(ch==1)
			{
				if(a[2*m+1]==-1)
				{
					a[2*m+1]=item;
				}
				else
				{
					printf("Left child exists\n");
				}
			}
			if(ch==0)
			{
				if(a[2*m+2]==-1)
				{
					a[2*m+2]=item;
				}
				else
				{
					printf("Right child exists\n");
				}
			}
		}
		else
		{
			printf("Operaion cannot be performed\n");
		}
	}
}
void main()
{
	int i=0,k,item,l,m;
	for(k=0;k<50;k++)
	{
		a[k]=-1;
	}
	do
	{
		printf("1.Build tree\n2.Insertion\n3.Deletion\n4.Search\n5.Display\n6.Exit\nEnter your option:\n");
		scanf("%d",&l);
		switch(l)
		{
			case 1:printf("Enter the item:\n");
				scanf("%d",&item);
				builttree(i,item);
				break;
			case 2:printf("Enter the element to be inserted:\n");
				scanf("%d",&item);
				printf("Enter the element after whilch you have to insert:\n");
				scanf("%d",&key);
				insert(key,item);
				break;
			case 3:printf("Enter the item to be deleted\n");
				scanf("%d",&item);
				delete(item);
				break; 
			case 4:printf("Enter the item to be searched:\n");
				scanf("%d",&item);
				m=search(item);
				if(m==-1)
				{
					printf("Item not found\n");
				}
				else
				{
					printf("Item found at %d\n",m);
				}
				break;
			case 5:display();
				break;
		}
	}while(l!=6);
}

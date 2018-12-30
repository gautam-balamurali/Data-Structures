#include<stdio.h>
#include<stdlib.h>
#define size 100
int a[size],n=0;

void insert_heap(int item)
{
	int i,p,temp;
	if(n>=size)
	{
		printf("Insertion not possible\n");
	}
	else
	{
		n=n+1;
		a[n]=item;
		i=n;
		p=i/2;
		while(p>0 && a[p]<a[i])
		{
			temp=a[p];
			a[p]=a[i];
			a[i]=temp;
			i=p;
			p=p/2;
		}
	}
}

void delete()
{
	int i,flag,lc,rc,x,y,temp;
	if(n==0)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		printf("Deleting %d ",a[1]);
		a[1]=a[n];
		n=n-1;
		i=1;
		
		flag=0;
		while(flag==0 && i<n)
		{
			lc=2*i;
			rc=2*i+1;
			if(lc<=n)
			{
				x=a[lc];
			}	
			else
			{
				x=-9999;
			}
			if(rc<n)
			{
				y=a[rc];
			}
			else
			{
				y=-9999;
			}
			if(a[i]>=x && a[i]>=y)
			{
				flag=1;
				
			}
			else if(x>=a[rc] && x>a[i])
			{
				temp=a[lc];
				a[lc]=a[i];
				a[i]=temp;
				i=lc;
			}
			else
			{
				temp=a[rc];
				a[rc]=a[i];
				a[i]=temp;
				i=rc;
			}
		}
	}
printf("\n");
}

void display()
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void main()
{
int item,ch;
do
{
printf("1.Insertion\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the item to be inserted\n");
       scanf("%d",&item);
       insert_heap(item);
       break;
case 2:delete();break;
case 3:display();break;
case 4:exit(0);
}
}while(ch!=4);
}

      		

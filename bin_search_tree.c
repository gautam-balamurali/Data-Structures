#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc;
	struct node *rc;
};
struct node *root=NULL,*parent,*ptr,*x,*ptr1;
void insertion()
{
	int item;
	printf("Enter the item\n");
	scanf("%d",&item);
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->lc=NULL;
	x->rc=NULL;
	if(root == NULL)
	{
		root=x;
	}
	else
	{
		ptr=root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if(item < ptr->data)
			ptr=ptr->lc;
			else if(item > ptr->data)
			ptr=ptr->rc;
		}
		if(item < parent->data)
		parent->lc=x;
		else if(item > parent->data)
		parent->rc=x;
	}
}

void search()
{
	int item;
	printf("Enter the item\n");
	scanf("%d",&item);
	int flag=0;
	ptr=root;
	while(ptr!=NULL && flag==0)
	{
		if(item < ptr->data)
		ptr=ptr->lc;
		else if(item > ptr->data)
		ptr=ptr->rc;
		else
		flag=1;
	}
	if(flag==1)
	printf("Element is present\n");
	else
	printf("Element is not present\n");
}

struct node *successor(struct node *ptr)
{
	ptr1=ptr->rc;
	if(ptr1!=NULL)
	{
		while(ptr1->lc!=NULL)
		{ptr1=ptr1->lc;}
	}
	return(ptr1);
}

void delete(int item1)
{
	struct node *ptr2;
	
	int flag=0;
	
	ptr2=root;
	flag=0;
	while(ptr2!=NULL && flag==0)
	{
		if(item1 < ptr2->data)
		{
			parent=ptr2;
			ptr2=ptr2->lc;
		}
		else if(item1 > ptr2->data)
		{
			parent=ptr2;
			ptr2=ptr2->rc;
		}
		else
		flag=1;
	}
	if(flag==0)
	printf("item not present\n");
	if(ptr2->lc == NULL && ptr2->rc == NULL)
	{
		if(parent->lc==ptr2)
		parent->lc=NULL;
		else if(parent->rc==ptr2)
		parent->rc=NULL;
		
	}
	else if(ptr2->lc != NULL && ptr2->rc != NULL)
	{
		ptr1=successor(ptr2);
		item1=ptr1->data;
		delete(item1);
		ptr2->data=item1;
	}
	else
	{
		if(parent->lc == ptr2)
		{
			if(ptr2->lc == NULL)
			parent->lc=ptr2->rc;
			else
			parent->lc=ptr2->lc;
		}
		else if(parent->rc == ptr2)
		{
			if(ptr2->lc==NULL)
			parent->rc=ptr2->rc;
			else
			parent->rc=ptr2->lc;
		}
	}
}



struct node *inorder(struct node *root)
{
	struct node *temp;
	temp=root;
	if(temp!=NULL)
	{
		inorder(temp->lc);
		printf("%d\n",temp->data);
		inorder(temp->rc);
	}
}

void main()
{
int ch,item1;
do
{
printf("1.Insertion\n2.Search\n3.Deletion\n4.Display\n5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insertion();break;
case 2: search();break;
case 3: printf("Enter the item to be deleted\n");
	scanf("%d",&item1);delete(item1);break;
case 4: inorder(root);break;
case 5: exit(0);
}
}while(ch!=5);
}



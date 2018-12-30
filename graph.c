#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *nxt;
};
struct node *graph[100];
int front=-1;
int rear=-1;
int top=-1;
int a[100];//stack
int b[100];//queue
void enqueue(int x)
{
if(front==-1 && rear==-1)
{
front=0;
rear=0;
b[front]=x;
}
else
{
rear=rear+1;
b[rear]=x;
}}
int dequeue()
{
int an;
if(front==rear)
{
an=b[front];
rear=-1;
front=-1;
return an;
}
else
{
an=b[front];
front=front+1;
return an;
}}
void push(int x)
{
	top=top+1;
	a[top]=x;
}
int pop()
{
	int q;
	q=a[top];
	top=top-1;
	return q;
}

int visit[100];
int visit2[100];
int sd=1;
int sd2=1;
int search(int item)
{
	int i,flag;
	flag=0;
	for(i=1;i<=sd;i++)
	{
	if(visit[i]==item)
	{
		flag=1;
	}
	}
	return flag;


}
int search2(int item)
{
	int i,flag;
	flag=0;
	for(i=1;i<=sd2;i++)
	{
	if(visit2[i]==item)
	{
		flag=1;
	}
	}
	return flag;
}
void insertion(int i)
{
	struct node *temp,*q,*p;
	int j,d,pt;
	printf("Enter number of nodes adj to %dth node\n",i );
	scanf("%d",&pt);
	for(j=0;j<pt;j++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&d);
		temp->data=d;
		temp->nxt=NULL;
		if(graph[i]==NULL)
		{
			graph[i]=temp;
		}
		else
		{
			p=graph[i];
			while(p->nxt!=NULL)
			{
				p=p->nxt;
			}
			p->nxt=temp;
		}
	}
}
void bfs(int q)
{

	int n,x,u,c;
	struct node *ptr;
	sd2=1;
	front=-1;
	rear=-1;
	if(graph==NULL)
	{
		printf("Graph is empty\n");
	}
	else
	{
		n=q;
		enqueue(n);
		while(front!=-1&& rear!=-1)
		{
			n=dequeue();
			x=search2(n);
			if(x==0)
			{
				visit2[sd2]=n;
				printf("%d\t",visit2[sd2]);
				sd2=sd2+1;
				ptr=graph[n];
				while(ptr!=NULL)
				{
					c=ptr->data;
					enqueue(c);
					ptr=ptr->nxt;
				}
			}
		}

	}
}
void dfs(int q)
{
top=-1;
sd=1;
struct node *ptr;
int u,x,c,i;
if(graph==NULL)
{
	printf("Graph is empty\n");
}
else
{
	u=q;
	push(u);
	while(top!=-1)
	{
		u=pop();
		x=search(u);
		if(x==0)
		{
			visit[sd]=u;
			printf("%d\t",visit[sd]);
			sd=sd+1;
			ptr=graph[u];

			while(ptr!=NULL)
			{
				c=ptr->data;
				push(c);
				ptr=ptr->nxt;
			}
		}
	}
}

}
void main()
{
int h;

int n,data,v,i,q;
do
{
printf("Menu\n1.create\n2.traversal bfs\n3.traversal dfs\n4.exit\nEnter your choice\n");
scanf("%d",&n);
switch(n)
{
case 1:
printf("Enter the number of vertices\n");
scanf("%d",&v);
for(h=1;h<=n;h++)
{
graph[h]=NULL;
}
for(i=1;i<=v;i++)
{
insertion(i);
}

break;
case 2:
printf("Enter starting value\n");
scanf("%d",&q);
bfs(q);
break;
case 3:
printf("Enter the starting value\n");
scanf("%d",&q);
dfs(q);
break;
case 4:
exit(0);
}}while(n!=4);
}

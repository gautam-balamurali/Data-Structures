#include<stdio.h>
#define size 100
void main()
{
	int a[size],i,j,n,k,c=0;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the values in array\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	printf("The elements are->\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Enter the element to be searched\n");
	scanf("%d",&k);
	for(i=1;i<=n;i++)
	{
		if(k==a[i])
		{
			printf("Search successful at location %d\n",i);
			c=1;
			break;
		}
	}
	if(c==0)
	{
		printf("Search unsuccessful\n");
	}
}
	
	

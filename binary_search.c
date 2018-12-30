#include<stdio.h>
#define size 100
int main()
{
	int a[size],i,j,n,temp,l,u,flag=0,mid,k;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	printf("Enter the values in array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n");
	printf("The elements are->\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
		
	printf("The sorted elements are->\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Enter the element to be searched\n");
	scanf("%d",&k);
	l=0;
	u=n-1;
	while(flag==0 && l<=u)
	{
		mid=(l+u)/2;
		if(k==a[mid])
		{
			printf("Successful\n");
			flag=1;
			return(mid);
		}
		if(k<a[mid])
		{
			u=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	if(flag==0)
	{
		printf("Unsuccessful\n");
		return(-1);
	}
}
		

#include<stdio.h>
int a[100];
int n;
void main()
{
	int item,j,i,f=0,l=0,m,temp,min;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elemets\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		m=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>m)
				a[j+1]=a[j];
			else
				break;
		}
		a[j+1]=m;
	}
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

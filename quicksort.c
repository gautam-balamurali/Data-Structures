#include<stdio.h>

int a[100];
int n;

void quicksort(int first,int last)
{

	int i,j,pivot,temp;
if(first<last)
{
	i=first;
	j=last;
	pivot=a[first];
	while(i<j)
	{
		while(a[i]<=pivot &&i<last)
		i=i+1;
		while(a[j]>=pivot &&j>first)
		j=j-1;
		if(i<j)
		{

		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	temp=a[j];
	a[j]=a[first];
	a[first]=temp;
	quicksort(first,j-1);
	quicksort(j+1,last);
}}
void main()
{
	int f=n-1,i,l=0;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter elemets\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);

	}

	quicksort(l,n-1);

	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

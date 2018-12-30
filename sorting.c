#include <stdio.h>
void main()
{

int a[100],i,n,j,temp;
printf("Enter no. of elements\n");
scanf("%d",&n);
printf("Insert the values in array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("The elements in the array are-->\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1-i;j++)
{
if(a[j+1]<a[j])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("The elements in the array after sorting are-->\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}




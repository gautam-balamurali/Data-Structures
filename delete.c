#include <stdio.h>
void main()
{
int a[100],i,j,n,val,pos;
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

printf("Enter the element to be deleted\n");
scanf("%d",&val);
for(i=0;i<n;i++)
{
if(a[i]==val)
{
pos=i;
for(j=pos;j<=n-2;j++)
{
a[j]=a[j+1];}
n=n-1;i=i-1;
printf("%d is deleted\n",val);
printf("\n");
}
}
printf("The array after deletion is\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}

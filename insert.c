#include <stdio.h>
void main()
{
int a[100],i,n,val,pos;
printf("Enter no. of elements\n");
scanf("%d",&n);
printf("Insert the values in array\n");
for(i=1;i<=n;i++)
{
scanf("%d",&a[i]);
}
printf("The elements in the array are-->\n");
for(i=1;i<=n;i++)
{
printf("%d ",a[i]);
}
printf("\n");

printf("Enter the element to be inserted\n");
scanf("%d",&val);
printf("Enter the position index where element is to be inserted\n");
scanf("%d",&pos);
for(i=n;i>=pos;i--)
{
a[i+1]=a[i];}
a[pos]=val;
n=n+1;
printf("The array after insertion-->\n");
for(i=1;i<=n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
}



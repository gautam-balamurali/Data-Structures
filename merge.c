#include <stdio.h>
void main()
{

int a[100],b[100],c[100],i=0,n1,n2,j=0,k=0,p;
printf("Enter no. of elements in 1st array\n");
scanf("%d",&n1);
printf("Insert the values in array\n");
for(i=0;i<n1;i++)
{
scanf("%d",&a[i]);
}
printf("The elements in the 1st array are-->\n");
for(i=0;i<n1;i++)
{
printf("%d ",a[i]);
}
printf("\n");

printf("Enter no. of elements in 2nd array\n");
scanf("%d",&n2);
printf("Insert the values in array\n");
for(i=0;i<n2;i++)
{
scanf("%d",&b[i]);
}
printf("The elements in the 2nd array are-->\n");
for(i=0;i<n2;i++)
{
printf("%d ",b[i]);
}
printf("\n");
i=0;j=0;k=0;
while(i<n1 && j<n2)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;k++;
}
else
{
c[k]=b[j];
j++;k++;
}
}
while(i<n1)
{
c[k]=a[i];
k++;
i++;
}
while(j<n2)
{
c[k]=b[j];
k++;
j++;
}
printf("The elements in the array after merging are-->\n");
for(i=0;i<n1+n2;i++)
{
printf("%d ",c[i]);
}
printf("\n");
}

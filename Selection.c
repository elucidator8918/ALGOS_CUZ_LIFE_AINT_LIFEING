#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,a[100],i,j,min;
printf("Enter the length of array\n");
scanf("%d",&n);
printf("Enter the elements of the array\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(a[min]>a[j])
min=j;
}
if(min!=i)
{
a[min]=a[min]+a[i];
a[i]=a[min]-a[i];
a[min]=a[min]-a[i];
}
}
printf("Sorted array\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}

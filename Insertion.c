#include<stdio.h>
#include<stdlib.h>

void main()
{
  int a[100],key,i,j,n;
  printf("Enter the length of the array\n");
  scanf("%d",&n);
  printf("Enter the elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=1;i<n;i++)
  {
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]<key)
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
  }
  printf("Sorted Array\n");
  for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}

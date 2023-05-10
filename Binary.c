#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool binarys(int a[],int low,int high,int search)
{
int mid=(low+high)/2;
if(low<=high)
{
  if(search==a[mid])
    return true;
  else if(search<a[mid])
    return binarys(a,low,mid-1,search);
  else
    return binarys(a,mid+1,high,search);
}
return false;
}

void main()
{
  int arr[100],i,n,search;
  printf("Enter the length of the array\n");
  scanf("%d",&n);
  printf("Enter the element to be searched\n");
  scanf("%d",&search);
  printf("Enter the elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  if(binarys(arr,0,n-1,search))
    printf("Search element found\n");
  else
    printf("Search element not found\n");
}

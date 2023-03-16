#include<stdio.h>
#define max 10
int main()
{
    int a[max],i,c,p,n,elt;
    printf("enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    //heapify
    heapify(arr);
    printf("Sorted elements in the array are:\n");
    for(i=1;i<=n;i++)
    printf("%d\n",arr[i]);
    return 0;
}
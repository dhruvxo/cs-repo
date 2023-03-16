#include<stdio.h>
#define max 10
int main()
{
    int a[max];
    int i,c,p,n,elt;
    printf("enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        elt=a[i];
        c=i;
        p=(c-1)/2;
        while(c>0 && a[p]<elt)
        {
            a[c]=a[p];
            c=p;
            p=(c-1)/2;
        }
        a[c]=elt;
    }
    printf("Sorted elements in the array are:\n");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
    return 0;
}
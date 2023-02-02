//sum of 3 numbers using pointers
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,sum=0,*ptr;
    printf("enter no of elements:");
    scanf("%d",&n);
    ptr= calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",ptr);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
        sum = sum + ptr[i];
    }
     printf("sum=%d",sum);
     return 0;
    }
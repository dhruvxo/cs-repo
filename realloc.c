#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1,n2,*ptr,i;
    printf("Enter n1:\n");
    scanf("%d",&n1);
    ptr= (int*)malloc(n1* sizeof(int));
    if(ptr=NULL)
    {
    printf("memory not allocated\n");
    exit(0);
    }
    for(i=0;i<n1;i++)
    printf("%p\n",ptr+i);
    printf("Enter n2:\n");
    scanf("%d",&n2);
    ptr=realloc(ptr,n2 *sizeof(int));
    for(i=0;i<n2;i++)
    printf("%p\n",ptr+i);
    return 0;
}
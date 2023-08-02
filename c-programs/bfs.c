#include<stdio.h>
void dfs(int n,int a[20][20],int src,int v[20])
{
    int i;
    v[src]=1;
    printf("%d",src);
    for(i=0;i<n;i++)
    {
        if(a[src][i]==1 && v[i]==0)
        {
            printf("-->");
            dfs(n,a,i,v);
        }
    }
}
int main()
{
    int i,src,j,n,count=0,a[20][20],v[20];
    printf("enter the no.of nodes\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    printf("enter src\n");
    scanf("%d",&src);
    for(i=0;i<n;i++)
    {
        v[i]=0;
    }
    dfs(n,a,src,v);
    for(i=0;i<n;i++)
    {
        if(v[i])
        {
            count=count+1;
        }
    }
    if(count==n)
    printf("\ntree is connected");
    else
    printf("\ntree is disconnected");
    return 0;
}
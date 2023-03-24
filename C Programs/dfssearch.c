#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
int dfs(int adj[MAX][MAX],int n,int visited[MAX],int src);

int main()
{
    int n;
    int adj[MAX][MAX]={0};
    int visited[MAX];
    int src,dest,res;

    scanf("%d,&n");
    printf("Enter the adjacency information\n");
    createGraph(adj,n);

    printf("Enter the source and dest vertex\n");
    scanf("%d%d",&src,&dest);

    res=dfs(adj,n,visited,src,dest);
    if(res)
    printf("There exists a path from %d to %d\n",src);
    else
    printf("There exists no path from %d to %d\ns",src);

    void createGraph(int adj[MAX][MAX],int n)
    {
        int src,dest;
        ...
    }

int dfs(int adj[MAX][MAX],int n,int visited[MAX],int src)
{
    visited[src]=1;
    for(int i=0;i<n;i++)
    {
        if(adj[src][i]&&visited[i]==0)
        if(i==dest || dfs(adj,n,visited,i,dest))
        return 1;
    }
    
    ...

}
}
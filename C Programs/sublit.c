#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct{
    unsigned int edge1;
    unsigned int edge2;
}edge;

bool dfs(unsigned int vertex, bool visited[], bool stack[], unsigned int parent, const edge *edges, unsigned int n)
{
    visited[vertex] = true;
    stack[vertex] = true;

    for(unsigned int i = 0; i < n; i++)
    {
        if(edges[i].edge1 == vertex || edges[i].edge2 == vertex)
        {
            unsigned int neighbor = edges[i].edge1 == vertex ? edges[i].edge2 : edges[i].edge1;

            if(!visited[neighbor])
            {
                if(dfs(neighbor, visited, stack, vertex, edges, n))
                {
                    return true;
                }
            }
            else if(stack[neighbor] && neighbor != parent)
            {
                return true;
            }
        }
    }

    stack[vertex] = false;
    return false;
}

bool cycle_finder(const edge *edges, unsigned int n, unsigned int order)
{
    bool visited[order];
    bool stack[order];

    for(unsigned int i = 0; i < order; i++)
    {
        visited[i] = false;
        stack[i] = false;
    }

    for(unsigned int i = 0; i < order; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, visited, stack, -1, edges, n))
            {
                return true;
            }
        }
    }

    return false;
}

int main(void)
{
    unsigned int order;
    unsigned int n;
    scanf("%u", &n);
    scanf("%u", &order);
    edge *edges;
    bool ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(unsigned int i=0;i<n;++i)
    {
        scanf("%u", &edges[i].edge1);
        scanf("%u", &edges[i].edge2);
    }
        
    ans= cycle_finder(edges, n, order);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 13
#define PRIME 7

void insertIntoHash(int key, int *hashtable)
{
    int index = key % SIZE;
    int step = PRIME - (key % PRIME);
    int i = 1;

    while (hashtable[index] != 0) {
        index = (index + i * step) % SIZE;
        i++;
        if (i == SIZE) {
            printf("Error: Hash table is full\n");
            exit(1);
        }
    }

    hashtable[index] = key;
}

void printHashTable(int *hashtable)
{
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", hashtable[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int stk[n];
    for (int k = 0; k < n; k++) {
        scanf("%d", &stk[k]);
    }

    int h[SIZE] = {0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (count == SIZE) {
            printf("-1\n");
            break;
        }
        if (stk[i] < 0) {
            continue;
        }
        insertIntoHash(stk[i], h);
        count++;
    }

    printHashTable(h);

    return 0;
}

//SUBLIT 2nd Q
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph {
int n; /* Number of vertices in graph */
int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

//creates the graph
void create_graph(Graph * adj_mat)
    {
        
        int i, j;
        for (int i = 0; i < adj_mat->n; ++i)
        {
            for (int j = 0; j < adj_mat->n; ++j)
            {
                adj_mat->adj[i][j] = 0;
            }
        }
        while (1)
        {
            //edge between two vertex
            scanf("%d %d\n", &i, &j);
            if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
            {
                break;
            }
            adj_mat->adj[i][j] = 1;
        }
    }
//helper functions for inserting an element into a queue 
void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}
//helper function to delete from a queue 
int delete (int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

int find_dist(Graph *adj_mat, int source, int dest) {
    // initialize queue and distance array
    int queue[MAX_NODES], front = -1, rear = -1;
    int dist[MAX_NODES];
    for (int i = 0; i < adj_mat->n; i++) {
        dist[i] = INFINITY;
    }
    dist[source] = 0;

    // enqueue the source vertex and start BFS
    append(queue, source, &rear);

    int is_empty(int front, int rear)
{
    return front == -1 || front > rear;
}

    while (!is_empty(front, rear)) {
        int u = delete(queue, &front);
        for (int v = 0; v < adj_mat->n; v++) {
            if (adj_mat->adj[u][v] == 1 && dist[v] == INFINITY) {
                dist[v] = dist[u] + 1;
                append(queue, v, &rear);
            }
        }
    }
    return dist[dest] == INFINITY ? -1 : dist[dest];
}

int main()
{
    Graph adj_mat;

    int source, dest;

    //number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    //source vertex
    scanf("%d\n", &source);

    //destination vertex
    scanf("%d", &dest);
    
    int result = find_dist(&adj_mat, source, dest);
    printf("%d",result);
    return 0;
}
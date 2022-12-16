
#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
// create a graph using user input
void createGraph(int v, int graph[v][v])
{
    int i, j;
    for (i = 0; i < v; i += 1)
    {
        for (j = 0; j < v; j += 1)
        {
            // printf("Is there an edge between %d and %d? (1/0): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
}
// print the graph
void printGraph(int v, int graph[v][v])
{
    int i, j;
    for (i = 0; i < v; i += 1)
    {
        for (j = 0; j < v; j += 1)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    struct queue q;

    int v, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int graph[v][v];
    createGraph(v, graph);
    printf("The graph is:");
    printGraph(v, graph);
    // vis array to keep track of visited nodes
    int vis[v];
    for (i = 0; i < v; i += 1)
    {
        vis[i] = 0;
    }
    // queue to keep track of nodes to be visited

    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // start from node 0
    int node;
    int s;
    printf("enter starting index");
    scanf("%d", &s);
    printf("%d", s);
    vis[s] = 1;
    enqueue(&q, s);

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);

        for (int i = 0; i < v; i++)
        {
            if (graph[node][i] == 1 && vis[i] == 0)
            {
                printf(" -> %d ", i);
                vis[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    return 0;
}
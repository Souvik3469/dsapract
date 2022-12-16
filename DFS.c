/*#include <stdio.h>
#include <stdlib.h>

typedef struct ll{
    int data;
    struct ll *nxt;
} Stack;

void push(Stack **sp, int data){
    Stack *temp = (Stack *) malloc(sizeof(Stack));
    temp->data = data;
    temp->nxt = *sp;
    *sp = temp;
}

int pop(Stack **sp){
    int data = (*sp)->data;
    *sp = (*sp)->nxt;
    return data;
}

int isEmpty(Stack *sp){
    return (sp == NULL);
}

void initialise(int v, int graph[v][v], int visited[v]){
    int i,j;
    for(i = 0; i<v; i+=1){
        visited[v] = 0;
        for(j = 0; j<v; j+=1){
            graph[i][j] = 0;
        }
    }
}

void printgraph(int v, int graph[v][v]){
    int i,j;
    for(i = 0; i<v; i+=1){
        for(j = 0; j<v; j+=1){
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

void creategraph(int v, int graph[v][v]){
    int connect,i,j;
    for(i = 0; i<v; i+=1){
        for(j = 0; j<v; j+=1){
            if(i == j) continue;
            printf("Connection from %d to %d (1 to connect, 0 to disconnect) -> ", i, j);
            scanf("%d", &connect);
            graph[i][j] = connect;
        }
    }
}

void dfs(int v, int graph[v][v], int visited[v], int start, Stack *sp){
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    visited[start] = 1;
    push(&sp, start);
    while(!isEmpty(sp)){
        int n = pop(&sp);
        int i;
        printf("%d ", n);
        visited[n] = 1;
        for(i = 0; i<v; i+=1){
            if(graph[n][i] == 1 && !visited[i]) push(&sp, i);
        }
    }
    printf("\n");
}

int main(){
    Stack *sp = NULL;
    int v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    int graph[v][v], visited[v];
    initialise(v, graph, visited);
    creategraph(v, graph);
    dfs(v, graph, visited, start, sp);
    printgraph(v, graph);
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

void DFS(int v, int s, int graph[v][v], int vis[v])
{
    printf("%d ", s);
    vis[s] = 1;
    for (int j = 0; j < v; j++)
    {
        if (graph[s][j] == 1 && !vis[j])
        {
            DFS(v, j, graph, vis);
        }
    }
}

int main()
{

    printf("enter the number of vertices");
    int v;
    scanf("%d", &v);
    int graph[v][v];
    // vis
    int vis[v];
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
    }

    // take user input for graph connection
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            // printf("Is there an edge between %d and %d? (1/0): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    int s = 0;
    printf("enter the starting index of dfs traversal");
    scanf("%d", &s);
    // print the graph
    printf("The graph is:");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }

    DFS(v, s, graph, vis);
    return 0;
}
//{0, 1, 1, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}, { 0, 0, 0, 1 }
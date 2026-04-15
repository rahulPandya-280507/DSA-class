#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX];
int n;
// BFS Function
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
// DFS Function
void DFS(int node)
{
    printf("%d ", node);
    visited[node] = 1;
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
int main()
{
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

            for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter starting node: ");
    scanf("%d", &start);
    printf("\nBFS Traversal: ");
    BFS(start);
    // Reset visited for DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    printf("\nDFS Traversal: ");
    DFS(start);
    return 0;
}
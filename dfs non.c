#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void dfs(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    int stack[MAX], top = -1;
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1) {
        int node = stack[top--];
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);   
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;  // For undirected graph
    }
    int start;
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(graph, visited, n, start);
    return 0;
}

#include <stdio.h>
#define MAX_VERTICES 10  
int adj[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];  
void dfs(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int I = 0; I < n; I++) {
        if (adj[vertex][I] == 1 && !visited[I]) {
            dfs(I, n);
        }
    }
}
int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (int I = 0; I < n; I++) {
        visited[I] = 0;
    }
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (int I = 0; I < n; I++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter the edges (u v):\n");
    for (int I = 0; I < e; I++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  
        adj[v][u] = 1;  
    }
    int startVertex;
    printf("Starting vertex:");
    scanf("%d",&startVertex);
    printf("DFS traversal:");
    dfs(startVertex, n);
    return 0;
}

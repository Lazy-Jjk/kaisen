#include <stdio.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX];

void bfs_non_recursive(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int cur = queue[front++];
        printf("%d ", cur);
        for (int i = 0; i < n; i++) {
            if (graph[cur][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, start;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    bfs_non_recursive(start, n);
    return 0;
}

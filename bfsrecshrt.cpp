#include <stdio.h>
#define MAX 100

int graph[MAX][MAX], visited[MAX], queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
  if (rear < MAX - 1) queue[++rear] = v; 
  if (front == -1) front = 0; 
}
int dequeue() { 
 return (front <= rear) ? queue[front++] : -1; 
}

void bfs(int start, int n) {
    enqueue(start); 
	visited[start] = 1;
    while (front <= rear) {
        int cur = dequeue();
		printf("%d ", cur);
        for (int i = 0; i < n; i++)
            if (graph[cur][i] && !visited[i]) {
			enqueue(i), visited[i] = 1;
		}
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, start;
    printf("Enter no.of vertices and edges:");
    scanf("%d %d", &n, &edges);
    printf("Enter Edge (u v):");
    while (edges--) {
		scanf("%d %d", &u, &v);
		graph[u][v] = graph[v][u] = 1;
	}
	printf("Enter starting vertex:");
    scanf("%d", &start);
	bfs(start, n);
    return 0;
}

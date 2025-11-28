#include <stdio.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
if (rear == MAX - 1) return;
if (front == -1) front = 0;
queue[++rear] = x;
}
int dequeue() {
if (front == -1 || front > rear) return -1;
return queue[front++];
}
int isEmpty() {
return (front == -1 || front > rear);
}
int main() {
int n, start;
int adj[MAX][MAX];
int visited[MAX] = {0};
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter adjacency matrix:\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
scanf("%d", &adj[i][j]);
printf("Enter starting vertex (0 to %d): ", n-1);
scanf("%d", &start);
enqueue(start);
visited[start] = 1;
printf("BFS Traversal: ");
while (!isEmpty()) {
int v = dequeue();
printf("%d ", v);
for (int i = 0; i < n; i++) {
if (adj[v][i] == 1 && visited[i] == 0) {
enqueue(i);
visited[i] = 1;
}
}
}
printf("\n");
return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX], visited[MAX];
int n;

void bfs(int start) {
    int queue[MAX], front = -1, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[start][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("BFS Traversal: ");
    bfs(0); // Starting from vertex 0

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");
    dfs(0); // Starting from vertex 0

    return 0;
}

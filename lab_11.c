#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int a[MAX][MAX], n, visited[MAX];
int q[MAX], front = -1, rear = -1;

void bfs(int v) {
    visited[v] = 1;
    q[++rear] = v;
    printf("%d ", v);
    while (front < rear) {
        int cur = q[++front];
        for (int i = 1; i <= n; i++) {
            if (a[cur][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                q[++rear] = i;
            }
        }
    }
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void reset_visited() {
    for (int i = 1; i <= n; i++) visited[i] = 0;
}

int main() {
    int ch, start;

    printf("\nEnter the number of vertices in graph: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (0 or 1):\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    while (1) {
        printf("\n==> 1. BFS\n==> 2. DFS\n==> 3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nBFS starting from vertex %d: ", start);
                reset_visited();
                bfs(start);
                printf("\n");
                break;
            case 2:
                printf("\nDFS starting from vertex %d: ", start);
                reset_visited();
                dfs(start);
                printf("\n");
                break;
            case 3:
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}

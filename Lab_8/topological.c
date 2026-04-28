#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// Function to perform DFS
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    // Push vertex to stack after visiting all adjacent vertices
    stack[++top] = v;
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS for all unvisited vertices
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print Topological Order (reverse of stack)
    printf("Topological Ordering:\n");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}

#include <stdio.h>

#define MAX 10
#define INF 9999

int main() {
    int n, cost[MAX][MAX], dist[MAX], visited[MAX];
    int i, j, u, v, min, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialization
    for(i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Main algorithm
    for(i = 1; i < n; i++) {
        min = INF;

        // Find minimum distance vertex
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for(v = 0; v < n; v++) {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Output
    printf("\nShortest distances from vertex %d:\n", source);
    for(i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}

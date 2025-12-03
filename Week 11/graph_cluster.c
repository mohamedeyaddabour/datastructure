#include <stdio.h>

/*
Input is done by adjacency matrix.
This program finds and prints all clusters in an undirected graph.

Example Input:

        Enter number of nodes: 5

        Enter adjacency matrix:
                0 1 0 0 0
                1 0 1 0 0
                0 1 0 0 0
                0 0 0 0 1
                0 0 0 1 0

Example Output:
        Cluster 1: 0 1 2
        Cluster 2: 3 4

*/


#define MAX 100

int visited[MAX];
int graph[MAX][MAX];
int n;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int clusterCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d:", clusterCount);

            dfs(i);

            // print all nodes belonging to this cluster
            for (int j = 0; j < n; j++) {
                if (visited[j] == 1) {
                    printf(" %d", j);
                    visited[j] = 2; // mark as printed (so next cluster skips)
                }
            }

            printf("\n");
        }
    }

    return 0;
}


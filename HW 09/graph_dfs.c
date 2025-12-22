/*
 * Description: Depth First Search (DFS) Implementation.
 * Explores as deep as possible along each branch before backtracking.
 * Implemented using an Adjacency Matrix and Recursion.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 6

void dfsRecursive(int graph[MAX_NODES][MAX_NODES], int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            dfsRecursive(graph, i, visited);
        }
    }
}

int main() {
    // 6 nodes graph (0 to 5)
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0}, // 0 connects to 1, 2
        {1, 0, 0, 1, 0, 0}, // 1 connects to 0, 3
        {1, 0, 0, 0, 1, 0}, // 2 connects to 0, 4
        {0, 1, 0, 0, 0, 0}, // 3 connects to 1
        {0, 0, 1, 0, 0, 1}, // 4 connects to 2, 5
        {0, 0, 0, 0, 1, 0}  // 5 connects to 4
    };

    bool visited[MAX_NODES] = {false};
    
    printf("DFS Traversal starting from Node 0: ");
    dfsRecursive(graph, 0, visited);
    printf("\n");

    return 0;
}
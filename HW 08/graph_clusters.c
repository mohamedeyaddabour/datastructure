/*
 * Description: Finding Clusters (Connected Components) in a Graph given as an Array (Adjacency Matrix).
 * I use a simple DFS approach. We iterate through every node. If a node hasn't been visited,
 * we start a traversal and print all nodes reachable from it. That group is one "Cluster".
 */

#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Recursive DFS to visit all nodes in a cluster
void DFS(int adj[V][V], int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v); // Print node as part of current cluster

    for (int i = 0; i < V; i++) {
        // If connected and not visited
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(adj, i, visited);
        }
    }
}

// Function to find all connected components
void findClusters(int adj[V][V]) {
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;

    int clusterCount = 0;
    
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // Found a new unvisited node, start of a new cluster
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            DFS(adj, v, visited);
            printf("}\n");
        }
    }
}

int main() {
    // Adjacency Matrix
    // 0 is connected to 1
    // 3 is connected to 4
    // 2 is isolated
    int adj[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    printf("Graph Cluster Extraction:\n");
    findClusters(adj);
    
    return 0;
}
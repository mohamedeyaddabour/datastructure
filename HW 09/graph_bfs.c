/*
 * Description: Breadth First Search (BFS) Implementation.
 * Explores neighbor nodes first before moving to the next level neighbors.
 * Uses a Queue to manage the visitation order.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 6

// --- Simple Queue Implementation for BFS ---
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX_NODES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = val;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return (front == -1 || front > rear);
}
// ------------------------------------------

void bfs(int graph[MAX_NODES][MAX_NODES], int startNode) {
    bool visited[MAX_NODES] = {false};

    visited[startNode] = true;
    enqueue(startNode);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        // Visit neighbors
        for (int i = 0; i < MAX_NODES; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main() {
    // Same graph structure as DFS example
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0}, // 0-1, 0-2
        {1, 0, 0, 1, 0, 0}, // 1-3
        {1, 0, 0, 0, 1, 0}, // 2-4
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1}, // 4-5
        {0, 0, 0, 0, 1, 0}
    };

    printf("BFS Traversal starting from Node 0: ");
    bfs(graph, 0);
    printf("\n");

    return 0;
}
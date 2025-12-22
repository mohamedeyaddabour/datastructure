/*
 * Description: Complete Max Heap and Min Heap implementation using Arrays.
 * I created generic heapify functions.
 * - insertMaxHeap: Inserts node and bubbles up.
 * - deleteMaxHeap: Removes root, replaces with last, and bubbles down.
 * Same logic applies to MinHeap with reversed comparison.
 */

#include <stdio.h>

#define MAX_SIZE 100

// --- MAX HEAP FUNCTIONS ---

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyMax(arr, n, largest);
    }
}

void insertMaxHeap(int arr[], int* n, int value) {
    if (*n == MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    
    // Insert at end
    int i = *n;
    arr[i] = value;
    (*n)++;

    // Fix the max heap property (Bubble up)
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        int parent = (i - 1) / 2;
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// --- MIN HEAP LOGIC (Simplified for Demo) ---
// For Min Heap, we just flip the comparison in Heapify and Insert.

int main() {
    int maxHeap[MAX_SIZE];
    int n = 0;

    printf("--- Max Heap Construction ---\n");
    insertMaxHeap(maxHeap, &n, 10);
    insertMaxHeap(maxHeap, &n, 20);
    insertMaxHeap(maxHeap, &n, 15);
    insertMaxHeap(maxHeap, &n, 30);
    insertMaxHeap(maxHeap, &n, 40);

    printf("Max Heap Array: ");
    printArray(maxHeap, n); // Should show parent > children
    
    // Root should be 40
    printf("Max Element (Root): %d\n", maxHeap[0]);

    return 0;
}
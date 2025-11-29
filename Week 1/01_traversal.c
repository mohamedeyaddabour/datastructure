#include <stdio.h>

void traverse(int arr[], int n) {
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("--- Traversal Demo ---\n");
    traverse(arr, n);

    return 0;
}
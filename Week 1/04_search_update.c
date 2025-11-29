#include <stdio.h>

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

void update(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Error: Invalid Position\n");
        return;
    }
    arr[pos] = value;
    printf("Updated Index %d to %d.\n", pos, value);
}

int main() {
    int arr[100] = {5, 10, 15, 20, 25};
    int n = 5;

    traverse(arr, n);

    int key = 15;
    int idx = search(arr, n, key);
    if (idx != -1) printf("Found %d at index %d\n", key, idx);
    else printf("%d not found\n", key);

    update(arr, n, 0, 999);
    traverse(arr, n);

    return 0;
}
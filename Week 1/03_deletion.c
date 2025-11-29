#include <stdio.h>

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void deleteEnd(int *n) {
    if (*n > 0) {
        (*n)--;
        printf("Deleted from End.\n");
    }
}

void deleteBeginning(int arr[], int *n) {
    if (*n == 0) return;
    for (int i = 0; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted from Beginning.\n");
}

void deleteAt(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Error: Invalid Position\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted from Index %d.\n", pos);
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("Original: ");
    traverse(arr, n);

    deleteBeginning(arr, &n);
    deleteEnd(&n);
    deleteAt(arr, &n, 1);

    printf("Result:   ");
    traverse(arr, n);
    return 0;
}
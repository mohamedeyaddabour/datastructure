#include <stdio.h>

void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertEnd(int arr[], int *n, int value) {
    arr[*n] = value;
    (*n)++;
    printf("Inserted %d at End.\n", value);
}

void insertBeginning(int arr[], int *n, int value) {
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
    printf("Inserted %d at Beginning.\n", value);
}

int insertAt(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n) {
        printf("Error: Invalid Position\n");
        return -1;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    printf("Inserted %d at Index %d.\n", value, pos);
    return 0;
}

int main() {
    int arr[100] = {1, 2, 3};
    int n = 3;

    printf("Original: ");
    traverse(arr, n);

    insertBeginning(arr, &n, 0);
    insertEnd(arr, &n, 9);
    insertAt(arr, &n, 2, 99);

    printf("Result:   ");
    traverse(arr, n);

    return 0;
}
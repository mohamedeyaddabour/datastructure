#include <stdio.h>

#define MAX 100

void traverse(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("\nCurrent Array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("] (Size: %d)\n", n);
}

void insertEnd(int arr[], int *n, int value) {
    if (*n >= MAX) { printf("Array Full!\n"); return; }
    arr[*n] = value;
    (*n)++;
    printf("Inserted %d at end.\n", value);
}

void insertBeginning(int arr[], int *n, int value) {
    if (*n >= MAX) { printf("Array Full!\n"); return; }
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*n)++;
    printf("Inserted %d at beginning.\n", value);
}

void insertAt(int arr[], int *n, int pos, int value) {
    if (*n >= MAX) { printf("Array Full!\n"); return; }
    if (pos < 0 || pos > *n) { printf("Invalid position!\n"); return; }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    printf("Inserted %d at index %d.\n", value, pos);
}

void deleteEnd(int *n) {
    if (*n <= 0) { printf("Array Empty!\n"); return; }
    (*n)--;
    printf("Deleted last element.\n");
}

void deleteBeginning(int arr[], int *n) {
    if (*n <= 0) { printf("Array Empty!\n"); return; }
    for (int i = 0; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted first element.\n");
}

void deleteAt(int arr[], int *n, int pos) {
    if (*n <= 0) { printf("Array Empty!\n"); return; }
    if (pos < 0 || pos >= *n) { printf("Invalid position!\n"); return; }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted element at index %d.\n", pos);
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

void update(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) { printf("Invalid position!\n"); return; }
    arr[pos] = value;
    printf("Updated index %d to value %d.\n", pos, value);
}

int main() {
    int arr[MAX];
    int n = 0;
    int choice, val, pos;

    while (1) {
        printf("\n=== ARRAY MASTER ===\n");
        printf("1. Insert End\n");
        printf("2. Insert Beginning\n");
        printf("3. Insert At Position\n");
        printf("4. Delete End\n");
        printf("5. Delete Beginning\n");
        printf("6. Delete At Position\n");
        printf("7. Search\n");
        printf("8. Update\n");
        printf("9. Show Array\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: "); scanf("%d", &val);
                insertEnd(arr, &n, val);
                break;
            case 2:
                printf("Value: "); scanf("%d", &val);
                insertBeginning(arr, &n, val);
                break;
            case 3:
                printf("Position: "); scanf("%d", &pos);
                printf("Value: "); scanf("%d", &val);
                insertAt(arr, &n, pos, val);
                break;
            case 4:
                deleteEnd(&n);
                break;
            case 5:
                deleteBeginning(arr, &n);
                break;
            case 6:
                printf("Position: "); scanf("%d", &pos);
                deleteAt(arr, &n, pos);
                break;
            case 7:
                printf("Value to search: "); scanf("%d", &val);
                pos = search(arr, n, val);
                if (pos != -1) printf("Found at index %d\n", pos);
                else printf("Not found.\n");
                break;
            case 8:
                printf("Position: "); scanf("%d", &pos);
                printf("New Value: "); scanf("%d", &val);
                update(arr, n, pos, val);
                break;
            case 9:
                traverse(arr, n);
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
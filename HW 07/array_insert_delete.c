/*
 * Description: Simple array manipulation.
 * - insertElement: Shifts elements to the right to make space.
 * - deleteElement: Shifts elements to the left to fill gap.
 * Checks for array bounds included.
 */

#include <stdio.h>

#define CAPACITY 10

void insertElement(int arr[], int* size, int pos, int value) {
    if (*size >= CAPACITY) {
        printf("Array is full!\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos] = value;
    (*size)++;
    printf("Inserted %d at index %d.\n", value, pos);
}

void deleteElement(int arr[], int* size, int pos) {
    if (*size == 0) {
        printf("Array is empty!\n");
        return;
    }
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }

    int deletedVal = arr[pos];

    // Shift elements to the left
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Deleted %d from index %d.\n", deletedVal, pos);
}

void printArray(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[CAPACITY] = {10, 20, 30, 40};
    int size = 4;

    printArray(arr, size);

    // Add 25 at index 2
    insertElement(arr, &size, 2, 25);
    printArray(arr, size);

    // Delete index 0
    deleteElement(arr, &size, 0);
    printArray(arr, size);

    return 0;
}
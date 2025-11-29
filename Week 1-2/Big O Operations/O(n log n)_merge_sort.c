#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    // Merging takes O(n)
}

void merge_sort(int arr[], int l, int r) {

    // merge sort splits array into halves:
    // Recurrence: T(n) = 2T(n/2) + O(n)
    // Using Master theorem → O(n log n)

    if (l < r) {
        int m = (l + r) / 2;

        merge_sort(arr, l, m);      // T(n/2)
        merge_sort(arr, m + 1, r);  // T(n/2)

        merge(arr, l, m, r);        // O(n)
    }
}

int main() {
    int arr[] = {5, 3, 8, 6, 2};
    merge_sort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    return 0;
}

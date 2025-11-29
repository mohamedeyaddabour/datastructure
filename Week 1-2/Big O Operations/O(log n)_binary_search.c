#include <stdio.h>

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    // While loop halves the array each time:
    // T(n) = log₂(n)
    // Big O = O(log n)

    while (left <= right) {  // O(log n)
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = 8;

    int index = binary_search(arr, n, 10);
    printf("%d", index);

    return 0;
}

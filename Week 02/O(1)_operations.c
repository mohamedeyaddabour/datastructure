#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // O(1) → Accessing an element
    int x = arr[2];   // O(1)

    // O(1) → Assigning new value
    arr[4] = 99;      // O(1)

    printf("%d %d\n", x, arr[4]);
    return 0;
}

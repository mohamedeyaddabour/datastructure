#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    // Summation of complexity:
    // for loop runs n times → T(n) = n
    // Final Big O = O(n)

    for (int i = 0; i < n; i++) {   // O(n)
        printf("%d ", arr[i]);
    }

    return 0;
}

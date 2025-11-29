#include <stdio.h>

int main() {
    int n = 4;

    // Nested loop:
    // Outer loop: n
    // Inner loop: n
    // Total = n * n = n²
    // T(n) = n² + n  → O(n²)

    for (int i = 0; i < n; i++) {           // runs n times
        for (int j = 0; j < n; j++) {       // runs n times
            printf("* ");                   // O(1)
        }
        printf("\n");
    }

    return 0;
}

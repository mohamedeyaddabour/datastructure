#include <stdio.h>

int main() {
    int n = 100;

    // Loop runs while i*i <= n
    // i = 1, 2, 3, ..., √n
    //
    // Solve condition:
    // i^2 ≤ n
    // i ≤ √n
    //
    // So loop executes √n times → O(√n)

    for (int i = 1; i * i <= n; i++) {
        printf("%d ", i);  // O(1)
    }

    return 0;
}

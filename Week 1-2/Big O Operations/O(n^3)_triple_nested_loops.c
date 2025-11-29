#include <stdio.h>

int main() {
    int n = 4;

    // 3 nested loops:
    //
    // i loop → n times
    // j loop → n times
    // k loop → n times
    //
    // Total operations:
    // T(n) = n * n * n = n³
    // Final Big O = O(n³)

    for (int i = 0; i < n; i++) {        // n
        for (int j = 0; j < n; j++) {    // n
            for (int k = 0; k < n; k++) {// n
                printf("*");            // O(1)
            }
        }
    }

    return 0;
}

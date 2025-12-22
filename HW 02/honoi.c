/*
 * Description: Recursive solution for the Tower of Hanoi problem.
 * It moves n disks from a source rod to a destination rod using an auxiliary rod.
 * The logic prints every move step-by-step.
 */

#include <stdio.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: If only 1 disk, just move it
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Move top n-1 disks from A to B, using C as aux
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move remaining disk from A to C
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Move n-1 disks from B to C, using A as aux
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // Number of disks
    printf("Tower of Hanoi Solution for %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B'); // A: Source, C: Destination, B: Auxiliary
    return 0;
}
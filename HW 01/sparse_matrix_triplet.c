/*
 * Description: This code converts a standard 2D matrix into a Sparse Matrix 
 * using the Triplet (Coordinate) Representation.
 * I specifically iterate through the matrix first to count non-zero elements 
 * to allocate the exact size needed for the triplet array.
 * Row 0 of the triplet stores the metadata (total rows, total cols, total non-zero values).
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 5

// Function to convert 2D array to Triplet format
void createTriplet(int matrix[ROWS][COLS]) {
    int i, j, k = 1;
    int count = 0;

    // First pass: Count non-zero elements
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0)
                count++;
        }
    }

    // Create triplet array. Size is count + 1 (for metadata row)
    // using 3 columns: [Row, Col, Value]
    int triplet[count + 1][3];

    // Metadata row
    triplet[0][0] = ROWS;
    triplet[0][1] = COLS;
    triplet[0][2] = count;

    // Second pass: Fill the triplet
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Print result
    printf("\nSparse Matrix (Triplet Representation):\n");
    printf("Row\tCol\tValue\n");
    printf("-------------------\n");
    for (i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

int main() {
    // Example matrix with many zeros
    int sparseMatrix[ROWS][COLS] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    createTriplet(sparseMatrix);

    return 0;
}
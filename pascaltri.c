#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    if (numRows == 0) return NULL;

    // 1. Allocate memory for the pointers to each row
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // 2. Each row 'i' has 'i + 1' elements
        int rowSize = i + 1;
        (*returnColumnSizes)[i] = rowSize;
        triangle[i] = (int*)malloc(rowSize * sizeof(int));

        // 3. Set the first and last elements of the row to 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // 4. Fill in the interior elements
        for (int j = 1; j < i; j++) {
            // Each middle element is the sum of the two elements above it
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}

Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.


Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true


bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
     for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[0]; j++) {
            if (matrix[i][j] != matrix[i-1][j-1]) {
                return false;
            }
        }
    }
    return true;

}
Given an m x n matrix, return all elements of the matrix in spiral order.

 1->2->3->6->9->8->7->4->5

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

int m = matrixSize;
    int n = *matrixColSize;
    *returnSize = m * n;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int index = 0;
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
          if (top <= bottom) {
               for (int i = right; i >= left; i--) {
                   result[index++] = matrix[bottom][i];
            }
               bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
     if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int size = rear - front;
        (*returnColumnSizes)[level] = size;
        result[level] = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            result[level][i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        level++;
    }

    *returnSize = level;
    free(queue);
    return result;
}

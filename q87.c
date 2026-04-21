Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void helper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    arr[(*index)++] = root->val;
    helper(root->left, arr, index);
    helper(root->right, arr, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 10000);
    int index = 0;
    helper(root, arr, &index);
    *returnSize = index;
    return arr;
}
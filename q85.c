94. Binary Tree Inorder Traversal
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

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
    helper(root->left, arr, index);
    arr[(*index)++] = root->val;
    helper(root->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 10000);
    int index = 0;
    helper(root, arr, &index);
    *returnSize = index;
    return arr;
}
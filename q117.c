You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

 

Example 1:


Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int dfs(struct TreeNode* root, int* cameras) {
    if (root == NULL) return 1;

    int left = dfs(root->left, cameras);
    int right = dfs(root->right, cameras);

    if (left == 2 || right == 2) {
        (*cameras)++;
        return 0;
    }

    if (left == 0 || right == 0) {
        return 1;
    }

    return 2;
}
int minCameraCover(struct TreeNode* root) {
     int cameras = 0;
    if (dfs(root, &cameras) == 2) {
        cameras++;
    }
    return cameras;
}
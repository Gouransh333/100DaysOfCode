Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end) return NULL;

    struct TreeNode* root = newNode(preorder[(*preIndex)++]);

    if (start == end) return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
     int preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIndex);
}
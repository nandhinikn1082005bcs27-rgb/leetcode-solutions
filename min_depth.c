/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

// Helper to get minimum of two integers
int getMin(int a, int b) {
    return (a < b) ? a : b;
}

int minDepth(struct TreeNode* root) {
    // Base Case: Empty tree
    if (root == NULL) return 0;

    // Case 1: Left subtree is empty, check right
    if (root->left == NULL) return 1 + minDepth(root->right);

    // Case 2: Right subtree is empty, check left
    if (root->right == NULL) return 1 + minDepth(root->left);

    // Case 3: Both subtrees exist, find the shorter path
    return 1 + getMin(minDepth(root->left), minDepth(root->right));
}

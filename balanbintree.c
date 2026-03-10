/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function: returns height if balanced, or -1 if unbalanced
int checkHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Check left subtree
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    // Check right subtree
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    // If the difference in heights is > 1, the current node is unbalanced
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    // Return the actual height of the node
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode* root) {
    // If checkHeight returns -1, the tree is not balanced
    return checkHeight(root) != -1;
}

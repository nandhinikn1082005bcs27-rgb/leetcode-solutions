#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int targetSum) {
    // 1. Base case: If the current node is NULL, the path is invalid.
    if (root == NULL) {
        return false;
    }

    // 2. Check if the current node is a leaf (no children).
    // If it is, check if its value matches the remaining targetSum.
    if (root->left == NULL && root->right == NULL) {
        return targetSum == root->val;
    }

    // 3. Recurse down to the left and right subtrees.
    // Subtract the current node's value from the targetSum for the next level.
    int remainingSum = targetSum - root->val;
    
    return hasPathSum(root->left, remainingSum) || 
           hasPathSum(root->right, remainingSum);
}

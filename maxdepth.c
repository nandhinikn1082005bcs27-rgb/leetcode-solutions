/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDepth(struct TreeNode* root) {
    // Base case: if node is null, depth is 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively find depth of left and right subtrees
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    // Return 1 (current node) + maximum of child subtrees
    return 1 + MAX(left, right);
}

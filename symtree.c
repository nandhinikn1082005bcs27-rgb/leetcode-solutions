/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to check if two subtrees are mirrors of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // Both subtrees are empty
    if (t1 == NULL && t2 == NULL) return true;
    
    // Only one is empty or values differ
    if (t1 == NULL || t2 == NULL || t1->val != t2->val) return false;
    
    // Check outer symmetry (t1 left, t2 right) and inner symmetry (t1 right, t2 left)
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

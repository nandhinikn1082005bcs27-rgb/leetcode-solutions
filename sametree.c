/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // 1. Both are null, so they are the same
    if (p == NULL && q == NULL) return true;

    // 2. One is null or values differ, so they are not the same
    if (p == NULL || q == NULL || p->val != q->val) return false;

    // 3. Recursively check left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

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
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = (int*)malloc(100 * sizeof(int)); // LeetCode constraints: max 100 nodes
    *returnSize = 0;
    struct TreeNode* curr = root;
    struct TreeNode* pre;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // Case 1: No left child, visit this node and go right
            res[(*returnSize)++] = curr->val;
            curr = curr->right;
        } else {
            // Case 2: Has left child, find the inorder predecessor
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                // Create a temporary thread to the current node
                pre->right = curr;
                curr = curr->left;
            } else {
                // Thread already exists; left subtree is done. 
                // Remove thread, visit current, and move right.
                pre->right = NULL;
                res[(*returnSize)++] = curr->val;
                curr = curr->right;
            }
        }
    }
    return res;
}

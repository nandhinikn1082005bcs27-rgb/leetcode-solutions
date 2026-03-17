/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) return NULL;

    // Pick middle element as root to maintain balance
    int mid = left + (right - left) / 2;
    
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    
    // Recursively build left and right subtrees
    node->left = helper(nums, left, mid - 1);
    node->right = helper(nums, mid + 1, right);
    
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}

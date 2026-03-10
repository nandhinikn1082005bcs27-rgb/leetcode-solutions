/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

// Helper function to build the tree recursively
struct TreeNode* buildBST(int* nums, int left, int right) {
    // Base case: if left index exceeds right, the subarray is empty
    if (left > right) {
        return NULL;
    }

    // Find the middle element to keep the tree balanced
    int mid = left + (right - left) / 2;

    // Create a new node with the middle value
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];

    // Recursively build the left and right subtrees
    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
}

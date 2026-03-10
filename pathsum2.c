#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findPaths(struct TreeNode* root, int targetSum, int* currentPath, int pathIdx, 
               int*** results, int* returnSize, int** returnColumnSizes) {
    if (!root) return;

    // Add current node to path and update remaining target
    currentPath[pathIdx++] = root->val;
    targetSum -= root->val;

    // Check if it's a leaf node and matches the target
    if (!root->left && !root->right && targetSum == 0) {
        // Allocate space for the new valid path found
        (*results)[*returnSize] = (int*)malloc(pathIdx * sizeof(int));
        for (int i = 0; i < pathIdx; i++) {
            (*results)[*returnSize][i] = currentPath[i];
        }
        (*returnColumnSizes)[*returnSize] = pathIdx;
        (*returnSize)++;
    } else {
        // Recurse down left and right subtrees
        findPaths(root->left, targetSum, currentPath, pathIdx, results, returnSize, returnColumnSizes);
        findPaths(root->right, targetSum, currentPath, pathIdx, results, returnSize, returnColumnSizes);
    }
    // Backtracking: The index pathIdx naturally resets as we return from recursion
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    // Pre-allocate memory based on constraints (max nodes 5000)
    int** results = (int**)malloc(5000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(5000 * sizeof(int));
    int* currentPath = (int*)malloc(5000 * sizeof(int));

    findPaths(root, targetSum, currentPath, 0, &results, returnSize, returnColumnSizes);

    free(currentPath);
    return results;
}

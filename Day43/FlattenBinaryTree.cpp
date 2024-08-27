// Leetcode question number 114 :
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Store the right subtree
        TreeNode* rightSubtree = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = NULL; // Set the left subtree to NULL

        // Find the rightmost node of the new right subtree
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }

        // Attach the original right subtree to the rightmost node
        current->right = rightSubtree;
    }
};

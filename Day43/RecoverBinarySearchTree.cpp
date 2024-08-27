// Leetcode question number 99 :
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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        // Perform an in-order traversal and find the two swapped nodes
        inorderTraversal(root, first, second, prev);

        // Swap the values of the two nodes
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }

private:
    void inorderTraversal(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!root) return;

        // In-order traversal: Left -> Node -> Right
        inorderTraversal(root->left, first, second, prev);

        // If previous node exists and its value is greater than the current node's value
        if (prev && prev->val > root->val) {
            // If it's the first occurrence, assign it to 'first'
            if (!first) {
                first = prev;
            }
            // Assign the second occurrence to 'second'
            second = root;
        }

        // Move the previous pointer to the current node
        prev = root;

        inorderTraversal(root->right, first, second, prev);
    }
};

// Leetcode question number 889 :
#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        return buildTree(preorder, postorder, 0, 0, preorder.size());
    }

private:
    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& postorder, 
                        int preStart, int postStart, int size) {
        if (size == 0) return nullptr;

        // Create the root node
        TreeNode* root = new TreeNode(preorder[preStart]);

        // If the tree has only one node
        if (size == 1) return root;

        // Find the root of the left subtree in the postorder array
        int leftSubtreeRoot = preorder[preStart + 1];
        int leftSubtreeSize = 0;
        
        // Calculate the size of the left subtree
        for (int i = 0; i < size; ++i) {
            if (postorder[postStart + i] == leftSubtreeRoot) {
                leftSubtreeSize = i + 1;
                break;
            }
        }

        // Recursively build the left and right sub

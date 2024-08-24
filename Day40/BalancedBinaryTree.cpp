// Leetcode question number 110 :
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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHeight = height(root->left);
        if (leftHeight == -1) return -1;  // Left subtree is not balanced
        
        int rightHeight = height(root->right);
        if (rightHeight == -1) return -1;  // Right subtree is not balanced
        
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;  // Current tree is not balanced
        }
        
        return 1 + std::max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

// Example usage
int main() {
    Solution solution;
    
    // Creating a sample tree: 1 -> / \ -> 2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    bool result = solution.isBalanced(root);
    std::cout << (result ? "The tree is balanced" : "The tree is not balanced") << std::endl;

    return 0;
}

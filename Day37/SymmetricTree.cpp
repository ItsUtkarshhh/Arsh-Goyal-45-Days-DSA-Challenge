// Leetcode question number 101 :
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to check if two trees are mirrors of each other
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true; // Both nodes are null, they are symmetric
        if (t1 == nullptr || t2 == nullptr) return false; // One is null, the other is not, they are not symmetric
        // Check if the current nodes are the same and their subtrees are mirrors of each other
        return (t1->val == t2->val) 
            && isMirror(t1->right, t2->left) 
            && isMirror(t1->left, t2->right);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    Solution sol;
    bool result = sol.isSymmetric(root);
    std::cout << "The tree is symmetric: " << (result ? "true" : "false") << std::endl;

    return 0;
}

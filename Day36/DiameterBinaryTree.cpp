// Leetcode question number 543 :
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    
private:
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        
        // Update the diameter if the current path is longer than the previously recorded one
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    cout << "Diameter of the binary tree: " << solution.diameterOfBinaryTree(root) << endl;

    return 0;
}

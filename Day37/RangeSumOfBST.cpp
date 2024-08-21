// Leetcode question number 938 :
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;  // Base case: if the node is null, return 0
        }
        
        int sum = 0;
        
        // Check if the current node's value is within the range
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        
        // If the current node's value is greater than low, then its left child might have values in the range
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }
        
        // If the current node's value is less than high, then its right child might have values in the range
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        
        return sum;  // Return the sum of values in the range
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    
    Solution sol;
    int low = 7, high = 15;
    int result = sol.rangeSumBST(root, low, high);
    std::cout << "Sum of values in range [" << low << ", " << high << "] is: " << result << std::endl;

    return 0;
}

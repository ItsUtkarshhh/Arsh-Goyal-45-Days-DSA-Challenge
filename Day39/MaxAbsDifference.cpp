// Leetcode question number 530 :
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiff = INT_MAX;    // Initialize the minimum difference to the maximum possible value
    int prevVal = -1;         // Initialize the previous value to an invalid number
    
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        
        // Traverse the left subtree
        inorderTraversal(root->left);
        
        // Process the current node
        if (prevVal != -1) {  // If prevVal is set, calculate the difference
            minDiff = min(minDiff, root->val - prevVal);
        }
        prevVal = root->val;  // Update prevVal to the current node's value
        
        // Traverse the right subtree
        inorderTraversal(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);  // Start the inorder traversal
        return minDiff;          // Return the minimum difference found
    }
};

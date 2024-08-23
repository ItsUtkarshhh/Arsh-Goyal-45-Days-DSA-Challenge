// Leetcode question paper 112 :
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // If the current node is null, return false.
        if (root == nullptr) {
            return false;
        }
        
        // If we reach a leaf node, check if the current node's value equals the remaining sum.
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }
        
        // Recur for the left and right subtrees with the updated target sum.
        int newTargetSum = targetSum - root->val;
        return hasPathSum(root->left, newTargetSum) || hasPathSum(root->right, newTargetSum);
    }
};

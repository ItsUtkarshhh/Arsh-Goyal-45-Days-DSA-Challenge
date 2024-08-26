// Leetcode question number 437 :
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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        // Sum paths that start from the root
        int pathFromRoot = pathSumFrom(root, targetSum);
        
        // Recursively check the left and right subtrees
        int pathFromLeftSubtree = pathSum(root->left, targetSum);
        int pathFromRightSubtree = pathSum(root->right, targetSum);
        
        // Return the total paths found
        return pathFromRoot + pathFromLeftSubtree + pathFromRightSubtree;
    }
    
private:
    int pathSumFrom(TreeNode* node, int sum) {
        if (!node) return 0;
        
        // Check if the current node completes the required path sum
        int count = (node->val == sum) ? 1 : 0;
        
        // Continue to check the left and right children
        count += pathSumFrom(node->left, sum - node->val);
        count += pathSumFrom(node->right, sum - node->val);
        
        return count;
    }
};

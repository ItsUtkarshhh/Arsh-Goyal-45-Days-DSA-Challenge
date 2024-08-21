// Leetcode question number 108:
#include <iostream>
#include <vector>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;  // Base case: if the range is invalid, return nullptr
        }
        
        int mid = left + (right - left) / 2;  // Calculate the middle element
        TreeNode* node = new TreeNode(nums[mid]);  // Create a new node with the middle element
        
        // Recursively construct the left and right subtrees
        node->left = helper(nums, left, mid - 1);
        node->right = helper(nums, mid + 1, right);
        
        return node;  // Return the node as the root of this subtree
    }
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    std::cout << "Preorder traversal of the constructed BST: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}

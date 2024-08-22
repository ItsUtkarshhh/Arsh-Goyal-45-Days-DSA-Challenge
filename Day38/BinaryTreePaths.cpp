// Leetcode question number 257 :
#include <iostream>
#include <vector>
#include <string>

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
    void dfs(TreeNode* node, std::string path, std::vector<std::string>& paths) {
        if (!node) return; // If the node is null, return
        
        // Add current node's value to the path
        path += std::to_string(node->val);
        
        // If it's a leaf node, add the path to the result
        if (!node->left && !node->right) {
            paths.push_back(path);
        } else {
            // If it's not a leaf, continue exploring left and right children
            path += "->"; // Add the arrow for the next step
            if (node->left) dfs(node->left, path, paths);
            if (node->right) dfs(node->right, path, paths);
        }
    }
    
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> paths;
        if (root) dfs(root, "", paths); // Start DFS from the root
        return paths;
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    std::vector<std::string> result = solution.binaryTreePaths(root);
    
    std::cout << "Root-to-leaf paths:" << std::endl;
    for (const std::string& path : result) {
        std::cout << path << std::endl;
    }

    // Clean up the allocated memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

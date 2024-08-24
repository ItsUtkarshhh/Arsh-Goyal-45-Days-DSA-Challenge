// Leetcode question number 94 :
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* current = root;

        while (current != nullptr || !stack.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            // Current must be NULL at this point, so we pop from stack
            current = stack.top();
            stack.pop();
            result.push_back(current->val);  // Visit the node

            // We have visited the node and its left subtree, now visit the right subtree
            current = current->right;
        }

        return result;
    }
};

// Example usage
int main() {
    Solution solution;

    // Creating a sample tree: 1 -> / \ -> 2   3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

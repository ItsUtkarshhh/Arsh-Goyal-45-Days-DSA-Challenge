// Leetcode question number 230 :
#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* current = root;

        while (true) {
            // Traverse the left subtree
            while (current != NULL) {
                stk.push(current);
                current = current->left;
            }

            // Process the node
            current = stk.top();
            stk.pop();
            k--;

            // If k reaches 0, we've found the kth smallest element
            if (k == 0) return current->val;

            // Traverse the right subtree
            current = current->right;
        }
    }
};

int main() {
    Solution sol;

    // Constructing the BST
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;
    cout << "The " << k << "th smallest element in the BST is: " << sol.kthSmallest(root, k) << endl;

    // Clean up memory (important in larger applications)
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

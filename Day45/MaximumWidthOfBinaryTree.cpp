// Leetcode questiion number 662 :
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q; // Pair of node and index
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long start = q.front().second;
            unsigned long long end = q.back().second;

            maxWidth = max(maxWidth, static_cast<int>(end - start + 1));

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }
        }

        return maxWidth;
    }
};

int main() {
    Solution sol;
    
    // Construct the binary tree [1,3,2,5,3,null,9]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    cout << "Maximum Width of Binary Tree: " << sol.widthOfBinaryTree(root) << endl;

    // Clean up memory (important in larger applications)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

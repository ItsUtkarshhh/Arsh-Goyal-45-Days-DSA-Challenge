// Leetcode question number 662 :
#include <iostream>
#include <queue>
#include <utility> // for std::pair

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
        std::queue<std::pair<TreeNode*, unsigned long long>> q; // Pair of node and its index
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second; // Get the index of the first node
            unsigned long long right = q.back().second; // Get the index of the last node
            maxWidth = std::max(maxWidth, int(right - left + 1));

            for (int i = 0; i < size; ++i) {
                auto [node, index] = q.front();
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * index});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }
        }

        return maxWidth;
    }
};

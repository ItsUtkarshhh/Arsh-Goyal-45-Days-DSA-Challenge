// Leetcode question number 95 :
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTreesHelper(1, n);
    }

private:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> trees;

        // Base case: when start > end, there should be no tree, so return a vector containing nullptr
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Try every number as a root
        for (int i = start; i <= end; i++) {
            // Generate all possible left and right subtrees
            vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
            vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

            // Combine each left and right tree with the root i
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};

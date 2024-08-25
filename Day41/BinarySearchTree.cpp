// Leetcode question number 173 :
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> nodeStack;

    // Helper function to push all left children to the stack
    void pushLeftNodes(TreeNode* node) {
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        // Initialize the stack with all left children of the root
        pushLeftNodes(root);
    }

    /** @return the next smallest number */
    int next() {
        // The next smallest node is at the top of the stack
        TreeNode* nextNode = nodeStack.top();
        nodeStack.pop();

        // If the node has a right child, push all of its left children to the stack
        if (nextNode->right != nullptr) {
            pushLeftNodes(nextNode->right);
        }

        return nextNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }
};

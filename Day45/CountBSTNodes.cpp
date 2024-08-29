// GFG Question :
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodesInRange(Node* root, int low, int high) {
        // Base case
        if (root == NULL) return 0;

        // If current node's data is in range, then count this node
        // and recursively count nodes in left and right subtrees
        if (root->data >= low && root->data <= high) {
            return 1 + countNodesInRange(root->left, low, high) + countNodesInRange(root->right, low, high);
        }
        // If current node's data is less than the lower range, then only consider the right subtree
        else if (root->data < low) {
            return countNodesInRange(root->right, low, high);
        }
        // If current node's data is greater than the higher range, then only consider the left subtree
        else {
            return countNodesInRange(root->left, low, high);
        }
    }
};

int main() {
    Solution sol;

    // Constructing the binary search tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int low = 5, high = 45;
    cout << "Count of nodes within range [" << low << ", " << high << "] is: " 
         << sol.countNodesInRange(root, low, high) << endl;

    // Clean up memory (important in larger applications)
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

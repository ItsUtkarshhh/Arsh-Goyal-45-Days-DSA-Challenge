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
    bool isDeadEnd(Node* root, int min = 1, int max = INT_MAX) {
        // Base case
        if (root == nullptr) return false;

        // If the current node represents a dead end
        if (min == max) return true;

        // Recur for left and right subtrees
        return isDeadEnd(root->left, min, root->data - 1) || 
               isDeadEnd(root->right, root->data + 1, max);
    }

    bool containsDeadEnd(Node* root) {
        return isDeadEnd(root);
    }
};

// Helper function to insert a new node with given data
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->data) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);

    return node;
}

// Example usage
int main() {
    Solution solution;

    /* Constructed BST:
             8
           /   \
          5     11
         /  \
        2    7
         \
          3
           \
            4
    */
    Node* root = new Node(8);
    insert(root, 5);
    insert(root, 2);
    insert(root, 3);
    insert(root, 7);
    insert(root, 4);
    insert(root, 11);

    if (solution.containsDeadEnd(root))
        cout << "BST contains a dead end" << endl;
    else
        cout << "BST does not contain a dead end" << endl;

    return 0;
}

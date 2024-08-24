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

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    if (root == nullptr) return;

    // If key is found at the root
    if (root->data == key) {
        // The predecessor is the rightmost child of the left subtree
        if (root->left != nullptr) {
            Node* temp = root->left;
            while (temp->right) temp = temp->right;
            pre = temp;
        }

        // The successor is the leftmost child of the right subtree
        if (root->right != nullptr) {
            Node* temp = root->right;
            while (temp->left) temp = temp->left;
            suc = temp;
        }
        return;
    }

    // If the key is smaller than the root's key, go to the left subtree
    if (key < root->data) {
        suc = root;  // current node could be successor
        findPreSuc(root->left, pre, suc, key);
    } else {  // If the key is larger than the root's key, go to the right subtree
        pre = root;  // current node could be predecessor
        findPreSuc(root->right, pre, suc, key);
    }
}

// Helper function to create a new BST node
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->data) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);

    return node;
}

// Example usage
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 65;
    Node* pre = NULL;
    Node* suc = NULL;

    findPreSuc(root, pre, suc, key);

    if (pre != NULL)
        cout << "Predecessor is " << pre->data << endl;
    else
        cout << "No Predecessor" << endl;

    if (suc != NULL)
        cout << "Successor is " << suc->data << endl;
    else
        cout << "No Successor" << endl;

    return 0;
}

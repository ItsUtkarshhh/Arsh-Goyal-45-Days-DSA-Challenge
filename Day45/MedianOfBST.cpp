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
    // Function to count the number of nodes in the BST
    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to find the kth node in an in-order traversal
    void findKthNode(Node* root, int& k, int& result) {
        if (root == NULL) return;
        
        findKthNode(root->left, k, result);
        
        k--;
        if (k == 0) {
            result = root->data;
            return;
        }
        
        findKthNode(root->right, k, result);
    }

    // Function to find the median of the BST
    float findMedian(Node* root) {
        if (root == NULL) return 0.0;

        int n = countNodes(root);
        int k1 = (n + 1) / 2;
        int k2 = n % 2 == 0 ? k1 + 1 : k1;

        int val1 = -1, val2 = -1;
        
        findKthNode(root, k1, val1);
        findKthNode(root, k2, val2);

        return (val1 + val2) / 2.0;
    }
};

int main() {
    Solution sol;

    // Constructing the binary search tree
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout << "Median of the BST is: " << sol.findMedian(root) << endl;

    // Clean up memory (important in larger applications)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}

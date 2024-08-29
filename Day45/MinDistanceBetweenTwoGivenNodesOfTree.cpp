// GFG Question :
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

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
    // Function to find the lowest common ancestor (LCA) of two nodes
    Node* findLCA(Node* root, int n1, int n2) {
        if (root == NULL) return NULL;
        if (root->data == n1 || root->data == n2) return root;

        Node* leftLCA = findLCA(root->left, n1, n2);
        Node* rightLCA = findLCA(root->right, n1, n2);

        if (leftLCA && rightLCA) return root;

        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }

    // Function to find the distance from the root node to the target node
    int findDistanceFromRoot(Node* root, int target) {
        if (root == NULL) return -1;
        if (root->data == target) return 0;

        int leftDistance = findDistanceFromRoot(root->left, target);
        int rightDistance = findDistanceFromRoot(root->right, target);

        if (leftDistance >= 0) return leftDistance + 1;
        if (rightDistance >= 0) return rightDistance + 1;

        return -1;
    }

    // Function to find the minimum distance between two given nodes
    int findDist(Node* root, int a, int b) {
        Node* lca = findLCA(root, a, b);

        int d1 = findDistanceFromRoot(lca, a);
        int d2 = findDistanceFromRoot(lca, b);

        return d1 + d2;
    }
};

int main() {
    Solution sol;
    
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int a = 4, b = 5;
    cout << "Minimum distance between " << a << " and " << b << " is: " << sol.findDist(root, a, b) << endl;

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

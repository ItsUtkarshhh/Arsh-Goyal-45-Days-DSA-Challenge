// Leetcode question number 116 :
#include <iostream>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Start with the root node
        Node* leftmost = root;

        // Continue until we reach the last level
        while (leftmost->left) {
            Node* head = leftmost;
            
            // Iterate over the nodes in the current level
            while (head) {
                // Connect the left child to the right child
                head->left->next = head->right;

                // Connect the right child to the next left child, if there is a next node
                if (head->next) {
                    head->right->next = head->next->left;
                }

                // Move to the next node in the current level
                head = head->next;
            }

            // Move to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};

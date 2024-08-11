// Leetcode question number 86 :
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child) {
                // Step 1: Store the next node
                Node* next = curr->next;

                // Step 2: Flatten the child list
                Node* child = flatten(curr->child);

                // Step 3: Attach the child list to curr
                curr->next = child;
                child->prev = curr;

                // Step 4: Find the tail of the child list
                while (child->next != NULL) {
                    child = child->next;
                }

                // Step 5: Connect the tail of the child list to the next node
                child->next = next;
                if (next != NULL) {
                    next->prev = child;
                }

                // Step 6: Don't forget to remove the child pointer
                curr->child = NULL;
            }
            // Move to the next node
            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating the nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Adding a child to the second node
    head->next->child = new Node(7);
    head->next->child->next = new Node(8);
    head->next->child->next->prev = head->next->child;

    // Flatten the list
    Solution solution;
    head = solution.flatten(head);

    // Print the flattened list
    printList(head);

    return 0;
}

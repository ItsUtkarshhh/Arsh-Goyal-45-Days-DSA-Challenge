// leetcode question number 82 :
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;

        // Dummy node to handle the edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != NULL) {
            // Move current until the end of the duplicates
            while (current->next != NULL && current->val == current->next->val) {
                current = current->next;
            }

            // If prev->next is current, then there's no duplicate
            if (prev->next == current) {
                prev = prev->next;
            } else {
                // If duplicates were found, skip all duplicates
                prev->next = current->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating the nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    // Print the resulting list
    printList(result);

    return 0;
}

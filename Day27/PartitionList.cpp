// Leetcode question number 86 :
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        // Dummy nodes to initiate the two lists
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        // Pointers to the current end of the less and greater lists
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        // Traverse the list and partition the nodes
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Connect the two lists and terminate the last node of the greater list
        greater->next = nullptr;
        less->next = greaterHead->next;

        // The new head is the start of the less list
        ListNode* newHead = lessHead->next;

        // Clean up the dummy nodes
        delete lessHead;
        delete greaterHead;

        return newHead;
    }
};

// Helper function to print the list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Creating the linked list 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->


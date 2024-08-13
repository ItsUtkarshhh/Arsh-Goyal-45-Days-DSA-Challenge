// Leetcode question number 25 :
#include <iostream>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node initialization
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Initialize pointers
        ListNode* prevGroupEnd = dummy;
        ListNode* end = head;

        int i = 0;

        while (end != nullptr) {
            i++;

            // If we have k nodes in the current group
            if (i % k == 0) {
                prevGroupEnd = reverseOneGroup(prevGroupEnd, end->next);
                end = prevGroupEnd->next;
            } else {
                end = end->next;
            }
        }

        return dummy->next;
    }

private:
    // Function to reverse the nodes between start and end (exclusive) and return the last node of the reversed group
    ListNode* reverseOneGroup(ListNode* start, ListNode* end) {
        ListNode* prev = start;
        ListNode* curr = start->next;
        ListNode* next;
        ListNode* first = curr;  // This will be the end of the reversed group

        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        start->next = prev;
        first->next = curr;

        return first;
    }
};

// Leetcode question number 92 :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if (!head || left == right) return head;

    ListNode dummy(0);  // Dummy node to handle edge cases
    dummy.next = head;
    ListNode* prev = &dummy;

    // Step 1: Move `prev` to the node before `left`
    for (int i = 1; i < left; ++i) {
        prev = prev->next;
    }

    // `start` will point to the `left` node and `then` to the next node
    ListNode* start = prev->next;
    ListNode* then = start->next;

    // Step 2: Reverse the sublist from `left` to `right`
    for (int i = 0; i < right - left; ++i) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    // Step 3: Return the head of the modified list
    return dummy.next; 
    }
};

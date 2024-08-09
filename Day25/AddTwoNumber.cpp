// Leetcode question number 2 :
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify handling the head
    ListNode* current = dummyHead;
    int carry = 0;

    // Traverse both linked lists
    while (l1 != nullptr || l2 != nullptr) {
        int x = (l1 != nullptr) ? l1->val : 0; // Get the value from l1, or 0 if l1 is null
        int y = (l2 != nullptr) ? l2->val : 0; // Get the value from l2, or 0 if l2 is null
        int sum = carry + x + y;               // Sum the values and the carry
        carry = sum / 10;                      // Update the carry
        current->next = new ListNode(sum % 10); // Create a new node with the digit
        current = current->next;               // Move to the next node

        // Move to the next nodes in l1 and l2
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    // If there's any carry left, add a new node with carry value
    if (carry > 0) {
        current->next = new ListNode(carry);
    }

    return dummyHead->next;
    }
};

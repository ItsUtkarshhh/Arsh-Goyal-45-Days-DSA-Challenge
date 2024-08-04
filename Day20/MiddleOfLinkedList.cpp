// Leetcode question number 876 :
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
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, slow and fast
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Iterate through the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // Move slow pointer by one step
            fast = fast->next->next;     // Move fast pointer by two steps
        }
        
        // When fast reaches the end, slow will be at the middle
        return slow;
    }
};

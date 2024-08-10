// Leetcode question number 19 :
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node that points to the head of the list
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    // Move the first pointer `n+1` steps ahead
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }
    
    // Move both pointers until the first pointer reaches the end
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    // Remove the nth node from the end
    ListNode* nodeToRemove = second->next;
    second->next = second->next->next;
    delete nodeToRemove;
    
    // Get the new head of the list
    ListNode* newHead = dummy->next;
    delete dummy;  // Free the dummy node
    return newHead;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
};

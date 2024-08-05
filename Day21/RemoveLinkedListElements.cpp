// Leetcode question number 203 :
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    // Create a dummy node which will be the new head
    ListNode dummy(0);
    dummy.next = head;
    
    ListNode* prev = &dummy; // Initialize prev to the dummy node
    ListNode* current = head;
    
    while (current != nullptr) {
        if (current->val == val) {
            // Skip the current node
            prev->next = current->next;
            delete current; // Free the memory of the removed node
        } else {
            // Move prev to current
            prev = current;
        }
        current = prev->next; // Move to the next node
    }
    
    return dummy.next; // Return the new head, which is dummy.next
}

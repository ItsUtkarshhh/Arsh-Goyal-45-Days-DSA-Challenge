// Leetcode question number 1920 :
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getDecimalValue(ListNode *head) {
    int result = 0;
    ListNode *current = head;
    
    while (current != nullptr) {
        // Left shift result by 1 (equivalent to multiplying by 2) and add the current node's value
        result = (result << 1) | current->val;
        current = current->next;
    }
    
    return result;
}

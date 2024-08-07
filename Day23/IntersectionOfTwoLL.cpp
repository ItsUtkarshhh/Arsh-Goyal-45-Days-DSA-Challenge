// Leetcode question number 160 :
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to get the intersection node of two linked lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;
    
    ListNode *a = headA;
    ListNode *b = headB;
    
    // Traverse both lists
    while (a != b) {
        // Move to the next node in list A, or to the head of list B if end is reached
        a = a ? a->next : headB;
        // Move to the next node in list B, or to the head of list A if end is reached
        b = b ? b->next : headA;
    }
    
    // Either the intersection node or NULL if no intersection
    return a;
}

// Helper function to create a new node
ListNode* newNode(int data) {
    ListNode* node = new ListNode(data);
    return node;
}

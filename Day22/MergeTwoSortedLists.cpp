// Leetcode question number 21 :
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify the merge logic
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining elements
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // The merged list is in dummy.next
        return dummy.next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage
    std::vector<int> arr1 = {1, 2, 4};
    std::vector<int> arr2 = {1, 3, 4};
    ListNode* list1 = createList(arr1);
    ListNode* list2 = createList(arr2);

    Solution solution;
    ListNode* mergedHead = solution.mergeTwoLists(list1, list2);
    
    printList(mergedHead); // Output should be: 1 1 2 3 4 4
    
    return 0;
}

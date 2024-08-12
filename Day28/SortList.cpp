// Leetcode question number 148 :
class Solution {
public:
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // Split the list into two halves
        ListNode* middle = getMiddle(head);
        ListNode* secondHalf = middle->next;
        middle->next = NULL;

        // Recursively sort both halves
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(secondHalf);

        // Merge the sorted halves
        return merge(left, right);
    }

    ListNode* getMiddle(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->val < right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

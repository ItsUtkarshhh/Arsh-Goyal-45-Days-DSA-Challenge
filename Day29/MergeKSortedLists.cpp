// Leetcode question number 23 :
#include <vector>
#include <queue>

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Define a comparator for the priority queue
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap based on node value
        };
        
        // Initialize the priority queue (min-heap)
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        // Push the head of each linked list into the priority queue
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        // Dummy node to start the merged list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;
        
        // Process the min-heap until it's empty
        while (!minHeap.empty()) {
            // Extract the node with the smallest value
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            // Add the smallest node to the merged list
            current->next = minNode;
            current = current->next;
            
            // If the extracted node has a next node, push it into the heap
            if (minNode->next != nullptr) {
                minHeap.push(minNode->next);
            }
        }
        
        // Return the head of the merged list (dummy->next)
        return dummy->next;
    }
};

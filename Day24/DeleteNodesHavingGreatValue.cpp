// GFG Question :
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to remove nodes with greater values on the right
Node* removeNodesWithGreaterValues(Node* head) {
    // Reverse the linked list
    head = reverse(head);

    Node* maxNode = nullptr;
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        // If this is the first node or it is greater than the current maxNode
        if (maxNode == nullptr || curr->data >= maxNode->data) {
            maxNode = curr;
            if (prev != nullptr) {
                prev->next = curr;
            }
            prev = curr;
        }
        curr = curr->next;
    }
    // Make sure the last node's next is nullptr
    if (prev != nullptr) {
        prev->next = nullptr;
    }

    // Reverse the linked list again to restore the original order
    return reverse(head);
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create linked list: 12 -> 15 -> 10 -> 11 -> 5 -> 6 -> 2
    Node* head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);

    std::cout << "Original List: ";
    printList(head);

    head = removeNodesWithGreaterValues(head);

    std::cout << "Modified List: ";
    printList(head);

    // Cleanup memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

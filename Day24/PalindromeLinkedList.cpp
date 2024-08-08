// Leetcode question number 234 :
#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Function to find the middle of the linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reverse a linked list
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

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a single element list is a palindrome
    }

    // Find the middle of the linked list
    Node* middle = findMiddle(head);
    
    // Reverse the second half of the list
    Node* secondHalf = reverse(middle);
    Node* firstHalf = head;

    // Compare the first half and the reversed second half
    Node* secondHalfCopy = secondHalf; // For restoring the list later if needed
    while (secondHalf != nullptr) {
        if (firstHalf->data != secondHalf->data) {
            // Restore the list (if needed)
            reverse(secondHalfCopy);
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Restore the list (if needed)
    reverse(secondHalfCopy);
    return true;
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
    // Create linked list: 1 -> 2 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    std::cout << "Is Palindrome: " << (isPalindrome(head) ? "true" : "false") << std::endl;

    // Cleanup memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

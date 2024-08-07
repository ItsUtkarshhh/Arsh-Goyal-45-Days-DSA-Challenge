// GFG Question :
#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to multiply two linked lists
long long multiplyTwoLists(Node* l1, Node* l2) {
    long long num1 = 0, num2 = 0;
    long long MOD = 1000000007;
    
    // Traverse the first linked list
    while (l1 != NULL) {
        num1 = (num1 * 10 + l1->data) % MOD;
        l1 = l1->next;
    }
    
    // Traverse the second linked list
    while (l2 != NULL) {
        num2 = (num2 * 10 + l2->data) % MOD;
        l2 = l2->next;
    }
    
    // Multiply the two numbers and take modulo
    return (num1 * num2) % MOD;
}

// Function to create a new node and return its pointer
Node* newNode(int data) {
    Node* node = new Node(data);
    return node;
}

int main() {
    // Creating two linked lists: L1 = 123 and L2 = 456
    Node* l1 = newNode(1);
    l1->next = newNode(2);
    l1->next->next = newNode(3);
    
    Node* l2 = newNode(4);
    l2->next = newNode(5);
    l2->next->next = newNode(6);
    
    // Multiply the linked lists and print the result
    cout << "Result: " << multiplyTwoLists(l1, l2) << endl;
    
    return 0;

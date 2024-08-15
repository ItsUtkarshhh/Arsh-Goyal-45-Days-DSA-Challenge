// GFG Question :
class Node {
public:
    int data;
    Node *next;
    Node *bottom;
};

class Solution {
public:
    Node *mergeTwoLists(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        
        Node *result;
        
        if (a->data < b->data) {
            result = a;
            result->bottom = mergeTwoLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeTwoLists(a, b->bottom);
        }
        
        return result;
    }

    Node *flatten(Node *root) {
        if (!root || !root->next)
            return root;

        // Recursively flatten the right list
        root->next = flatten(root->next);
        
        // Merge current list with the flattened right list
        root = mergeTwoLists(root, root->next);

        return root;
    }
};

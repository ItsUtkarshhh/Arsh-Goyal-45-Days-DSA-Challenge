// Leetcode question number 138 :
if (head == nullptr) {
        return nullptr;
    }

    // Step 1: Create new nodes and interweave them with the original list.
    Node* iter = head;
    while (iter != nullptr) {
        Node* next = iter->next;
        Node* copy = new Node(iter->val);
        iter->next = copy;
        copy->next = next;
        iter = next;
    }

    // Step 2: Assign random pointers for the copied nodes.
    iter = head;
    while (iter != nullptr) {
        if (iter->random != nullptr) {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }

    // Step 3: Separate the original and copied lists.
    iter = head;
    Node* copyHead = head->next;
    Node* copyIter = copyHead;

    while (iter != nullptr) {
        iter->next = iter->next->next;
        if (copyIter->next != nullptr) {
            copyIter->next = copyIter->next->next;
        }
        iter = iter->next;
        copyIter = copyIter->next;
    }

    return copyHead;

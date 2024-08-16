// GFG Question :
#include <iostream>
using namespace std;

class TwoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    // Constructor
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;             // Top of the first stack starts from the beginning
        top2 = size;           // Top of the second stack starts from the end
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Function to remove an element from the top of the stack1.
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        } else {
            cout << "Stack Underflow" << endl;
            return -1; // Return -1 if there's underflow
        }
    }

    // Function to remove an element from the top of the stack2.
    int pop2() {
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        } else {
            cout << "Stack Underflow" << endl;
            return -1; // Return -1 if there's underflow
        }
    }
};

int main() {
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    
    cout << "Popped element from stack1 is " << ts.pop1() << endl;
    ts.push2(40);
    cout << "Popped element from stack2 is " << ts.pop2() << endl;
    return 0;
}

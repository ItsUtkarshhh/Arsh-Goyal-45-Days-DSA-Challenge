// Leetcode question number 341 :
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This is the interface that allows for creating nested lists.
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer.
    // The result is undefined if this NestedInteger holds a nested list.
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list.
    // The result is undefined if this NestedInteger holds a single integer.
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> stk;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Push all elements from the list onto the stack in reverse order
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            stk.push(*it);
        }
    }
    
    int next() {
        int result = stk.top().getInteger();
        stk.pop();
        return result;
    }
    
    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger curr = stk.top();
            if (curr.isInteger()) {
                return true;
            }
            stk.pop();
            vector<NestedInteger> lst = curr.getList();
            for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
                stk.push(*it);
            }
        }
        return false;
    }
};

int main() {
    // Example usage:
    // Suppose we have a list of NestedInteger objects (pseudo code):
    // [1,[4,[6]]]
    // NestedInteger a(1), b(4), c(6);
    // NestedInteger d(vector<NestedInteger>{c}), e(vector<NestedInteger>{b, d});
    // vector<NestedInteger> nestedList = {a, e};
    
    // NestedIterator i(nestedList);
    // while (i.hasNext()) cout << i.next() << " ";  // Output: 1 4 6

    return 0;
}

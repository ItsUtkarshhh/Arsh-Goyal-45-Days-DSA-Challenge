// Leetcode question number 1209 :
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeDuplicates(string s, int k) {
    // A stack to keep track of characters and their consecutive counts.
    stack<pair<char, int>> stk;
    
    // Traverse each character in the string
    for (char c : s) {
        // If the stack is not empty and the top element has the same character
        if (!stk.empty() && stk.top().first == c) {
            stk.top().second++;
            // If the count of the top element reaches k, pop it off the stack
            if (stk.top().second == k) {
                stk.pop();
            }
        } else {
            // Push the character with count 1 to the stack
            stk.push({c, 1});
        }
    }
    
    // Construct the final string
    string result;
    while (!stk.empty()) {
        result.append(stk.top().second, stk.top().first);
        stk.pop();
    }
    
    // The stack builds the result in reverse, so reverse it back
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << removeDuplicates(s, k) << endl;  // Output: "aa"
    return 0;
}

// GFG Question :
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string exp) {
        stack<int> st;

        // Traverse the expression
        for (int i = 0; i < exp.length(); i++) {
            char c = exp[i];

            // If the character is a digit, push it to the stack.
            if (isdigit(c)) {
                st.push(c - '0'); // Convert char digit to int
            }
            // If the character is an operator, pop two elements from stack, apply the operator, and push the result back.
            else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                switch (c) {
                    case '+': st.push(val2 + val1); break;
                    case '-': st.push(val2 - val1); break;
                    case '*': st.push(val2 * val1); break;
                    case '/': st.push(val2 / val1); break;
                }
            }
        }
        // The final result will be in the stack.
        return st.top();
    }
};

// Example usage
int main() {
    Solution sol;
    string expr = "231*+9-";
    cout << "Postfix evaluation: " << sol.evaluatePostfix(expr) << endl; // Output: -4
    return 0;
}

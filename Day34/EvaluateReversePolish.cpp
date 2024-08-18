// Leetcode question number 150 :
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (token == "+") {
                    st.push(a + b);
                } else if (token == "-") {
                    st.push(a - b);
                } else if (token == "*") {
                    st.push(a * b);
                } else if (token == "/") {
                    st.push(a / b);
                }
            } else {
                st.push(stoi(token));  // Convert token to integer and push it onto the stack
            }
        }
        
        return st.top();  // The result of the expression
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Result: " << solution.evalRPN(tokens) << endl;  // Output should be 9

    return 0;
}

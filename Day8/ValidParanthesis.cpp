// Leetcode question number 20 :
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {
            // If the character is one of the closing brackets
            if (matchingBrackets.count(ch)) {
                // Check if the stack is empty or the top of the stack is not the matching opening bracket
                if (st.empty() || st.top() != matchingBrackets[ch]) {
                    return false;
                }
                st.pop();
            } else {
                // If it is an opening bracket, push it onto the stack
                st.push(ch);
            }
        }

        // The stack should be empty if all the brackets are matched correctly
        return st.empty();
    }
};

// Leetcode question number 227 :
class Solution {
public:
    int calculate(string s) {
        stack<int> nums; // Stack to store numbers
        stack<char> ops; // Stack to store operators
        int n = s.size();
        int currentNumber = 0;
        char currentOp = '+';
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }
            
            if (!isdigit(c) && !isspace(c) || i == n - 1) {
                if (currentOp == '+') {
                    nums.push(currentNumber);
                } else if (currentOp == '-') {
                    nums.push(-currentNumber);
                } else if (currentOp == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * currentNumber);
                } else if (currentOp == '/') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / currentNumber);
                }
                
                currentOp = c;
                currentNumber = 0;
            }
        }
        
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        
        return result;
    }
};

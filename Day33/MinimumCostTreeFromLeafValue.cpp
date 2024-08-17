// Leetcode question number 1130 :
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

int mctFromLeafValues(vector<int>& arr) {
    int result = 0;
    stack<int> s;
    s.push(INT_MAX);

    for (int num : arr) {
        while (s.top() <= num) {
            int mid = s.top();
            s.pop();
            result += mid * min(s.top(), num);
        }
        s.push(num);
    }

    while (s.size() > 2) {
        int mid = s.top();
        s.pop();
        result += mid * s.top();
    }

    return result;
}

int main() {
    vector<int> arr = {6, 2, 4};
    cout << "Minimum Cost Tree from Leaf Values: " << mctFromLeafValues(arr) << endl;
    return 0;
}

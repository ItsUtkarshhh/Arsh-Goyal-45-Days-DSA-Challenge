// Leetcode question number 907 :
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> ple(n), nle(n);
        stack<int> s;
        
        // Previous Less Element (PLE)
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        // Clear the stack to reuse it for NLE
        while (!s.empty()) s.pop();
        
        // Next Less Element (NLE)
        for (int i = n-1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            nle[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        // Calculate the result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            long long count = (long long)(i - ple[i]) * (nle[i] - i) % MOD;
            result = (result + count * arr[i] % MOD) % MOD;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << sol.sumSubarrayMins(arr) << endl; // Output: 17
    return 0;
}

// Leetcode question number 496 :
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Pop elements that are not greater than nums2[i]
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            // If stack is not empty, the top is the next greater element
            if (!st.empty()) {
                nextGreater[nums2[i]] = st.top();
            } else {
                nextGreater[nums2[i]] = -1;
            }
            
            // Push the current element onto the stack
            st.push(nums2[i]);
        }
        
        // Create the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};

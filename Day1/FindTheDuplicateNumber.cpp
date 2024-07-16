// Leetcode question number 287 :
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};

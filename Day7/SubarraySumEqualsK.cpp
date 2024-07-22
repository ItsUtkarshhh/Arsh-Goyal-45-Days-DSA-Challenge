// Leetcode question number 560 :
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_count;
        sum_count[0] = 1;
        
        int current_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            if (sum_count.find(current_sum - k) != sum_count.end()) {
                count += sum_count[current_sum - k];
            }
            
            sum_count[current_sum]++;
        }
        
        return count;
    }
};

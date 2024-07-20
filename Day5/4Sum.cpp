// Leetcode question number 18 :
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n; ++j) {
                // Skip duplicate elements
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        // Skip duplicates for left pointer
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        // Skip duplicates for right pointer
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        
        return result;
    }
};

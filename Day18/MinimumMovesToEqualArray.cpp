// Leetcode question number 462 :
class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        // Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Find the median
        int median = nums[nums.size() / 2];
        
        // Calculate the total number of moves
        int moves = 0;
        for (int num : nums) {
            moves += std::abs(num - median);
        }
        
        return moves;
    }
};

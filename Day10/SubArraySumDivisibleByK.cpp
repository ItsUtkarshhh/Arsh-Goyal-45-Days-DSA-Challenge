// Leetcode question number 974 :
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::unordered_map<int, int> remainderCount;
        remainderCount[0] = 1; // To handle cases where the subarray itself is divisible by k
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int remainder = sum % k;
            if (remainder < 0) remainder += k; // Handle negative remainders

            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            
            remainderCount[remainder]++;
        }
    return count;
    }
};

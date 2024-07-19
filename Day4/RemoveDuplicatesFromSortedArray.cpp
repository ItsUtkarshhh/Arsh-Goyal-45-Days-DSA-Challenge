// Leetcode question number 26 :
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
        return 0;
    }

    int i = 1, k = 1;

    while (i < nums.size()) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
        i++;
    }

    return k;
    }
};

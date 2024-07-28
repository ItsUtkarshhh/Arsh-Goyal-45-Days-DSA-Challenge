// Leetcode question number 11 :
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            int current_height = std::min(height[left], height[right]);
            int current_width = right - left;
            int current_area = current_height * current_width;
            
            max_water = std::max(max_water, current_area);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};

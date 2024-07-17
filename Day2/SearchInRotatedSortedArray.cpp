// Leetcode question number 33 :
class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int key) {
        int start = s;
        int end = e;
        int mid = (start+end)/2;
        while(start<=end) {
            if(key==nums[mid]) {
                return mid;
            }

            if(key>nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = (start+end)/2;
        }
        return -1;
    }
    int pivotElement(vector<int>& nums, int n) {
        int s = 0; int e = n-1;
        int mid = s +(e-s)/2;
        while(s<e) {
            if(nums[mid]>=nums[0]) {
                s = mid+1;
            }
            else {
                e = mid;
            }
            mid = s +(e-s)/2;
        }
        return s;
    }
    int search(vector<int>& nums, int key) {
        int pivot = pivotElement(nums, nums.size());
        int e = nums.size()-1;
        if(key>=nums[pivot] && key<=nums[e]) {
            return binarySearch(nums,pivot,nums.size()-1,key);
        }
        else {
            return binarySearch(nums, 0, pivot-1, key);
        }
    }
};

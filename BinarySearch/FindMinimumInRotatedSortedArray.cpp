class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid = (lo + hi) / 2;
        if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi])
            return nums[lo];
        
        while (lo < hi-1) {
            mid = (lo + hi) / 2;
            // 0 1 2 3 4   0/5 lo < mid < hi
            // 4 0 1 2 3   1   lo > mid && mid < hi
            // 3 4 0 1 2   2   lo > mid && mid < hi
            // 2 3 4 0 1   3   lo < mid && mid > hi 
            // 1 2 3 4 0   4   lo < mid && mid > hi
            if (nums[lo] > nums[mid]) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return min(nums[lo], nums[hi]);;
    }
};

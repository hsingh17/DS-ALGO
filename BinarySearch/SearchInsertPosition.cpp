class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary search (lower bound implementation)
        int lo = 0, hi = nums.size()-1;
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (nums[mid] > target) 
                hi = mid;
            else 
                lo = mid+1;
        }
        
        return (lo == nums.size()-1 && nums[lo] < target) ? lo+1 : lo;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//         // Method 1: DP approach
//         // LIS[k] = length of the LIS up to index k = max(1+LIS[k-1], 1+LIS[k-2], ... , 1+LIS[1])
//         //          IF nums[k] > nums[k-1] etc.
//         // Runtime: O(N^2) where N=len(nums), since for each N nums we need to check the previous 
//         //          values of LIS
//         // Space: O(N) to store N values for LIS
        
//         vector<int> dp(nums.size(), -1);
//         int LIS = 1;
//         for (int i = 0; i < nums.size(); i++) {
//             int best = 1;
//             for (int j = i-1; j >= 0; j--) {
//                 if (nums[i] > nums[j]) best = max(best, 1+dp[j]);
//             }
//             // Set dp[i]
//             dp[i] = best;
            
//             // Update LIS
//             LIS = max(LIS, dp[i]);
//         }
        
//         return LIS;
        
        // Method 2: Patience Sorting
        // Runtime: O(NlogN)
        // Space: O(N)
        
        if (nums.empty()) return 0;
        
        vector<int> piles;
        piles.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            // Do binary search (lower_bound implementation) to find 
            // the LEFTMOST pile where the top card is >= current card
            int lo = 0, mid = 0, res = 0, hi = piles.size();
            while (lo < hi) {
                mid = (lo + hi) / 2;
                
                if (piles[mid] >= nums[i]) {
                    res = mid;
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            
            if (piles[res] < nums[i]) piles.push_back(nums[i]);
            else piles[res] = nums[i];
        }
        
        return piles.size();
    }
};

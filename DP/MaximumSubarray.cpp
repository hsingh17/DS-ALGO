class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Method 1: DP
        //          DP[i] stores the best sum possible to index i. If DP[i-1] <= 0 then DP[i] = nums[i]                           otherwise it’s DP[i-1]+nums[i]
        vector<int> dp(nums.size(), 0);
        int ret = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = (dp[i-1] > 0) ? dp[i-1]+nums[i] : nums[i];
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};

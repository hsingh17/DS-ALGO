class Solution {
public:
    // Method: 
    // Standard DP problem. Can do bottom-up or top-down. Idea is to
    // break each N into N-1, N-2,...,1 then solve each subproblem.
    // Base case is n == 1 --> return 1
    // Recursive case is n >= 1 --> return max(integerBreak(N-1)*1, integerBreak(N-2)*2, ... N-1*1)
    // Runtime: O(n^2) since for each value of n we need to at most n operations
    // Space: O(n) for memo
    vector<int> MEMO;
    // This method is top-down
    int integerBreak(int n, bool top_level) {
        // Base Case
        if (n == 1) return 1;
        
        // Check if current n is in memo
        if (MEMO[n] != -1) return MEMO[n];
        
        // Recursive Case
        int ret = -1;
        for (int i = 1; i < n; i++) {
            int prod = integerBreak(n-i, false);
            ret = max(ret, prod*i);
        }
        
        // Add to memo and return entry
        MEMO[n] = top_level ? ret : max(ret, n);
        return MEMO[n];
    }
    
    int integerBreak(int n) {
        // // Init the memo
        // this->MEMO = vector<int>(58, -1);
        // return integerBreak(n, true);
        
        // Bottom-up approach
        vector<int> dp(n+1, -1);
        
        // Init starting values in dp to be i (EXCEPT FOR N)
        // This is to obey the k >= 2 condition
        for (int i = 1; i < n; i++) dp[i] = i;
        
        // Continue with the bottom-up method
        for (int i = 2; i <= n; i++) {
            // dp[i] = max(dp[j-1]*1, dp[j-2]*2, ... dp[1]*1)
            for (int j = 1; j < i; j++) 
                dp[i] = max(dp[i], dp[i-j]*j);
        }
        
        return dp[n];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // DP Method: 
        //           To reach a certain tile, we just need to know how many ways it takes to the tile to                        the left and above it, and add these two numbers.
        // Runtime: O(MN)
        // Space: O(MN)
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
        
        // Math Method:
        //            To reach the end, we need to move M times down and N times right.
        //            We need to make a total number of M+N moves, we need to choose M of these to be down.
        //            So, total ways = M+N-2 choose M-1 (since robot starts in top left)
        
        // I'm not sure how to code this efficiently.
    }
};

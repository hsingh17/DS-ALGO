class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j) {
        if (i == grid.size() || j == grid[0].size() || j < 0 || i < 0) return;
        
        // Reached the end        
        if (i == grid.size()-1 && j == grid[0].size()-1) 
            grid[i][j]++;
        
        if (grid[i][j] == 1) return;
        
        
        
        helper(grid, i+1, j); // DOWN
        helper(grid, i, j+1); // RIGHT
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Method 1: DFS 
        if (obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]) return 0;
        helper(obstacleGrid, 0, 0);
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
        
        // Method 2: DP
        //          Pretty much the same as Unique Paths 1

//         int M = obstacleGrid.size(), N = obstacleGrid[0].size();
//         vector<vector<int>> dp(M, vector<int>(N, 0));
        
//         // Init 0th col as 1s (stop if there is obstacle in the way)
//         for (int i = 0; i < M; i++) {
//             if (obstacleGrid[i][0]) break;
//             dp[i][0] = 1;
//         }
        
//         // Init 0th row as 1s (stop if there is obstacle in the way)
//         for (int i = 0; i < N; i++) {
//             if (obstacleGrid[0][i]) break;
//             dp[0][i] = 1;
//         }

//         for (int i = 1; i < M; i++) {
//             for (int j = 1; j < N; j++) {
//                 if (obstacleGrid[i][j]) continue;
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }
        
//         return dp[M-1][N-1];
    }
};

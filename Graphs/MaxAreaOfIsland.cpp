class Solution {
public:
    const vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // UP RIGHT DOWN LEFT
    
    int dfs(vector<vector<int>>& grid, int i, int j, const int& M, const int& N) {
        // Boundary conditions
        if (i < 0 || i >= M || 
            j < 0 || j >= N || 
            grid[i][j] == -1 || grid[i][j] == 0) 
            return 0;
        
        // Mark current area as processed
        grid[i][j] = -1;
        
        int island_size = 1;
        for (auto& dir : dirs) 
            island_size += dfs(grid, i+dir[0], j+dir[1], M, N);
        
        return island_size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Method:
        //        This is the same as Number of Islands problem except this time instead of wanting to know                     how many islands there are, we want to know the size of each island.
        //        This is easy to do since when we reach a land area where we can no longer traverse, we just                   return 1 + the area returned from the recursive components.
        // Runtime: O(MN) where M is height of grid and N is width of grid
        // Space : O(1)
        if (grid.empty()) return 0;
        
        int ret = 0, M = grid.size(), N = grid[0].size();
        // Step 1
        for (int i= 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // Step 2
                if (grid[i][j] == 1) {
                    ret = max(ret, dfs(grid, i, j, M, N));
                }
            }
        }
        
        return ret;
    }
};

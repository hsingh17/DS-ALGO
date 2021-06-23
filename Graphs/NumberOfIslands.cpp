class Solution {
public:
    const vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // UP RIGHT DOWN LEFT
    
    void dfs(vector<vector<char>>& grid, int i, int j, const int& M, const int& N) {
        // Boundary conditions
        if (i < 0 || i >= M || 
            j < 0 || j >= N || 
            grid[i][j] == '@' || grid[i][j] == '0') 
            return;
        
        // Step 3
        grid[i][j] = '@';
        
        // Step 2
        for (auto& dir : dirs) 
            dfs(grid, i+dir[0], j+dir[1], M, N);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Method:
        //        Step 1: Iterate through every space on the grid 
        //        Step 2: When a '1' is found, do dfs to find the rest of the island
        //              Step 2a: For every '1' in the grid, mark it with '@' to indicate it being already                                      discovered.
        //        Step 3: After completely processing that island, increase the cnt of islands
        //        Step 4: Repeat step 1-3 for every non-processed island on the grid
        // Runtime: O(MN) where M is height of grid and N is width of grid. Since we need to iterate through                     every space on the grid 
        // Space: O(1) 
        if (grid.empty()) return 0;
        
        int cnt = 0, M = grid.size(), N = grid[0].size();
        // Step 1
        for (int i= 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // Step 2
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, M, N);
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};

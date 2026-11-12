class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        // Base case: stop if out of bounds or on water ('0')
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }

        // Sink the current land cell to mark it as visited
        grid[r][c] = '0';

        // Explore all 4 adjacent directions (down, up, right, left)
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
         if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                // Found a new island
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    result = max(result, dfs(grid, i, j));;
                } 
            }
        }
        return result;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j]) {
            return 0;
        }
        grid[i][j] = 0;
        return dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1) + 1;
    }
};

// Time: O(mn)
// Space: O(mn)
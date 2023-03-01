class Solution {
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    count += dfs(grid1, grid2, i, j);
                }
            }
        }
        return count;
    }
private:
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || !grid2[i][j]) {
            return 1;
        }
        grid2[i][j] = 0;
        int is_island = 1;
        for (auto& dir : dirs) {
            is_island &= dfs(grid1, grid2, i + dir[0], j + dir[1]);
        }
        return is_island & grid1[i][j];
    }
};

// Time: O(m * n)
// Space: O(1)

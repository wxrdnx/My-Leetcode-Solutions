class Solution {
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0, minute = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({i, j});
                    minute = -1;
                }
            }
        }
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (auto& dir : dirs) {
                    int ni = i + dir[0], nj = j + dir[1];
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        fresh--;
                    }
                }
            }
            minute++;
        }
        return fresh == 0 ? minute : -1;
    }
};

// Time: O(m * n)
// Space: O(m * n)

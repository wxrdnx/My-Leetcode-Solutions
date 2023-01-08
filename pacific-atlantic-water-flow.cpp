class Solution {
    constexpr static int pacific = 1, atlantic = 1 << 1;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        vector<vector<int>> visited(heights.size(), vector<int>(heights[0].size()));
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, visited, i, 0, pacific, -1);
            dfs(heights, visited, i, heights[0].size() - 1, atlantic, -1);
        }
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, visited, 0, j, pacific, -1);
            dfs(heights, visited, heights.size() - 1, j, atlantic, -1);
        }
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (visited[i][j] == (pacific | atlantic)) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j, int ocean, int height) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || visited[i][j] & ocean || heights[i][j] < height) {
            return;
        }
        visited[i][j] |= ocean;
        dfs(heights, visited, i + 1, j, ocean, heights[i][j]);
        dfs(heights, visited, i - 1, j, ocean, heights[i][j]);
        dfs(heights, visited, i, j + 1, ocean, heights[i][j]);
        dfs(heights, visited, i, j - 1, ocean, heights[i][j]);    
    }
};

// Time: O(m * n)
// Space: O(m * n)

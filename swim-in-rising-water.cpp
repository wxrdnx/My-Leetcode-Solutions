class Solution {
    using Tuple = tuple<int, int, int>;
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;
        int result = grid[0][0];
        while (!pq.empty()) {
            int i = get<1>(pq.top()), j = get<2>(pq.top());
            result = max(result, get<0>(pq.top()));
            if (i == grid.size() - 1 && j == grid.size() - 1) {
                return result;
            }
            pq.pop();
            for (auto& dir : dirs) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid.size() && grid[ni][nj] != -1) {
                    pq.push({grid[ni][nj], ni, nj});
                    grid[ni][nj] = -1;
                }
            }
        }
        return -1;
    }
};

// Time: O((V + E) * log(V))
// Space: O(V)

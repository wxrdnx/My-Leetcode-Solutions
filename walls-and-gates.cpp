class Solution {
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for (auto& dir : dirs) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && ni < rooms.size() && nj >= 0 && nj < rooms[0].size() && rooms[i][j] < rooms[ni][nj]) {
                    rooms[ni][nj] = rooms[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};
